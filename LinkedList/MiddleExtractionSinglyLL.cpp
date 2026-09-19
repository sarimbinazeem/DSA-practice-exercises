/*
A university examination system stores students' roll numbers as a chain of connected boxes. The invigilator needs to identify the middle student in the queue to distribute answer sheets from the center outward. The system must find the middle box in a single pass without counting the total length first.

Given the head of this chain, return the middle box. If the chain has an even number of boxes, return the second middle box. Solve using the two-pointer technique.

Input (Odd): [1] → [2] → [3] → [4] → [5] → NULL
Expected Output (Odd): Middle  = [3]

Input (Even):[1] → [2] → [3] → [4] → [5] → [6] → NULL
Expected Output (Even): Middle Box = [4]   (second middle)

*/

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

Node* findMiddle(Node*head)
{
    Node*slow = head;
    Node*fast = head;

    //when the fast pointer moves at the end of the list, slow point is at the middle of the list
    while(fast!= NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout<<"\n====List====\n";
    list.display();

    Node*head = list.head;
    Node* middle = findMiddle(head);

    cout<<"Middle Node: "<<middle->data<<endl;
}