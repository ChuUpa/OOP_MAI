#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H

#include <vector>
#include <memory>
#include <string>
#include <map>
#include <functional>
#include <cmath>
#include "NPC.h"
#include "EventObserver.h"

class DungeonEditor {
public:
    DungeonEditor();
    ~DungeonEditor() = default;

    void addNPC();
    void printNPCs() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void startCombat();

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<EventObserver>> observers;

    using NPCFactory = std::function<std::shared_ptr<NPC>(const std::string&, int, int)>;
    std::map<std::string, NPCFactory> npcFactories;

    void initializeFactories();
    void notifyObservers(const std::string& event);
};

DungeonEditor::DungeonEditor() {
    initializeFactories();
}

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

    npcs.push_back(factoryIt->second(name, x, y));
    notifyObservers("Added NPC: " + type + " (" + name + ") at (" + std::to_string(x) + ", " + std::to_string(y) + ")");
}

void DungeonEditor::notifyObservers(const std::string& event) {
    for (const auto& observer : observers) {
        observer->onEvent(event);
    }
}

void DungeonEditor::startCombat() {
    if (npcs.size() < 2) {
        std::cout << "Not enough NPCs for combat." << std::endl;
        return;
    }

    double range;
    std::cout << "Enter combat range: ";
    std::cin >> range;

    class CombatVisitor : public NPCVisitor {
    public:
        CombatVisitor(double range, std::vector<std::shared_ptr<NPC>>& npcs, DungeonEditor& editor)
            : range(range), npcs(npcs), editor(editor) {}

        void visit(Bear& bear) override {
            for (auto it = npcs.begin(); it != npcs.end();) {
                if (auto target = std::dynamic_pointer_cast<NPC>(*it)) {
                    if (target->getType() != "Bear" && inRange(bear, *target)) {
                        editor.notifyObservers(bear.getName() + " kills " + target->getName());
                        it = npcs.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

        void visit(Bittern& bittern) override {
            // Bittern does nothing
        }

        void visit(Desman& desman) override {
            for (auto it = npcs.begin(); it != npcs.end();) {
                if (auto target = std::dynamic_pointer_cast<NPC>(*it)) {
                    if (target->getType() == "Bear" && inRange(desman, *target)) {
                        editor.notifyObservers(desman.getName() + " kills " + target->getName());
                        it = npcs.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

    private:
        double range;
        std::vector<std::shared_ptr<NPC>>& npcs;
        DungeonEditor& editor;

        bool inRange(const NPC& a, const NPC& b) {
            double distance = std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2));
            return distance <= range;
        }
    };

    CombatVisitor visitor(range, npcs, *this);

    for (auto& npc : npcs) {
        npc->accept(visitor);
    }

    std::cout << "Combat completed." << std::endl;
}

#endif
