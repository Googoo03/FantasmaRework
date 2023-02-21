#ifndef DUNGEON_H
#define DUNGEON_H

#include "../header/Location.h"
#include <vector>
#include "../header/Item.hpp"
#include "../header/NameGenerator.h"

class Dungeon : public Location {


    public:
        Dungeon(int x, int y, int seed);
        void CreateLocation(NameGenerator*);
        string getName(){return Location::name;}
        int getXPos(){return Location::xPos;}
        int getYPos(){return Location::yPos;}
        
    private:
        


};

#endif 