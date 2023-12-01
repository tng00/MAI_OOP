#include "../googletest/googletest/include/gtest/gtest.h"
#include "../include/factory.hpp"
#include "../include/knight.hpp"
#include "../include/merchant.hpp"
#include "../include/observer.hpp"
#include "../include/squirrel.hpp"
#include "bits/stdc++.h"

//_________________________________________________________________________________________________________________________
TEST(NPCFactoryTest, CreateNPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
        std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
        std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.createNPC(NPC_type::knight, 1, 2));
        s.insert(factory.createNPC(NPC_type::merchant, 3, 4));
        s.insert(factory.createNPC(NPC_type::squirrel, 5, 6));
        factory.save(s, "test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<Knight>(1, 2);
    std::stringstream expected_output;
    expected_output << "knight_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

//_________________________________________________________________________________________________________________________
TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(merchant->getType(), "Merchant");
    EXPECT_EQ(squirrel->getType(), "Squirrel");

    EXPECT_TRUE(knight->alive());
    EXPECT_TRUE(merchant->alive());
    EXPECT_TRUE(squirrel->alive());

    EXPECT_EQ(knight->getX(), 1);
    EXPECT_EQ(merchant->getX(), 3);
    EXPECT_EQ(squirrel->getX(), 5);
    EXPECT_EQ(knight->getY(), 2);
    EXPECT_EQ(merchant->getY(), 4);
    EXPECT_EQ(squirrel->getY(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 1);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 50, 1);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 100, 1);

    EXPECT_FALSE(knight->near(merchant, 10));
    EXPECT_TRUE(knight->near(merchant, 60));
    EXPECT_FALSE(knight->near(squirrel, 90));
    EXPECT_TRUE(knight->near(squirrel, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 1);
    std::shared_ptr<Observer> console_observer, file_observer;
    console_observer = std::make_shared<ConsoleObserver>();
    file_observer = std::make_shared<FileObserver>();
    bool test = true;
    try {
        knight->attach(console_observer);
        knight->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

//_________________________________________________________________________________________________________________________
TEST(KnightTest, ConstructorAndGetters) {
    Knight knight(1, 2);
    EXPECT_EQ(knight.getX(), 1);
    EXPECT_EQ(knight.getY(), 2);
    EXPECT_TRUE(knight.alive());
    EXPECT_EQ(knight.getType(), "Knight");
}

TEST(KnightTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(knight->accept(knight));
    EXPECT_FALSE(knight->accept(merchant));
    EXPECT_FALSE(knight->accept(squirrel));
    EXPECT_TRUE(knight->alive());
}

//_________________________________________________________________________________________________________________________
TEST(MerchantTest, ConstructorAndGetters) {
    Merchant merchant(1, 2);
    EXPECT_EQ(merchant.getX(), 1);
    EXPECT_EQ(merchant.getY(), 2);
    EXPECT_TRUE(merchant.alive());
    EXPECT_EQ(merchant.getType(), "Merchant");
}

TEST(MerchantTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(merchant->accept(merchant));
    EXPECT_FALSE(merchant->accept(squirrel));
    EXPECT_TRUE(merchant->alive());
    EXPECT_TRUE(merchant->accept(knight));
    EXPECT_FALSE(merchant->alive());
}

//_________________________________________________________________________________________________________________________
TEST(SquirrelTest, ConstructorAndGetters) {
    Squirrel squirrel(1, 2);
    EXPECT_EQ(squirrel.getX(), 1);
    EXPECT_EQ(squirrel.getY(), 2);
    EXPECT_TRUE(squirrel.alive());
    EXPECT_EQ(squirrel.getType(), "Squirrel");
}

TEST(SquirrelTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);
    std::shared_ptr<NPC> squirrel_ = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(squirrel->accept(knight));
    EXPECT_TRUE(squirrel->alive());
    EXPECT_TRUE(squirrel->accept(merchant));
    EXPECT_FALSE(squirrel->alive());
    EXPECT_TRUE(squirrel_->accept(squirrel));
    EXPECT_FALSE(squirrel_->alive());
    remove("battle_stats.txt");
    remove("test.txt");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
