#include "../header/PerlinNoise.h"
#include "../header/Map.h"
#include "../header/NameGenerator.h"
#include "../header/Character.h"
#include "../header/FightScreen.h"
#include "../header/Fighter.h"
#include "../header/Mage.h"
#include "../header/Tank.h"
#include "../header/Item.hpp"
#include "../header/fighterItem.hpp"
#include "../header/mageItem.hpp"
#include "../header/tankItem.hpp"
#include "../header/bardItem.hpp"

#include <iostream>
#include "../header/Bard.h"



using namespace std;

void buySequence(char input, Map* newMap, Character* player);

void inventorySequence(char input, Character* player);

void drawInventory(Character* player);

char menu();

void characterSelection(char choice, Character*& userChar);

int main(){
    PerlinNoise* myPerlin = new PerlinNoise(); //This needs a destructor!!!

    Map* newMap = new Map();
    NameGenerator* names = new NameGenerator();
    
    newMap->createMap(myPerlin);
    newMap->marchingSquares();
    bool TownEvent = false;
    bool FightEvent = false;
    bool BossEvent = false;
    bool InventoryEvent = false;

    bool winFight = false;

    bool MapEvent = (!TownEvent) && (!FightEvent) && (!BossEvent) && (!InventoryEvent)&& (!winFight);

    
    char input = ' ';
   

    ///////////////MENU CODE HERE////////////////////////////
    //show main menu. Player has option to play or quit. 
    Character* userChar;
    FightScreen fightScreen;
    //If quit, return 0;
    char userChoice = menu();
    characterSelection(userChoice, userChar);

    //CHANGE PLAYER TO USERCHAR
    


    /////////////////////////////////////////////////////////

    ///////////////GAME LOOP ////////////////////////////////
    while(true){
        
        ///////////////////GAME EVENTS //////////////////////////
        if(input != '\n'){
            cout << "\033[2J\033[1;1H"; //clears screen
            TownEvent = newMap->getEnteredTown();
            FightEvent = newMap->getEnteredDungeon();
            BossEvent = newMap->getEnteredBoss();
            MapEvent = (!TownEvent) && (!FightEvent) && (!BossEvent) && (!InventoryEvent);
            

            if(MapEvent){
                newMap->drawMap();
            }else if(TownEvent){
                newMap->townEvent(names);
                cout << "Press number you want to buy or" << endl << "L: Leave Town" << endl;
            }else if(InventoryEvent){

                userChar->displayInventory();
                
                cout << "Press i to leave" << endl;
                inventorySequence(input, userChar);
              
            }else if(FightEvent && winFight){
                //FIGHT EVENT CLASS CODE //ANTHONY

                

            }else if(FightEvent){
                //FIGHT EVENT CLASS CODE //ANTHONY
                newMap->dungeonEvent();
                Bandit* bandit = new Bandit(100,10);
                fightScreen.printFightScreen(cout, userChar, bandit,winFight);
                if(winFight){
                    cout << "-------------------------------" << endl;
                    cout << "YOU HAVE DEFEATED THE BANDIT" << endl;
                    cout << "-------------------------------" << endl;
                    FightEvent = false;
                    winFight = false;
                    newMap->movementValidation('d');
                }
                delete bandit;
                FightEvent = false;
                newMap->movementValidation('d');

            }
            else if(BossEvent){
                //FIGHT EVENT CLASS CODE BUT WITH BUFFED OUT ENEMY //ANTHONY

                Boss* boss = new Boss(200,30,"THE BOSS", 20);
                fightScreen.printBossScreen(cout, userChar, boss, boss->getBossName(),winFight);
                if(winFight){
                    cout << "-------------------------------" << endl;
                    cout << "YOU HAVE DEFEATED NARDWAR" << endl;
                    cout << "-------------------------------" << endl << endl;
                    cout << "-------------------------------" << endl;
                    cout << "THANK YOU FOR FREEING FANTASMA" << endl;
                    cout << "-------------------------------" << endl << endl;
                    BossEvent = false;
                    winFight = false;

                    delete boss;
                    delete myPerlin;
                    delete newMap;
                    delete names;
                    delete userChar;
                    return 0;
                    //newMap->movementValidation('d');
                }
                delete boss;
                FightEvent = false;
                newMap->movementValidation('d');

            }
            cout << "Waiting for keypress... " << endl;
        }
        ///////////////////////////////////////////////////////
        
    
        input = getchar();

        ////////////////////INPUT VALIDATION///////////////////
        if(MapEvent){
            newMap->movementValidation(input);
        }else if(TownEvent){
            buySequence(input, newMap, userChar);
        }else if(InventoryEvent){
            cout << "\033[2J\033[1;1H";
            userChar->displayInventory();

            cout << "Press i to leave" << endl;
        }
        
        if(input == 'i'){ 
            InventoryEvent = !InventoryEvent;
        }

        /////////KILL SWITCH////////
        if(input == '-'){
            break;
        }
        ////////////////////////////

    }
    ////////////////////////////////////////////////////

    //Delete memory allocation
    delete myPerlin;
    delete newMap;
    delete names;
    delete userChar;
    return 0;
}



void inventorySequence(char input, Character* player){
    int choice = (input - 48);

    
    if(choice > player->getInventorySize() || choice <= 0) return;

    if(player->getEquipped() == player->getInventoryItem(choice-1)){ 
        //unequip
        player->UnequipItem();

    }else{
        //equip
        player->equipItem( player->getInventoryItem(choice-1)  );
    }
}

