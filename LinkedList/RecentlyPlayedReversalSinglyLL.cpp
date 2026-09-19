// A music streaming app stores a user's "Recently Played" songs as a chain of connected boxes, where each box holds a song and a pointer to the next box. The most recently played song sits at the front. A software update accidentally reversed the display order. The team must now reverse the entire chain in-place so the oldest played song appears first  without creating any new boxes.

// Given the head of this chain, reverse it in-place and return the new head. You must not allocate new memory. Show the pointer manipulation at each step.

// Input:  [10] → [20] → [30] → [40] → [50] → NULL
// Expected Output: [50] → [40] → [30] → [20] → [10] → NULL

#include <iostream>
using namespace std;

class Node{
    public:
        Node*next;
        int data;

        Node()
        {
            next = nullptr;
            data = 0;
        }
        Node(int d)
        {
            data = d;
            next= nullptr;
        }

};

class LinkedList
{
    public:
        Node*head;
        Node*tail;

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void insert(int elem)
        {
            Node*temp = new Node(elem);
            if(head == NULL)
            {
                head = temp;
                tail = temp;

                tail->next = NULL;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        void display()
        {
            if(head==NULL) return;

            Node*temp = head;
            while(temp!= NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<" NULL";
            cout<<endl;
        }

        ~LinkedList()
        {
            Node*temp = head;
            while(temp!=NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;
            }
        }
    };
    
    Node* reverse(Node*head)
    {
        //we reverse the direction only
        Node*prev = NULL;
        Node*curr = head;   
        Node*next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            
            //reversing
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        //now previous becomes the new head
        return prev;
    }
    
    void displayReversed(Node*head)
    {
        if(head == NULL) return;
        Node*temp = head;
        while(temp!= NULL)
        {
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<" NULL \n";
    }
int main()
    {
        LinkedList list;
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);

    cout<<"\n===Original List===\n";
    list.display();

    Node*temp = list.head;
    Node*reversed = reverse(temp);

    cout<<"\n===Reversed List===\n";
    displayReversed(reversed);

    delete reversed;
}