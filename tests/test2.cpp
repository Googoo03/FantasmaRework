#include "gtest/gtest.h"
#include "../src/Character.cpp"
#include "../src/Bard.cpp"
#include "../src/Fighter.cpp"
#include "../src/Tank.cpp"
#include "../src/Mage.cpp"
#include "../src/Item.cpp"

#include <string>
#include <sstream>

using namespace std;

TEST(bardClass, normalAttackTest)
{
  Bard bard;
  ostringstream out;

  bard.normalAttack(out);
  double res = bard.getMana();

  EXPECT_EQ(res, 105);
  
}

TEST(bardClass, specialAttackTest)
{
  Bard bard;
  ostringstream out;
  bard.specialAttack(out);
  
  double res = bard.getMana();

  EXPECT_EQ(res, 95); 
}

TEST(BardClass, attackedTest)
{
  ostringstream out;
  Bard bard;
  bard.attacked(30, out);

  double res = bard.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 120);
  EXPECT_EQ(str, "you've been hit!\n");
}

TEST(bardClass, deathTest)
{
  ostringstream out;
  Bard bard;
  bard.attacked(150, out);

  double res = bard.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 0);
  EXPECT_EQ(str, "your character has died! game over....\n");
}

TEST(bardClass, inventoryFullTest)
{
  Bard bard;
  bool res = bard.isInventoryFull();
  EXPECT_EQ(res, false);
}

TEST(BardClass, inventoryCountTest)
{
  Bard bard;

  Item *p = new Item(5,5,5,5,5,5,"banjo");

  bard.addItem(p);

  int res = bard.getInventorySize();
  EXPECT_EQ(res, 1);
}

//fighter class tests
TEST(fighterClass, normalAttackTest)
{
  Fighter fighter;
  ostringstream out;

  double res = fighter.normalAttack(out);
  double res2 = fighter.getMana();
  string str = out.str();

  EXPECT_EQ(res, 50);
  EXPECT_EQ(res2, 70);
  EXPECT_EQ(str, "you have hit the enemy!\n");
  
}

TEST(fighterClass, specialAttackTest)
{
  Fighter fighter;
  ostringstream out;
  
  
  double res = fighter.specialAttack(out);
  double res2 = fighter.getMana();
  string str = out.str();

  EXPECT_EQ(res, 60); 
  EXPECT_EQ(res2, 65);
  EXPECT_EQ(str, "you hit the enmy with your special move!\n");
}


TEST(fighterClass, attackedTest)
{
  ostringstream out;
  Fighter fighter;
  fighter.attacked(30, out);

  double res = fighter.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 150);
  EXPECT_EQ(str, "you've been hit!\n");
}

TEST(fighterClass, deathTest)
{
  ostringstream out;
  Fighter fighter;
  fighter.attacked(180, out);

  double res = fighter.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 0);
  EXPECT_EQ(str, "your character has died! game over....\n");
}

TEST(fighterClass, inventoryFullTest)
{
  Fighter fighter;
  bool res = fighter.isInventoryFull();
  EXPECT_EQ(res, false);
}

TEST(fighterClass, inventoryCountTest)
{
  Fighter fighter;

  Item *p = new Item(5,5,5,5,5,5,"sword");

  fighter.addItem(p);

  int res = fighter.getInventorySize();
  EXPECT_EQ(res, 1);
}

//Mage class tests
TEST(mageClass, normalAttackTest)
{
  Mage mage;
  ostringstream out;

  double res = mage.normalAttack(out);
  double res2 = mage.getMana();
  string str = out.str();

  EXPECT_EQ(res, 45);
  EXPECT_EQ(res2, 140);
  EXPECT_EQ(str, "you have hit the enemy!\n");
  
}


TEST(mageClass, specialAttackTest)
{
  Mage mage;
  ostringstream out;
  
  
  double res = mage.specialAttack(out);
  double res2 = mage.getMana();
  string str = out.str();

  EXPECT_EQ(res, 55); 
  EXPECT_EQ(res2, 130);
  EXPECT_EQ(str, "you hit the enemy with your special move!\n");
}


TEST(mageClass, attackedTest)
{
  ostringstream out;
  Mage mage;
  mage.attacked(30, out);

  double res = mage.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 70);
  EXPECT_EQ(str, "you've been hit!\n");
}

TEST(mageClass, deathTest)
{
  ostringstream out;
  Mage mage;
  mage.attacked(100, out);

  double res = mage.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 0);
  EXPECT_EQ(str, "your character has died! game over....\n");
}

TEST(mageClass, inventoryFullTest)
{
  Mage mage;
  bool res = mage.isInventoryFull();
  EXPECT_EQ(res, false);
}

TEST(mageClass, inventoryCountTest)
{
  Mage mage;

  Item *p = new Item(5,5,5,5,5,5, "staff");

  mage.addItem(p);

  int res = mage.getInventorySize();
  EXPECT_EQ(res, 1);
}
//Tank tets

TEST(tankClass, normalAttackTest)
{
  Tank tank;
  ostringstream out;

  double res = tank.normalAttack(out);
  double res2 = tank.getMana();
  string str = out.str();

  EXPECT_EQ(res, 30);
  EXPECT_EQ(res2, 55 );
  EXPECT_EQ(str, "you have hit the enemy!\n");
  
}


TEST(tankClass, specialAttackTest)
{
  Tank tank;
  ostringstream out;
  
  
  double res = tank.specialAttack(out);
  double res2 = tank.getMana();
  string str = out.str();

  EXPECT_EQ(res, 40); 
  EXPECT_EQ(res2, 50);
  EXPECT_EQ(str, "you Just steamrolled the enemy with your special move!\n");
}


TEST(tankClass, attackedTest)
{
  ostringstream out;
  Tank tank;
  tank.attacked(30, out);

  double res = tank.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 170);
  EXPECT_EQ(str, "you've been hit!\n");
}


TEST(tankClass, deathTest)
{
  ostringstream out;
  Tank tank;
  tank.attacked(200, out);

  double res = tank.getHealth();
  string str = out.str();


  EXPECT_EQ(res, 0);
  EXPECT_EQ(str, "your character has died! game over....\n");
}

TEST(tankClass, inventoryFullTest)
{
  Tank tank;
  bool res = tank.isInventoryFull();
  EXPECT_EQ(res, false);
}

TEST(tankClass, inventoryCountTest)
{
  Tank tank;

  Item *p = new Item(5,5,5,5,5,5,"kunckles");

  tank.addItem(p);

  int res = tank.getInventorySize();
  EXPECT_EQ(res, 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}