void buySequence(char input, Map* newMap, Character* player){
    if(player->isInventoryFull() && input != 'l'){
        cout << endl << "your inventory is full! Lose items to pickup more!" << endl;
        return;
    }
    Town* town = newMap->returnTown();

    switch(input){
        case 'l':
            newMap->movementValidation('d');
            break;
        case '1':
            //if inventory isn't full, then remove item from shop and add to player inventory
            if(town->getShopSize() >= 1){
                Item* shopItem = town->getItem(0);
                player->addItem(shopItem);
                town->removeShopItem(0);
                //delete shopItem;
            }
            break;
        case '2':
            //if inventory isn't full, then remove item from shop and add to player inventory
            if(town->getShopSize() >= 2){
                Item* shopItem = town->getItem(1);
                player->addItem(shopItem);
                town->removeShopItem(1);
                //delete shopItem;
            }
            break;
        case '3':
            //if inventory isn't full, then remove item from shop and add to player inventory
            if(town->getShopSize() >= 3){
                Item* shopItem = town->getItem(2);
                player->addItem(shopItem);
                town->removeShopItem(2);
                //delete shopItem;
            }
            break;
        case '4':
            //if inventory isn't full, then remove item from shop and add to player inventory   
            if(town->getShopSize() >= 4){      
                Item* shopItem = town->getItem(3);
                player->addItem(shopItem);
                town->removeShopItem(3);
                //delete shopItem;
            }
            break;
        case '5':
            //if inventory isn't full, then remove item from shop and add to player inventory
            if(town->getShopSize() >= 5){
                Item* shopItem = town->getItem(4);
                player->addItem(shopItem);
                town->removeShopItem(4);
                delete shopItem;
            }
            break;

        default:
            break;
            }
}

char menu(){
    char choice = ' ';
    cout << "\033[2J\033[1;1H"; 
    cout << "=============================================" << endl;
    cout << "                 FANTASMA                    " << endl;
    cout << "=============================================" << endl;
    
    cout << endl << endl;

    cout << "To start the game, please type [S] "<< endl;
    cout << "To end the game, please type [Q] "<< endl;

cin >> choice;
while(choice != 's' && choice != 'q'){
    cin >> choice;
}
if (choice == 's'){

    return choice;
}else{
    cout << endl;
    cout << "Thank you for playing" << endl;
    exit(0);
}

}

void characterSelection(char userChoice, Character*& userChar){
    if (userChoice == 's') {
        cout << "\033[2J\033[1;1H";
        
        int classChoice;

        cout << "The land of Fantasma used to be a prosperous nation with a friendly and loving population, until their peaceful ways were usurped and their land seized by the ever-powerful Nardwar, an ancient being who roams across the globe and toys with the lives of the innocents for his own amusement. Fantasma yearns for the improbable arrival of their savior, and here you have arrived. You have chosen to challenge the timeless devil Nardwar, now you must choose how you will approach this epic showdown. " << endl << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "(1) Choose to be a fighter , and you will learn the ways of the blade, as well as how to use your emotions to wreak more havoc and prolong your life. " << endl << endl;
        cout << "(2) Being a bard grants you the aptidude to connect yourself with music, using the sound waves to sway the enemy and lift your spirits in battle. " << endl << endl; 
        cout << "(3) Choosing the way of the mage permits you access to the dark arts of Fantasma, and while you wont be as tuned in the arts of physical combat, you can deal more damage with your higher sense of battle intellect. " << endl << endl; 
        cout << "(4) Lastly, choosing to become a tank is for those who dont mind getting their hands dirty, and who enjoy relying on pure domination." << endl << endl;
        cout << "Choose now (1-4), and restore this once-great land to its former glory: " << endl;

        cin >> classChoice;

        while (classChoice < 1 || classChoice > 4) {
            cout << "Invalid input. Choose 1-4 and try again: ";
            cin >> classChoice;
        }

        if (classChoice == 1) {
            
            userChar = new Fighter;
            Item* fighterStarter = new Item(2, 7, 3, 2, 1, 1, "Basic sword");
            userChar->addItem(fighterStarter);
            cout << "You have chosen the way of the fighter. You're given a basic sword when your training concludes." << endl;

        }

        else if (classChoice == 2) {

            userChar = new Bard;
            bardItem* bardStarter = new bardItem(5, 2, 5, 5, 5, 5, "Beat boxing", 5, 3);
            userChar->addItem(bardStarter);
            cout << "You have chosen the way of the bard. You've acquired the skillful craft of beat boxing in your training." << endl;

        }

        else if (classChoice == 3) {

            userChar = new Mage;
            mageItem* mageStarter = new mageItem(3, 5, 1, 5, 3, 5, "Wooden staff", 3, 3);
            userChar->addItem(mageStarter);
            cout << "You have chosen the way of the mage. Your master grants you with a simple wooden staff to complete your training." << endl;

        }

        else {

            userChar = new Tank;
            tankItem* tankStarter = new tankItem(4, 3, 5, 3, 1, 1, "Sturdy stick", 3, true);
            userChar->addItem(tankStarter);
            cout << "You have chosen the way of the tank. After dominating the mountains to become a monster in human flesh, you salvage a sturdy stick to impose your will on opponents." << endl;
        }
    }
}