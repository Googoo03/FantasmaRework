#include "gtest/gtest.h"
#include "../src/Item.cpp"
#include "../src/fighterItem.cpp"
#include "../src/bardItem.cpp"
#include "../src/mageItem.cpp"
#include "../src/tankItem.cpp"
#include "../src/Bandit.cpp"
#include "../src/Boss.cpp"

TEST(ItemTests, itemConstructor) 
{
    Item *constructorTester = new Item(1, 5, 3, 1, 1, 1, "basic sword");
    EXPECT_EQ(constructorTester->getItemID(), 1);
    EXPECT_EQ(constructorTester->getDamageRating(), 5);
    EXPECT_EQ(constructorTester->getDefenseRating(), 3);
    EXPECT_EQ(constructorTester->getHealthRegen(), 1);
    EXPECT_EQ(constructorTester->getManaRegen(), 1);
    EXPECT_EQ(constructorTester->getRange(), 1);
    EXPECT_EQ(constructorTester->getItemName(), "basic sword");
    delete constructorTester;
}

TEST(ItemTests, fighterItemConstructor)
{
    fighterItem *fighterConstructorTester = new fighterItem(2, 7, 3, 2, 1, 1, "broad sword", 3, 4);
    EXPECT_EQ(fighterConstructorTester->getItemID(), 2);
    EXPECT_EQ(fighterConstructorTester->getDamageRating(), 10); 
    EXPECT_EQ(fighterConstructorTester->getDefenseRating(), 3);
    EXPECT_EQ(fighterConstructorTester->getHealthRegen(), 5);
    EXPECT_EQ(fighterConstructorTester->getManaRegen(), 1);
    EXPECT_EQ(fighterConstructorTester->getRange(), 1);
    EXPECT_EQ(fighterConstructorTester->getItemName(), "broad sword");
    EXPECT_EQ(fighterConstructorTester->getRage(), 3);
    EXPECT_EQ(fighterConstructorTester->getDexterity(), 4);
    delete fighterConstructorTester;
}

TEST(ItemTests, bardItemConstructor)
{
    bardItem *bardConstructorTester = new bardItem(3, 1, 5, 5, 5, 5, "banjo", 5, 5);
    EXPECT_EQ(bardConstructorTester->getItemID(), 3);
    EXPECT_EQ(bardConstructorTester->getDamageRating(), 6);
    EXPECT_EQ(bardConstructorTester->getDefenseRating(), 5);
    EXPECT_EQ(bardConstructorTester->getHealthRegen(), 10);
    EXPECT_EQ(bardConstructorTester->getManaRegen(), 5);
    EXPECT_EQ(bardConstructorTester->getRange(), 5);
    EXPECT_EQ(bardConstructorTester->getItemName(), "banjo");
    EXPECT_EQ(bardConstructorTester->getJamScale(), 5);
    EXPECT_EQ(bardConstructorTester->getMeditation(), 5);
    delete bardConstructorTester;
}

TEST(ItemTests, mageItemConstructor)
{
    mageItem *mageConstructorTester = new mageItem(4, 3, 1, 3, 3, 7, "wand", 3, 5);
    EXPECT_EQ(mageConstructorTester->getItemID(), 4);
    EXPECT_EQ(mageConstructorTester->getDamageRating(), 6);
    EXPECT_EQ(mageConstructorTester->getDefenseRating(), 1);
    EXPECT_EQ(mageConstructorTester->getHealthRegen(), 8);
    EXPECT_EQ(mageConstructorTester->getManaRegen(), 3);
    EXPECT_EQ(mageConstructorTester->getRange(), 7);
    EXPECT_EQ(mageConstructorTester->getItemName(), "wand");
    EXPECT_EQ(mageConstructorTester->getMagicDamage(), 3);
    EXPECT_EQ(mageConstructorTester->getSelfHeal(), 5);
    delete mageConstructorTester;
}

TEST(ItemTests, tankItemConstructor)
{
    tankItem *tankConstructorTester = new tankItem(5, 3, 7, 5, 1, 1, "big ol' fists", 3, true);
    EXPECT_EQ(tankConstructorTester->getItemID(), 5);
    EXPECT_EQ(tankConstructorTester->getDamageRating(), 3);
    EXPECT_EQ(tankConstructorTester->getDefenseRating(), 10);
    EXPECT_EQ(tankConstructorTester->getHealthRegen(), 8);
    EXPECT_EQ(tankConstructorTester->getManaRegen(), 1);
    EXPECT_EQ(tankConstructorTester->getRange(), 1);
    EXPECT_EQ(tankConstructorTester->getItemName(), "big ol' fists");
    EXPECT_EQ(tankConstructorTester->getArmor(), 3);
    EXPECT_EQ(tankConstructorTester->areTheyStunned(), true);
    delete tankConstructorTester;
}

TEST(BanditTests, banditTesting) 
{
    Bandit *banditTester = new Bandit(60.0, 10.0);
    banditTester->dealDamage(10.0);
    EXPECT_EQ(banditTester->getDamageDone(), 10.0);
    EXPECT_EQ(banditTester->getBanditHealth(), 50.0);
    delete banditTester;

}

TEST(BossTests, bossTesting)
{
    Boss *bossTester = new Boss(300.0, 20.0, "Nardwar", 5.0);
    bossTester->dealDamage(10.0);
    bossTester->selfHeal();
    EXPECT_EQ(bossTester->getBanditHealth(), 295.0);
    EXPECT_EQ(bossTester->getBossName(), "Nardwar");
    delete bossTester;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}