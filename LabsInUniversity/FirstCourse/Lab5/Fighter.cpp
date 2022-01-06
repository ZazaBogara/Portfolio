#include "Fighter.h"
#include <iostream>
#include <math.h>
#include <string.h>

/*
Створіть клас Fighter (name, health, damagePerAttack).
Додайте клас Fight, який міститиме пару бійців і метод, який повертає ім’я переможця в поєдинку двох бійців.
Кожен боєць по черзі нападає на іншого, і той, хто першим вбиває іншого, перемагає.
Смерть визначається як стан здоров'я <= 0. 
*/

Fighter::Fighter(std::string objectName, int objectHealth, int objectdamagePerAttack)
{
    this->Name = objectName;
    this->Health = objectHealth;
    this->DamagePerAttack = objectdamagePerAttack;
};


void Fight::FightTwoGuys(Fighter fighter1, Fighter fighter2)
{
    while (fighter1.Health >= 0 and fighter2.Health >= 0)
    {
        fighter1.Health -= fighter2.DamagePerAttack;
        fighter2.Health -= fighter1.DamagePerAttack;
    }
    if (fighter1.Health <= 0)
    {
        std::cout << "Winner is: " << fighter2.Name;
    }
    else
    {
        std::cout << "Winner is: " << fighter1.Name;
    }
};