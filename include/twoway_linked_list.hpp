#include <memory>
#include <iterator>

template <typename T>
class PmrDoublyLinkedList {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(const T& value, Node* prev = nullptr, Node* next = nullptr)
            : value(value), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;
    size_t size;
    std::pmr::polymorphic_allocator<Node> allocator;

public:
    explicit PmrDoublyLinkedList(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
        : head(nullptr), tail(nullptr), size(0), allocator(resource) {}

    ~PmrDoublyLinkedList() {
        clear();
    }

    void push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size;
}

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            allocator.destroy(temp);
            allocator.deallocate(temp, 1);
        }
        tail = nullptr;
        size = 0;
    }

    size_t get_size() const { return size; }

    class Iterator {
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->value;
        }

        T* operator->() {
            return &(current->value);
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};