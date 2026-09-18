/*You are developing a game called Undo Battle in which a player moves along a one-dimensional
path starting from position 0. The player can perform four types of commands: R moves the player
one position to the right, L moves the player one position to the left, J moves the player two
positions to the right, and B performs an Undo operation. Every valid movement (R, L, or J) must
be stored in a stack so that the most recent movement can be undone. When the player performs
B, the most recent valid movement must be removed from the stack and the player must return to
the position before that movement. An Undo operation itself must not be stored in the stack. A
movement that would take the player to a position less than 0 is considered invalid and must not
be stored in the stack. If the player requests an Undo when the stack is empty, nothing should
happen. You are required to implement the stack using a linked list and process n commands given
as input. At the end, display the player's final position, the total number of successful movements,
the total number of successful Undo operations, and the remaining elements in the stack. Do not
use STL stack or any other built-in stack data structure.*/

#include <iostream>
using namespace std;

//Node of stack will keep track of movement and previous postion (for undo)
class Node
{
    public:
        char direction;
        int prevPos;
        Node*next;
        Node(char dir, int pos)
        {
            direction = dir;
            prevPos = pos;
            next = nullptr;

        }

};

class Stack
{
    public:
        Node*top;

        Stack(){
            top = NULL;
        }

        void push(Node*n)
        {
            if(top == NULL)
            {
                top = n;
                top->next = NULL;
                return;
            }
            n->next = top;
            top = n;
        }

        Node* pop()
        {
            if(top== NULL)
            {
                cout<<"Stack IS Empty..\n";
                return NULL;
            }
            Node*temp = top;
            top = top->next;
            return temp;
        }

        void display()
        {
            if(top == NULL)
            {
                cout << "Stack is empty..." << endl;
                return;
            }

            Node* temp = top;

            cout << "Stack From Top To Bottom: ";

            while(temp != NULL)
            {
                cout << temp->direction;

                if(temp->next != NULL)
                {
                    cout << " -> ";
                }

                temp = temp->next;
            }

            cout << endl;
        }

        ~Stack()
        {
            Node*temp = top;
            while(temp!= NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;
                 
            }
        }
};

int main()
{
    Stack stack;
    int movements;

    cout<<"Enter Number of Movements: ";
    cin>>movements;

    int position = 0;
    int successfulMovements = 0;
    int successfulUndos = 0;

    cout<<"Enter "<<movements<<" Commands (R->right,L->left,J->jump,B->undo): ";

    for(int i=0;i<movements;i++)
    {
        char command;
        cout<<"Enter Command "<<i+1<<": ";
        cin>>command;

        int prev,newPos;
        
        switch(command)
        {
            case 'R':
{                //move to thr right (there is no restrcition of size so we move freely)
                prev = position;
                newPos = position +1;
                position  = newPos;
                Node* temp =new Node('R',prev);
                stack.push(temp);
                successfulMovements++;
                break;}

            case 'L':
{                    //move to the left (we need to check boundary)
                     newPos = position-1;
                    if(newPos<0)
                    {
                        cout<<"Invalid Position -> Cant go Left..\n";
                        continue;
                    }
                     prev = position;
                    position = newPos;
                    Node* temp =new Node('L',prev);
                    stack.push(temp);
                    successfulMovements++;
                    break;}
                    
            case 'J':
{                    //Jump 2 right
                     prev = position;
                     newPos = position +2;

                    position = newPos;
                    Node* temp =new Node('J',prev);
                    stack.push(temp);
                    successfulMovements++;
                    break;}

            case 'B':
{                    //Undo button
                    // we get the top node and update position to previous position

                    if(stack.top ==NULL)
                    {
                        cout<<"Stack is Empty. \n";
                        continue;
                    }
                    Node*temp = stack.pop();
                    position = temp->prevPos;

                    successfulUndos++;
                    delete temp;
                    break;}

            default:
                    cout<<"Invalid Operation Entered..\n";
                    break;

        }
    }

    cout << "===============FINAL RESULT===============" << endl;



    cout << "Final Position: "     << position << endl;


    cout << "Successful Movements: " << successfulMovements << endl;


    cout << "Successful Undo Operations: "<< successfulUndos << endl;


    stack.display();



}