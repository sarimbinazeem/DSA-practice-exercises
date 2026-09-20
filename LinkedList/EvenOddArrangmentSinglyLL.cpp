// Question 6:

// A ticketing system stores passengers as a chain of connected boxes, where each box holds a passenger ID. The manager wants to group all odd-positioned passengers first, followed by even-positioned passengers, while preserving their relative order. The rearrangement must be done in-place.

//  Input:  [2] → [1] → [3] → [5] → [6] → [4] → [7] → NULL


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
            head = tail = nullptr;
        }
};

void evenOdd(Node* &head)
{
    //we sepearte list into two lists (odd and even)
    Node*oddHead = NULL;
    Node*oddTail = NULL;

    Node*evenHead = NULL;
    Node*evenTail = NULL;

    Node*temp = head;
    int position = 0 ;
    while(temp!=NULL)
    {
        Node*next = temp->next;
        if(position %2 == 0)
        {
            if(evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
                evenTail->next = NULL;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
                evenTail->next = NULL;
            }
        }
        else{
            if(oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
                oddTail->next = NULL;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
                oddTail->next = NULL;
            }

        }
        temp = next;
        position++;
    }

    if(oddHead == NULL)
    {
        head = evenHead;
        return;
    }
    oddTail->next = evenHead;
    head = oddHead;

}

int main()
{
    LinkedList list;

    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    list.insert(4);
    list.insert(7);

    cout << "Original List:" << endl;
    list.display();

    evenOdd(list.head);

    cout << "\nAfter Rearrangement:" << endl;
    list.display();

    return 0;
}