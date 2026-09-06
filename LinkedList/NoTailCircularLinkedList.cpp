/*  Write a C++ program to implement a circular linked list of characters using only head pointer. (No tail pointer)
Your program should:

Create an empty linked list.
Add 5 characters to the end of the list.
Display all characters.
Ask the user for a character to search.
Display "Found" if the character exists; otherwise display "Not Found".*/

#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
};

class CircularLL
{
    private:
        Node*head;

    public:
        CircularLL()
        {
            head = nullptr;
        }

        void append(char elem)
        {
            Node*temp = new Node;
            temp->data = elem;
            
            if(head == NULL)
            {
                head = temp;
                temp->next =  head;
                return;

            }

            //since there is no tail pointer, we will use a loop to get to the end
            Node*curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = temp;
            temp->next = head; //for circular

        }

        void display()
        {
            if(head == NULL)
            {
                cout << "List is empty...\n";
                return;
            }
            
            Node*temp = head;
            
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp!=head);
        }
        
        void search(char c)
        {
            if(head == NULL)
            {
                cout << "List is empty...\n";
                return;
            }

            Node*temp = head;
            
            do{
                if(temp->data == c)
                {
                    cout<<"Character "<<c <<" found in the list.\n";
                    return;
                }
                
				temp = temp->next;
            }while(temp!=head);

            cout<<"Character "<< c <<" was not found in the list.\n";

        }

    ~CircularLL()
    {
        if(head == NULL)
        {
            return;
        }

        // To delete all the nodes we find the last node and break the circular cycle
        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        // Break the cycle
        temp->next = NULL;

        // Delete normally
        temp = head;

        while(temp != NULL)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        head = NULL;
    }

};

int main()
{
    CircularLL list;

    cout<<"\n====Adding Nodes====\n";
    list.append('S');
    list.append('A');
    list.append('R');
    list.append('I');
    list.append('M');
    
    cout<<endl;

    cout<<"\n====Ciruclar Linked List===\n";
    list.display();
    cout<<endl;

    char elem;
    cout<<"Enter Character You Want To Search: ";
    cin>>elem;

    list.search(elem);

}