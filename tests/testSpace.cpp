#include "../header/PerlinNoise.h"
#include "../header/Town.h"
#include "../header/Map.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

TEST(PerlinTests, PerlinNoiseValue)
{
  PerlinNoise *perlin = new PerlinNoise();
  EXPECT_NO_THROW(perlin->perlinNoise(5,'a'));
  EXPECT_NO_THROW(perlin->perlinNoise(-5,0));

  delete perlin;
}
TEST(PerlinTests, OctavePerlinNoiseValue)
{
  PerlinNoise *perlin = new PerlinNoise();
  EXPECT_NO_THROW(perlin->OctavePerlin(5,'a',3,0.5,1));
  EXPECT_NO_THROW(perlin->OctavePerlin(0,0,3,0.5,1));
  delete perlin;
}

TEST(TownTests, shopItemRemoval)
{
    Town *town = new Town(1,1,12345);
    NameGenerator *names = new NameGenerator();
    EXPECT_NE(town->getName(), "");

    town->CreateLocation(names);
    EXPECT_EQ(town->getShopSize(), 5); //Make sure shop has correct amount of items
    ASSERT_LT(town->getItem(0)->getDamageRating(), 256); //Make sure each item stays within its bounds
    ASSERT_LT(town->getItem(0)->getHealthRegen(), 20);
    ASSERT_LT(town->getItem(0)->getManaRegen(), 25);

    town->removeShopItem(0);
    EXPECT_EQ(town->getShopSize(), 4);
    town->removeShopItem(0);
    town->removeShopItem(0);
    town->removeShopItem(0);
    town->removeShopItem(0);
    EXPECT_EXIT(town->removeShopItem(0), testing::KilledBySignal(SIGKILL),"Sending myself unblockable signal");
    delete town;
    delete names;

}
TEST(InventoryTests, nameVerification)
{
    Town *town = new Town(1,1,12345);
    EXPECT_NE(town->getName(), "");
    delete town;

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}