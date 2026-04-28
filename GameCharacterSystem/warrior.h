#ifndef WARRIOR_H
#define WARRIOR_H
#include <character.h>
#include <iostream>
using namespace std;




class Warrior : Character
{
public:
    Warrior(string n, string wN): Character(n, 150,15, wN){}


    void attack(Character &enemy) override {
        int totalDamage = basePower + activeWeapon.bonusDamage;
        cout << name << " swings their " << activeWeapon.weaponName << "!" << endl;
        enemy.takeDamage(totalDamage);
    }




};

#endif // WARRIOR_H
