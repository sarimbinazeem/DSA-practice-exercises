/*
Question 10
You are developing a game called Treasure Battle in which several players are waiting to enter a
treasure cave. Each player has a unique ID and starts with `100` energy points. Players enter the
cave in the order in which they arrive. During the game, players take turns one by one. On each
turn, the player at the front gets exactly one command to perform. After completing the command,
if the player is still active, they go to the end of the waiting line and the next player gets a turn. If
a player's energy becomes `0` or less, that player is eliminated and does not return to the waiting
line.
The available commands are `F` (move forward), `B` (move backward), `T` (collect treasure), and
`U` (undo the previous valid action). A forward move decreases the player's energy by `10`,
moving backward has no effect on energy, and collecting treasure increases the player's energy by
`20`. Whenever a player performs `F`, `B`, or `T`, the action must be remembered because the
player may later use `U`. When `U` is performed, only the most recent action of that player is
cancelled and its effect must be reversed. An `U` command itself cannot be cancelled. If the player
has no previous action to undo, the command has no effect. Each player must maintain their own
history of actions independently.
The game is given as a sequence of commands. You must process all commands according to the
rules above. At the end, display the order in which players were eliminated, followed by the IDs
and remaining energy of all active players in the waiting line. Also display the number of actions
that can still be undone for each remaining player. You must implement the required data structures
yourself using arrays. Do not use STL containers such as `stack`, `queue`, `vector`, or `deque`.*/

#include <iostream>
using namespace std;

class Player
{
    public:
        int id;
        int energy;

        Player()
        {
            id = 0;
            energy=100;
        }
        Player(int id){
            this->id = id;
            energy=100;
        }
};

class Movement{
    public:
        char action;
        Movement()
        {
            action = '\0';
        }
        Movement(char a)
        {
            action = a;
        }
};

class Stack{
    public:
        //each player has its own stack
        Movement actions[100];
        int top;

        Stack()
        {
            top = -1;
        }
        bool isEmpty()
        {
            return top == -1;
        }
        bool isFull()
        {
            return top == 99;
        }
        void push(Movement a)
        {
            if(isFull())
            {
                cout<<"Stack Overflow! \n";
                return;
            }
            top++;
            actions[top] = a;
        }
        
        Movement pop()
        {
            Movement temp;
            if(isEmpty())
            {
                cout<<"Stack UnderFlow\n";
                return temp;
            }
            temp = actions[top];
            top--;
            return temp;
        }
        int getSize()
        {
            return top+1;
        }
};

class PlayerHistory
{
    public:
        Stack history;
        Player player;
        
        PlayerHistory()
        {

        }

        PlayerHistory(int id)
        {
            player = Player(id);
        }
};

class Queue
{
    public:
        PlayerHistory records[100];
        int front;
        int rear;
        int count;

        Queue()
        {
            front = 0;
            rear = -1;
            count = 0;
        }

        bool isEmpty()
        {
            return count==0;
        }
        bool isFull()
        {
            return count==100;
        }

        void enqueue(PlayerHistory r)
        {
            if(isFull())
            {
                cout<<"Queue Overflow! \n";
                return;
            }
            rear = (rear +1) %100;
            records[rear] = r;
            count++;
        }

        PlayerHistory dequeue()
        {
            PlayerHistory temp;
            if(isEmpty())
            {
                cout<<"Queue IS Empty..\n";
                return temp;
            }
            temp = records[front];
            front = (front+1)%100;
            count--;
            return temp;
        }

};

int main()
{
    Queue waitingLine;
    int commands, players;

    cout<<"Enter Number of Players: ";
    cin>>players;

    for(int i = 0;i<players;i++)
    {
        int id ;
        cout<<"Enter Player "<<i+1<<" ID: ";
        cin>>id;

        PlayerHistory p(id);
        waitingLine.enqueue(p);
    }

    cout<<"Enter Number of Commands: ";
    cin>>commands;

    int eliminatedPlayers[100];
    int eliminated = 0;

    for(int i=0; i<commands; i++)
    {
        if(waitingLine.isEmpty())
        {
            cout<<"All the players have been eliminated.\n";
            break;
        }
        char command;
        cout << "\nEnter Command (F for forward, B for Backward, T for treasure, U for undo): ";
        cin >> command;

        //converting to lowercase
        if(command >= 'a' && command <= 'z')
        {
            command = command - 32;
        }

        //get the plaeyer from queue
        PlayerHistory player = waitingLine.dequeue();
        
        cout<<"Player "<<player.player.id<<" Chose Command "<<command<<endl;

        if(command == 'F')
        {
            //decrease 10 energy
            player.player.energy -=10;
            player.history.push(Movement('F'));
        }
        else if(command == 'B')
        {
            // B does not change energy
            player.history.push(Movement('B'));
        }
        else if(command == 'T')
        {
            // T increases energy by 20

            player.player.energy += 20;
            player.history.push(Movement('T'));
        }
        else if(command == 'U')
        {
            if(!player.history.isEmpty())
            {
                Movement lastAction = player.history.pop();

                if(lastAction.action == 'F')
                {


                    player.player.energy += 10;
                }

                else if(lastAction.action == 'T')
                {

                    player.player.energy -= 20;
                }
            }
            else
            {
                cout<<"Nothing to UNDO ! \n";
            }
        }
        else
        {
            cout<<"Invalid Command! \n";

            //move this player to end if not eliminated
            if(player.player.energy >0){
                waitingLine.enqueue(player);
            }

            continue;
        }

        //checking for leiniation
        if(player.player.energy <=0)
        {
            cout<<"Player "<<player.player.id<<" Has been Eliminated! \n";
            eliminatedPlayers[eliminated] = player.player.id;
            eliminated++;
        }
        else{
            waitingLine.enqueue(player);
        }

    }


        cout << "\nFINAL RESULT\n";


    cout << "\nElimination Order Is: ";

    if(eliminated == 0)
    {
        cout << "None";
    }
    else
    {
        for(int i = 0; i < eliminated; i++)
        {
            cout << eliminatedPlayers[i];

            if(i < eliminated - 1)
            {
                cout << " -> ";
            }
        }
    }

    cout << endl;


    cout << "\nPlayers In Waiting Line are:\n";


    if(waitingLine.isEmpty())
    {
        cout << "None\n";
    }
    else
    {
        int numberRemaining = waitingLine.count;

        for(int i = 0; i < numberRemaining; i++)
        {
            PlayerHistory current = waitingLine.dequeue();

            cout << "Player ID: " << current.player.id << endl;

            cout << "Remaining Energy: "<< current.player.energy << endl;

            cout << "Actions That Can Still Be Undone: " << current.history.getSize() << endl;

            cout << endl;


            // Put the front player in the bck of the queue to move forward
            waitingLine.enqueue(current);
        }
    }


    return 0;

}