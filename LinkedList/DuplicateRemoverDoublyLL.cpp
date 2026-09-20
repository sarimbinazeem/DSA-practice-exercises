// A hospital stores patient IDs in an ordered two-way sequence of connected records, where each record is linked to both the next record and the previous record (allowing traversal in both directions). Due to a data entry bug, some IDs got duplicated. The records team must clean the sequence so that each ID appears only once, preserving the order. Both forward and backward links must remain consistent after cleanup. delete all duplicate records so each element appears only once. Return the cleaned sequence. 

// Input: NULL ← [1] ⇄ [1] ⇄ [2] ⇄ [3] ⇄ [3] ⇄ [3] ⇄ [4] → NULL
// Expected Output: NULL ← [1] ⇄ [2] ⇄ [3] ⇄ [4] → NULL

#include <iostream>
using namespace std;


class Node{
    public:
        Node*next;
        Node*prev;
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
                head->prev = NULL;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        void removeDuplicate()
        {
            Node*temp = head;
            while(temp!=NULL && temp->next !=NULL)
            {
                if(temp->data == temp->next->data)
                {
                    Node*next = temp->next;
                    temp->next = next->next;
                    
                    if(temp->next != NULL)
                    {
                        temp->next->prev = temp;
                    }
                    else
                    {
                        tail = temp;
                    }
                    delete next;
                }
                else{

                    temp = temp->next;
                }
            }
        }

        void display()
        {
            if(head==NULL) return;

            Node*temp = head;
            cout<<"NULL <-> ";
            while(temp!= NULL)
            {
                cout<<temp->data<<" <-> ";
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
            head = tail = nullptr;
        }
};



int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(4);

    cout << "Original List:" << endl;
    list.display();

    list.removeDuplicate();

    cout << "\nAfter Removing Duplicates:" << endl;
    list.display();

    return 0;
}