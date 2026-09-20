// A city's road network is modeled as two chains of connected boxes representing two routes that eventually merge into a common road (a Y-shaped junction). Traffic control needs to find the exact box where the two routes meet, so signals can be synchronized. The solution must not modify the chains.

// Given the heads of two chains that intersect at some box, return the box at which the intersection begins. If they do not intersect, return NULL.

// Input:

// Chain A:  [4] → [1] ↘
//                        [8] → [4] → [5] → NULL
// Chain B:  [5] → [6] → [1] ↗

// Expected Output: Intersection point = [8]


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

Node* findIntersection(Node*head1, Node*head2)
{
    Node*h1 = head1;
    Node*h2 = head2;

    //condition for ntersection
    while(h1 != h2)
    {
        //if the list goes to end we move the listcontrol to second list
        if(h1 == NULL)
        {
            h1 = head2;
        }
        else{
            h1 = h1->next;
        }

        if(h2 == NULL)
        {
            h2 = head1;
        }
        else{
            h2 = h2->next;
        }
    }
    return h1;
}

int main()
{
    LinkedList list1,list2;

    list1.insert(4);
    list1.insert(1);
    
    list2.insert(5);
    list2.insert(6);
    list2.insert(1);

    LinkedList shared;
    shared.insert(8);
    shared.insert(4);
    shared.insert(5);

    list1.tail->next = shared.head;
    list2.tail->next = shared.head;

    cout<<"\n=====List 1====\n";
    list1.display();
    
    cout<<"\n=====List 2====\n";
    list2.display();

    Node*head1 = list1.head;
    Node*head2 = list2.head;
    Node*intersection = findIntersection(head1,head2);


    cout<<"\n=======Merged List======\n";
    cout<<"Intersection at ["<<intersection->data<<"] \n";

    list1.tail->next = nullptr;
    list2.tail->next = nullptr;

}