#include <iostream>
#include <string>
#include "../include/fixed_block_mem_resource.hpp"
#include <iostream>
#include "twoway_linked_list.hpp"

int main() {
    try {
        FixedBlockMemoryResource memory_resource(1024 * 1024, sizeof(int) * 4);
        PmrDoublyLinkedList<int> list(&memory_resource);
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        std::cout << "Список содержит: " << std::endl;
        for (auto it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        list.clear();
        std::cout << "Лист очищен" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Ошибка аллокации: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
