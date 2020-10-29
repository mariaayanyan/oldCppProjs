#include <iostream>
using namespace std;

struct Tank
{
    double health, attack, defense;
    double startingHealth;
    
    bool isDead()
    {
        return health <= 0;
    }
};

void Input(Tank& tank)
{
    cin >> tank.health >> tank.attack >> tank.defense;
    tank.startingHealth = tank.health; 
}

bool Validate(const Tank& tank)
{
    return tank.health > 0 && tank.health == (int)tank.health &&
           tank.attack > 0 && tank.defense >= 0 && tank.defense <= 1;  
}

bool Hit(const Tank& attacker, Tank& defender)
{
    defender.health -= attacker.attack*(1-defender.defense)*attacker.health/attacker.startingHealth; 
    defender.health = (int)defender.health;
}

int main()
{
    Tank T[2];
    cout << "Welcome to tank battle.\n";
    do
    {
        cout << "Please enter the first tank's characteristics: health attack defence\n";
        Input(T[0]);
    } while (!Validate(T[0]));

    do
    {
        cout << "Please enter the second tank's characteristics: health attack defence\n";
        Input(T[1]);
    } while (!Validate(T[1]));

    cout << "\nInto the motherland the German army march!\n\n";

    while(true)
    {
        cout << "Enter the number of the attacking tank <1 or 2>\n";
        
        int num;
        cin >> num;
        --num;

        Hit(T[num], T[(num+1)%2]);
        if(T[(num+1)%2].isDead())
        {
            cout << "Tank " << (num + 1)%2 + 1 << " is dead\n";
            return 0;
        }
        cout << "Tank1 health: " << T[0].health << endl;
        cout << "Tank2 health: " << T[1].health << endl;
    }
    
}