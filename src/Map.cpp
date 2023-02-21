#include "../header/Map.h"
#include "../header/PerlinNoise.h"
#include "../header/Dungeon.h"
#include "../header/NameGenerator.h"

Map::~Map(){

    for(int i = TownList.size()-1; i >= 0; --i){
        delete TownList.at(i);
    }
    for(int i = DungeonList.size()-1; i >= 0; --i){
        delete DungeonList.at(i);
    }
}

void Map::createMap(PerlinNoise*& myPerlin){
    //double center = size/2;
    srand(time(0));
    int seed = rand();

    int MountainSeed = rand();

    for(int i = 0; i < size; ++i){

        for(int j = 0; j < size; ++j){
            double perlinValue = myPerlin->OctavePerlin((i+seed)*(1.0/size),(j+seed)*(1.0/size), 3, 0.5, 1);
            double mountainValue = myPerlin->OctavePerlin((i+MountainSeed)*(1.0/size),(j+MountainSeed)*(1.0/size), 1, 0.5, 5);
            perlinValue += 2.0 / sqrt(pow(abs(center-i),2) + pow(abs(center-j),2) );
            mountainValue += 2.0 / sqrt(pow(abs(center-i),2) + pow(abs(center-j),2) );
            if(mountainValue > 0.4 && perlinValue > 0.05){
                
                mapData[(i*size) + j] = '-';
            }else if(perlinValue > 0.05){
                
                if(int(perlinValue * 1000) % 127 == 0){
                    mapData[(i*size) + j] = 'T';
                    TownList.push_back(new Town(i, j, seed)); 
                    //this is where we'll add T to the town list
                }else if(int(perlinValue * 1000) % 255 == 0){
                    mapData[(i*size) + j] = 'D';
                    DungeonList.push_back(new Dungeon(i,j,seed));
                    //this is where we'll add D to the dungeon list
                }else if(perlinValue - 0.015 < 0.05){
                    mapData[(i*size) + j] = '.';
                }else{
                    mapData[(i*size) + j] = '\'';
                } 
            }else{
                mapData[(i*size) + j] = ' ';
            }
        }
        
    }
}

/*void addTown(int i, int j, int seed){
    Town *newTown = new Town(i, j, seed);
    Town->CreateLocation();
    TownList.push_back(); 
}*/

void Map::marchingSquares(){
    for(int i = 0; i < size; ++i){

        for(int j = 0; j < size; ++j){
            int topAdjacent = ((i+1)*size) + j;
            int bottomAdjacent = ((i-1)*size) + j;
            int leftAdjacent = ((i)*size) + j-1;
            int rightAdjacent = ((i)*size) + j+1;

            if(i == center-3 && j==center) {
                mapData[(i*size) + j] = 'B';
                continue;
            }
            if(mapData[leftAdjacent] == '\'' && mapData[rightAdjacent] == '-') {
                mapData[(i*size) + j] = '/';
                continue;
            }
            if(mapData[leftAdjacent] == '-' && mapData[rightAdjacent] == '\'') {
                mapData[(i*size) + j] = 0x5c;
                continue;
            }
            
        }
    }
}

void Map::movementValidation(char input){
    int topAdjacent = ((playerY-1)*size) + playerX;
    int bottomAdjacent = ((playerY+1)*size) + playerX;
    int leftAdjacent = ((playerY)*size) + playerX-1;
    int rightAdjacent = ((playerY)*size) + playerX+1;

                
    if(input == 'w'){
        playerY -= 1*(mapData[topAdjacent] != ' ');
    }else if(input == 'a'){
        playerX -= 1*(mapData[leftAdjacent] != ' ');
    }else if(input == 's'){
        playerY += 1*(mapData[bottomAdjacent] != ' ');
    }else if (input == 'd'){
        playerX += 1*(mapData[rightAdjacent] != ' ');
    }

    EnteredTown = false;
    for(int i = 0; i < TownList.size(); ++i){
        if(TownList.at(i)->getXPos() == playerY && TownList.at(i)->getYPos() == playerX){
            EnteredTown = true;
            TownIndex = i;
            break;
        }
    }
    EnteredDungeon = false;
    for(int i = 0; i < DungeonList.size(); ++i){
        if(DungeonList.at(i)->getXPos() == playerY && DungeonList.at(i)->getYPos() == playerX){
            EnteredDungeon = true;
            DungeonIndex = i;
            break;
        }
    }
    EnteredBoss = (playerY == center-3 && playerX==center);
    ////NICK's JOB
}


void Map::drawMap(){

    for(int i = 0; i < size; ++i){

        for(int j = 0; j < size; ++j){
            
                if(i == playerY && j == playerX) {
                    cout << '#';
                }else{
                    cout << mapData[(i*size) + j];
                }

        }
        cout << endl;
    }

    

}

void Map::townEvent(NameGenerator*& nameClass){
    cout << "You have entered the Town \'" << returnTownName(TownList.at(TownIndex) ) << "\' \n\n" << endl;
    if(TownList.at(TownIndex)->IsShopEmpty()){
        TownList.at(TownIndex)->CreateLocation(nameClass);
    }
    TownList.at(TownIndex)->totalList();
}

void Map::dungeonEvent(){
    cout << "You have entered the Dungeon \'" << returnDungeonName(DungeonList.at(DungeonIndex) ) << "\' \n\n" << endl;
}

string Map::returnTownName(Town*& town){

    return town->getName();
}

string Map::returnDungeonName(Dungeon*& dungeon){

    return dungeon->getName();
}