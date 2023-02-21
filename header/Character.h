#ifndef CHARACTER_H
#define CHARACTER_H

#include "../header/Item.hpp"
#include <vector>

#include <iostream>

class Character{
    protected:
        Item* equipped;
    private:
        

        int id;
        double healthPoints;
        double manaPoints;
        double attackDamage;
        double magicDamage;
        std::vector<Item*> inventory;
        int carryCapacity;
    public:
        virtual void UnequipItem() = 0;
        Item*& getEquipped(){return equipped;}
        virtual void equipItem(Item*& item) = 0;
        
        Character(double hp, double mp, double attackDmg, double magicDmg, int carryCapacity, int id) : healthPoints(hp), manaPoints(mp),
        attackDamage(attackDmg), magicDamage(magicDmg), carryCapacity(carryCapacity), id(id) {}
        ~Character();

        void addItem(Item* item);
        void removeHealth(double x);
        void removeMana(double x);
        virtual double normalAttack(std::ostream& out) = 0;
        virtual double specialAttack(std::ostream& out) = 0;
        virtual void attacked(double x, std::ostream& out) = 0;
        double getHealth();
        double getMana();
        void displayInventory();
        virtual void useItem(std::ostream& out) = 0;
        double getAttackDamage();
        void setAttackDmg(double x);
        double getMagicDamage();
        virtual bool isInventoryFull() = 0;
        int getInventorySize();
        //bool isInventoryFull(){return inventory.size() >= carryCapacity;}

        Item*& getInventoryItem(int idx);
        void removeItem(int idx);
        void addHealth(double buff);
        void setMagicDmg(double dmg);
        int getId();
    
        

        
};

#endif
