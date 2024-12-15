#include "DungeonEditor.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Конструктор
DungeonEditor::DungeonEditor() {
    initializeFactories(); // Инициализация фабрик для NPC
}

// Инициализация фабрик
void DungeonEditor::initializeFactories() {
    npcFactories["Bear"] = [](const std::string& name, int x, int y) {
        return std::make_shared<Bear>(name, x, y);
    };
    npcFactories["Bittern"] = [](const std::string& name, int x, int y) {
        return std::make_shared<Bittern>(name, x, y);
    };
    npcFactories["Desman"] = [](const std::string& name, int x, int y) {
        return std::make_shared<Desman>(name, x, y);
    };
}

// Добавление NPC
void DungeonEditor::addNPC() {
    std::string type, name;
    int x, y;

    std::cout << "Enter NPC type (Bear, Bittern, Desman): ";
    std::cin >> type;

    auto factoryIt = npcFactories.find(type);
    if (factoryIt == npcFactories.end()) {
        std::cout << "Unknown NPC type!" << std::endl;
        return;
    }

    std::cout << "Enter NPC name: ";
    std::cin >> name;
    std::cout << "Enter coordinates (x y): ";
    std::cin >> x >> y;

    if (x < 0 || x > 500 || y < 0 || y > 500) {
        std::cout << "Coordinates out of bounds!" << std::endl;
        return;
    }

    npcs.push_back(factoryIt->second(name, x, y)); // Создаем NPC через фабрику и добавляем в список
    notifyObservers("Added NPC: " + type + " (" + name + ") at (" + std::to_string(x) + ", " + std::to_string(y) + ")");
}

// Уведомление наблюдателей
void DungeonEditor::notifyObservers(const std::string& event) {
    for (const auto& observer : observers) {
        observer->onEvent(event);
    }
}

// Печать списка NPC
void DungeonEditor::printNPCs() const {
    if (npcs.empty()) {
        std::cout << "No NPCs in the dungeon." << std::endl;
        return;
    }

    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() 
                  << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

// Сохранение NPC в файл
void DungeonEditor::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (const auto& npc : npcs) {
        outFile << npc->getType() << " " << npc->getName() 
                << " " << npc->getX() << " " << npc->getY() << std::endl;
    }
    outFile.close();
    std::cout << "NPCs saved to " << filename << std::endl;
}

// Загрузка NPC из файла
void DungeonEditor::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return;
    }

    npcs.clear(); // Очистка текущего списка NPC
    std::string type, name;
    int x, y;

    while (inFile >> type >> name >> x >> y) {
        auto factoryIt = npcFactories.find(type);
        if (factoryIt != npcFactories.end()) {
            npcs.push_back(factoryIt->second(name, x, y));
        }
    }
    inFile.close();
    std::cout << "NPCs loaded from " << filename << std::endl;
}
