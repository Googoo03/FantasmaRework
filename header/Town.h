#ifndef TOWN_H
#define TOWN_H

#include "../header/Location.h"
#include <vector>
#include "../header/Item.hpp"
#include "../header/NameGenerator.h"

class Town : public Location {


    public:
        Town(int x, int y, int seed);
        ~Town();
        void CreateLocation(NameGenerator*&);
        string getName(){return Location::name;}
        int getXPos(){return Location::xPos;}
        int getYPos(){return Location::yPos;}
        bool IsShopEmpty(){return (shopItems.size() == 0);}
        int getShopSize(){return shopItems.size();}
        void removeShopItem(int index){shopItems.erase(shopItems.begin()+index);}
        Item* getItem(int index){return shopItems.at(index);}

        void totalList();
    private:
        vector<Item*> shopItems;


};

#endif 