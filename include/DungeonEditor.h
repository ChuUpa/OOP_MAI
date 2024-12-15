#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H

#include <vector>
#include <memory>
#include <string>
#include <map>
#include <functional>
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

#endif
