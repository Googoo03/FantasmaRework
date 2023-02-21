#ifndef FIGHTER_H
#define FIGHTER_H

#include "../header/Character.h"
#include "iostream"

class Fighter: public Character {
    private:

        bool usingItem;
        bool isFighterItem(Item* item);
        void equipItem(Item*& item);
   


    public:
        void UnequipItem();

        Fighter() : usingItem(false), Character{180, 80 , 50, 30, 8, 2} {}
        double normalAttack(std::ostream& out);
        double specialAttack(std::ostream& out);
        void attacked(double x, std::ostream& out);
        bool isInventoryFull();
        void useItem(std::ostream& out);

        

};


#endif
