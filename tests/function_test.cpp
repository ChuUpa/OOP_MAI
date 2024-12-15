#include <iostream>
#include <cassert>
#include "DungeonEditor.h"
#include "NPC.h"
#include "EventObserver.h"

TEST(BattleArenaTests, CheckNPCName) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);

    const auto& characters = battleField.GetAllNPCsCopy();
    ASSERT_FALSE(characters.empty());
    EXPECT_EQ(characters[0]->getNpcName(), "OrkTest");
}

TEST(BattleArenaTests, SpawnIncreasesNPCCount) {
    Arena battleField(500, 500);

    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);
    battleField.SpawnNPC("Druid", "DruidTest", 200, 200);

    const auto& characters = battleField.GetAllNPCsCopy();
    EXPECT_EQ(characters.size(), 2);
}

TEST(BattleArenaTests, VerifyNPCPosition) {
    Arena battleField(500, 500);

    battleField.SpawnNPC("Ork", "OrkTest", 150, 250);
    const auto& characters = battleField.GetAllNPCsCopy();

    ASSERT_FALSE(characters.empty());
    std::pair<int, int> position = characters[0].get()->getCoordinates();
    int posX = position.first;
    int posY = position.second;
    EXPECT_EQ(posX, 150);
    EXPECT_EQ(posY, 250);
}

TEST(BattleArenaTests, SpawnOutOfBounds) {
    Arena battleField(500, 500);

    EXPECT_THROW(battleField.SpawnNPC("Ork", "OutOfBoundsTest", 600, 600), std::out_of_range);
}

TEST(BattleArenaTests, RemoveNPC) {
    Arena battleField(500, 500);

    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);
    battleField.SpawnNPC("Druid", "DruidTest", 200, 200);

    const auto& characters = battleField.GetAllNPCsCopy();
    ASSERT_EQ(characters.size(), 2);

    battleField.RemoveNPC("OrkTest");
    const auto& updatedCharacters = battleField.GetAllNPCsCopy(); 
    EXPECT_EQ(updatedCharacters.size(), 1);
    EXPECT_EQ(updatedCharacters[0]->getNpcName(), "DruidTest");
}

TEST(BattleArenaTests, RemoveNPCSingle) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);

    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 1);

    battleField.RemoveNPC("OrkTest");
    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 0);
}

TEST(BattleArenaTests, RemoveNPCMultiple) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);
    battleField.SpawnNPC("Druid", "DruidTest", 200, 200);

    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 2);

    battleField.RemoveNPC("OrkTest");
    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 1);

    std::vector<std::unique_ptr<NPC>> characters = battleField.GetAllNPCsCopy();
    EXPECT_EQ(characters[0]->getNpcName(), "DruidTest");
}

TEST(BattleArenaTests, SpawnDuplicateNPCNames) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "Duplicate", 100, 100);
    EXPECT_THROW(battleField.SpawnNPC("Druid", "Duplicate", 200, 200), std::invalid_argument);
}

TEST(BattleArenaTests, TestConsoleObserver) {
    Arena battleField(10, 10);
    auto observer = std::make_shared<ConsoleObserver>();
    battleField.AddObserver(observer);
    EXPECT_EQ(battleField.getSizeObservers(), 1);
}

TEST(BattleArenaTests, TestFileObserver) {
    Arena battleField(10, 10);
    auto observer = std::make_shared<FileObserver>();
    battleField.AddObserver(observer);
    EXPECT_EQ(battleField.getSizeObservers(), 1);
}

TEST(BattleArenaTests, TestAddNPC) {
    Arena battleField(10, 10);
    auto character = std::make_unique<Ork>("NPC1", 0, 0);
    battleField.AddNPC(std::move(character));
    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 1);
}

TEST(BattleArenaTests, TestCheckForDuplicate) {
    Arena battleField(10, 10);

    auto character1 = std::make_unique<Ork>("NPC1", 0, 0);
    auto character2 = std::make_unique<Ork>("NPC2", 0, 0);

    battleField.AddNPC(std::move(character1));
    EXPECT_FALSE(battleField.CheckForDuplicate("NPC2", 0, 0));
    EXPECT_TRUE(battleField.CheckForDuplicate("NPC2", 1, 1));
}

TEST(BattleArenaTests, StarterBattleWithoutNPCs) {
    Arena battleField(10, 10);
    EXPECT_NO_THROW(battleField.ToStartBattle(5));
}

TEST(BattleArenaTests, StarterBattleWithoutNPCsWrongRange) {
    Arena battleField(10, 10);
    EXPECT_THROW(battleField.ToStartBattle(15), std::out_of_range);
}

TEST(BattleArenaTests, FileSaverTest) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "OrkTest", 100, 100);
    battleField.SpawnNPC("Druid", "DruidTest", 200, 200);
    std::string fileName = "npcs_text.txt";
    EXPECT_NO_THROW(battleField.SaveToFile(fileName));
}

TEST(BattleArenaTests, SpawnerWithRandomCoordinates) {
    Arena battleField(500, 500);
    battleField.SpawnNPC("Ork", "OrkTest");
    battleField.SpawnNPC("Druid", "DruidTest");
    EXPECT_EQ(battleField.GetAllNPCsCopy().size(), 2);
}