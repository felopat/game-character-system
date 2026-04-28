#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

struct Weapon
{
    string weaponName;
    int bonusDamage;
};


class Character
{
protected:
    string name;
    int health, basePower, level, maxHealth, xp, xpThreshold;
    Weapon activeWeapon;

public:
    Character(string n, int h, int p, string wName):
        name(n) , health(h) , basePower(p),
        maxHealth(h), level(1), xp(0),xpThreshold(100)
    {
        activeWeapon.weaponName = wName;
        activeWeapon.bonusDamage = 0;
    }


    virtual ~Character(){}


    void selectWeapon(name)
    {
        if (name == "Broadsword") activeWeapon.bonusDamage = 15;
        else if (name == "Dagger") activeWeapon.bonusDamage = 8;
        else if (name == "Scepter") activeWeapon.bonusDamage = 25;

    }

    virtual void attack(Character &enemy) = 0;

    void takeDamage(int amount)
    {
        if (health > 0) health -= amount;
        else if(health < 0) health = 0;
    }

    void gainXP(int amount) {
        xp += amount;
        cout << name << " gained " << amount << " XP! (" << xp << "/" << xpThreshold << ")" << endl;

        while (xp >= xpThreshold) {
            levelUp();
        }
    }

    void showXPBar() {
        int barWidth = 10;
        float progress = (float)xp / xpThreshold;
        int pos = barWidth * progress;

        cout << name << " [";
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "=";
            else cout << " ";
        }
        cout << "] " << xp << "/" << xpThreshold << " XP" << endl;
    }



    void levelUp()
    {
        xp -= xpThreshold;
        level++;
        maxHealth += 20;
        health = maxHealth;
        basePower += 5;

        cout << "\n LEVEL UP! " << name << " reached Level " << level << "!" << endl;
        cout << "New Stats -> HP: " << maxHealth << " | Power: " << basePower << endl;
    }


    string getName() { return name; }
    int getHealth() { return health; }
};










#endif // CHARACTER_H
