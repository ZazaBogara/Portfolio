class Fighter
{
public:
    std::string Name;
    int Health;
    int DamagePerAttack;
    Fighter(std::string objectName, int objectHealth, int objectdamagePerAttack);
};

class Fight
{
public:
    void FightTwoGuys(Fighter fighter1, Fighter fighter2);
};
