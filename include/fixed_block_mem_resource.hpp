#include <memory_resource>
#include <list>
#include <vector>
#include <cassert>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
private:
    void* memory_pool;
    size_t pool_size;
    size_t block_size;
    std::list<void*> free_blocks;

public:
    explicit FixedBlockMemoryResource(size_t total_memory, size_t block_size)
        : memory_pool(std::malloc(total_memory)), pool_size(total_memory), block_size(block_size) {
        assert(memory_pool && "Ошибка аллокации мем пула");
        for (size_t offset = 0; offset + block_size <= pool_size; offset += block_size) {
            free_blocks.push_back(static_cast<char*>(memory_pool) + offset);
        }
    }

    ~FixedBlockMemoryResource() override {
        std::free(memory_pool);
    }

protected:
    void* do_allocate(size_t bytes, size_t alignment) override {
        if (bytes > block_size || free_blocks.empty()) {
            throw std::bad_alloc();
        }
        void* block = free_blocks.front();
        free_blocks.pop_front();
        return block;
    }

    void do_deallocate(void* p, size_t bytes, size_t alignment) override {
        free_blocks.push_back(p);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
