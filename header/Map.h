#ifndef MAP_H
#define MAP_H

#include "../header/PerlinNoise.h"
#include "../header/Town.h"
#include "../header/Dungeon.h"
#include "../header/Location.h"
#include "../header/NameGenerator.h"
#include <cstdlib>

class Map {

    public:
        int center;
        const static int size = 50;
        //const static int length = 20;
        //const static int width = 50;
        char mapData[size*size];

        //inlcude another list for dungeons

        Map():center(size/2), playerX(center),playerY(center){}
        ~Map();
        void createMap(PerlinNoise*&); 

        void drawMap();
        void townEvent(NameGenerator*&);
        void dungeonEvent();

        void marchingSquares();
        void movementValidation(char input);
        bool getEnteredTown(){return EnteredTown;}

        bool getEnteredDungeon(){return EnteredDungeon;}
        bool getEnteredBoss(){return EnteredBoss;}

        string returnTownName(Town*& town);
        string returnDungeonName(Dungeon*& dungeon);
        Town* returnTown(){ return TownList.at(TownIndex);}
    private:
        vector<Town*>  TownList;
        vector<Dungeon*>  DungeonList;
        int playerX,playerY;

        bool EnteredTown;
        bool EnteredDungeon;
        bool EnteredBoss;

        int DungeonIndex;
        int TownIndex;
};

#endif