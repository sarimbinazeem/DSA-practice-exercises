/*
Question 07
You are required to implement a Turn-Based Battle Simulator game using Doubly Linked
Lists where each node contains a Combatant object with properties like name, health points
(1-70), both inclusive and attack power (1 to 5), both inclusive. This game simulates a classic
RPG-style battle between a player’s party of heroes and a team of enemies. The core challenge
involves managing two teams - one for the hero’s team and another for the enemy team.
The hero’s team should be initialized with five heroes. The enemy team should contain five
enemies in this sequence. The battle follows a structured turn based sequence where the player
hero always attacks first in each round, followed by the enemy counterattack.
Any member of a team can attack any opponent. During each turn, the program will first ask the
player to choose an attacker (by name or position) and then select a target from the opponent’s
team (also by name or position). The attacker and target must exist in their respective teams. Once
attacker is chosen, the attacker will strike on opponent and the opponent’s health will be reduced
by:
Damage = Attack Power × Random Value (where the random value is between 1 and 3,
inclusive).
If any combatant’s health reaches zero or below, they are immediately removed from their team.
After every turn, only the names of the remaining team members from both sides will be displayed.
(do not display health points and attack power of combatant while playing the game).
The winning conditions are based on both survival and strength. If one team is completely
eliminated, the other team wins instantly. However, if the combat lasts until a fixed number of
rounds (10 Minimum), the winner is decided by comparing the total health points of the remaining
members. If both teams have the same total health, the match ends in a draw. At the end of the
game, display the names, health points, and attack power of the surviving members of the winning

team, or in the case of a draw, display the remaining members of both teams, with remaining health
points and attack power.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant{
    public:
        string name;
        int health;
        int attack;

        Combatant()
        {
            name = "";
            health = 0;
            attack = 0;
        }
        Combatant(string n,int h, int a)
        {
            name = n;
            while(h<1 || h>70)
            {
                cout<<"Invalid Health Entered! Enter Between 1-70 (Both Inclusive): ";
                cin>>h;
            }
            health = h;

            while(a<1 || a>5)
            {
                cout<<"Invalid Attack Power Entered! Enter Between 1 to 5 (both inclusive): ";
                cin>>a;
            }
            attack = a;
        }
        
};

class Node{
    public:
        Combatant data;
        Node*next;
        Node*prev;

        Node(Combatant c)
        {
            data = c;
            next = nullptr;
            prev = nullptr;
        }
};

class Team{
    public:
        Node*head;
        Node*tail;

        Team()
        {
            head = nullptr;
            tail = nullptr;
        }

        void insert(Combatant c)
        {
            Node* temp = new Node(c);

            if(head == NULL)
            {
                head = temp;
                tail = temp;
                head->prev = NULL;
                tail->next = NULL;
            }
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }
        
        int getSize()
        {
            Node*temp = head;
            int size =0;
            while(temp!= NULL)
            {
                size++;
                temp = temp->next;
            }

            return size;
        }

        //find by position
        Node* findByPos(int pos)
        {
            Node*temp = head;
            for(int i=0 ;i<pos && temp!=NULL ; i++)
            {
                
                temp = temp->next;
            }
            return temp;
        }

        void remove(Node*target)
        {
            if(target==NULL) return;
            if(target==head){
                head = target->next;
                if(head!= NULL){
                    head->prev = NULL;
                }
                else{
                    tail = NULL; //list is empty
                }
                delete target;
                return;
            }
            if(target==tail){
                tail = target->prev;
                tail->next = NULL;
                delete target;
                return;
            }

            //deleting target from middle  therefore we have to change the prev and next node of the nodes surrounding it     
             target->prev->next = target->next;
             target->next->prev = target->prev;

             delete target;
        }

        //to display each time
        void displayTeam()
        {
            Node* temp = head;

            while(temp != NULL)
            {
                cout << temp->data.name;

                if(temp->next != NULL)
                {
                    cout << " -> ";
                }

                temp = temp->next;
            }

            cout << endl;
        }

        void display()
        {
            Node* temp = head;

            while(temp != NULL)
            {
                cout << "Name: " << temp->data.name << endl;
                cout << "Health: " << temp->data.health << endl;
                cout << "Attack Power: " << temp->data.attack << endl;
                cout << endl;

                temp = temp->next;
            }
        }

        int getHealth()
        {
            int total = 0;
            Node*temp = head;
            while(temp!= NULL)
            {
                total += temp->data.health;
                temp = temp->next;
            }
            return total;
        }

        ~Team()
        {
            Node*temp = head;
            while(temp!= NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr;
            tail = nullptr;
        }
};

//choose someone from team to attack
Node* chooseMember(Team &t)
{
    int choice;

    cout<<"Choose Combatant By Name: \n";
    int position = 0;

    Node*temp = t.head;
    while(temp!= NULL)
    {
        cout<<position<<" ) "<<temp->data.name<<endl;
        temp = temp->next;
        position++;

    }

    cout<<"Enter Team Member By Position: ";
    cin>>choice;

    while(choice<0 || choice>= t.getSize())
    {
        cout<<"Invalid Position Entered! Enter From 0 to "<<t.getSize() -1<<" : "<<endl;
        cin>>choice;
    }

    return t.findByPos(choice);

}

//After choosing attacker and targer we use this function

void attack(Node*attacker, Node*target)
{
    //Formula: Damage = Attack Power × Random Value (where the random value is between 1 and 3,inclusive).
    //we take random value acccording to the formula

    //to get between 1 and 3 , we add 1
    int random = rand()%3 + 1 ;
    int damage = attacker->data.attack * random;

    target->data.health -= damage;

    cout<<"Attacker '"<<attacker->data.name<<"' Dealth  "<<damage<<" damage to Target "<<target->data.name<<"! \n";

    if(target->data.health <=0)
    {
        cout<<" Target "<<target->data.name<<" Defeated Successfully!\n";
    }
}

//function check health of teams and print the winning one according to health
void healthCheck(Team &t1, Team &t2)
{
    int t1Health = t1.getHealth();
    int t2Health = t2.getHealth();

    if(t1Health> t2Health)
    {
        cout<<"\n Hero Team Won!...\n";
        cout<<"\n===Surviving Team===\n";
        t1.display();
    }
    else if(t1Health< t2Health)
    {
        cout<<"\n Enemy Team Won!...\n";
        cout<<"\n===Surviving Team===\n";
        t2.display();
    }
    else 
    {
        cout<<"\n Both Team Survived: DRAW...\n";
        cout<<"\n===Hero Team===\n";
        t1.display();
        cout<<endl;
        cout<<"\n===Enemy Team===\n";
        t2.display();
    }
}

int main()
{
    srand(time(0));


    Team heroes;
    Team enemies;

    // FIVE HEROES

    heroes.insert(Combatant("Knight", 60, 4));
    heroes.insert(Combatant("Archer", 50, 3));
    heroes.insert(Combatant("Mage", 45, 5));
    heroes.insert(Combatant("Paladin", 70, 2));
    heroes.insert(Combatant("Rogue", 40, 4));


    // FIVE ENEMIES

    enemies.insert(Combatant("Goblin", 35, 3));
    enemies.insert(Combatant("Orc", 60, 4));
    enemies.insert(Combatant("Skeleton", 30, 2));
    enemies.insert(Combatant("Dragon", 70, 5));
    enemies.insert(Combatant("Demon", 55, 4));

    cout << "\n===========TURN BASED BATTLE==========\n";
    
    cout << "\nInitial Teams:\n";
    cout<<"\n=====Heroes======\n";
    heroes.displayTeam();

    cout<<"\n=====Enemies======\n";
    enemies.displayTeam();
    
    //Battle

    int round = 1;    
    while(round<=10 && heroes.head != NULL && enemies.head !=NULL)
    {
        cout<<"\n=== Round "<< round<<" ===\n";
        
        cout<<"\n======= Turn: HERO =======\n";
        cout<<"\n=====Heroes======\n";
        heroes.displayTeam();
        
        cout<<"\n=====Enemies======\n";
        enemies.displayTeam();
        
        Node* heroAttacker = NULL;
        Node* enemyTarget = NULL;
        
        cout<<"Choose Hero To Attack \n";
        heroAttacker = chooseMember(heroes);
        cout<<"Choose Enemy To Target \n";
        enemyTarget = chooseMember(enemies);
        
        attack(heroAttacker,enemyTarget);
        
        //if the enemy is dead we remove that from the list
        if(enemyTarget->data.health <= 0)
        {
            enemies.remove(enemyTarget);
        }
        
        cout<<"After Hero Turn: ";
        cout<<"\n=====Heroes======\n";
        heroes.displayTeam();
        cout<<"\n=====Enemies======\n";
        enemies.displayTeam();
        
        if(enemies.head == NULL)
        {
            cout << "\nAll enemies have been defeated!\n";
            cout << "Heroes win!\n";
            break;
        }
        
        
        cout << "\n===== ENEMY ATTACK =====\n";

        cout<<"\n=====Heroes======\n";
        heroes.displayTeam();
        
        cout<<"\n=====Enemies======\n";
        enemies.displayTeam();
        
        Node* enemyAttacker = NULL;
        Node* heroTarget = NULL;
        
        cout<<"Choose Enemy To Attack \n";
        enemyAttacker = chooseMember(enemies);
        cout<<"Choose Hero To Target \n";
        heroTarget = chooseMember(heroes);
        
        attack(enemyAttacker,heroTarget);
        
        //if the hero is dead we remove that from the list
        if(heroTarget->data.health <= 0)
        {
            heroes.remove(heroTarget);
        }
        
        cout<<"After Enemy Turn: ";
        cout<<"\n=====Heroes======\n";
        heroes.displayTeam();
        cout<<"\n=====Enemies======\n";
        enemies.displayTeam();
    
        if(heroes.head == NULL)
        {
            cout << "\nAll heroeas have been defeated!\n";
            cout << "Enemeis win!\n";
            break;
        }

        round++;
    }


    cout<<"\n=====Final Result======\n";

    if(heroes.head == NULL)
    {
        cout << "\nWinning Team: ENEMIES\n\n";

        cout << "Surviving Enemies:\n";

        enemies.display();
    }
    else if(enemies.head == NULL)
    {
        cout << "\nWinning Team: HEROES\n\n";

        cout << "Surviving Heroes:\n";

        heroes.display();
    }
    else{
        healthCheck(heroes,enemies);
    }

}