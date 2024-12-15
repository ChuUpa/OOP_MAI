#include <iostream>
#include "include/DungeonEditor.h"

int main() {
    try {
        DungeonEditor editor;

        int choice;
        do {
            std::cout << "\n--- Dungeon Editor Menu ---\n";
            std::cout << "1. Add NPC\n";
            std::cout << "2. Print NPC list\n";
            std::cout << "3. Save NPCs to file\n";
            std::cout << "4. Load NPCs from file\n";
            std::cout << "5. Start combat mode\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    editor.addNPC();
                    break;
                case 2:
                    editor.printNPCs();
                    break;
                case 3:
                    editor.saveToFile("npc_data.txt");
                    break;
                case 4:
                    editor.loadFromFile("npc_data.txt");
                    break;
                case 5:
                    editor.startCombat();
                    break;
                case 0:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
