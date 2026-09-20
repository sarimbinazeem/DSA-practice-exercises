// Question 4:

// Two departments of a company each maintain their employee IDs in a sorted list. The HR department wants to merge both lists into a single sorted list for payroll processing. The merge must be done by rearranging the existing list.

// Given the heads of two sorted list, merge them into one sorted list and return its head.

// Input:
// Chain A: HEAD1 → [1] → [3] → [5] → [7] → NULL
// Chain B: HEAD2 → [2] → [4] → [6] → [8] → NULL

// Expected Output:  [1] → [2] → [3] → [4] → [5] → [6] → [7] → [8] → NULL


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
Node* merge(Node*head1,Node*head2)
{
    Node*h1 = head1;
    Node*h2 = head2;

    Node dummy;
    Node*tail = &dummy;

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data < h2->data)
        {
            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            tail = tail->next;
            h2 = h2->next;
        }

    }

    if(h1!=NULL)
    {
        tail->next = h1;

    }
    if(h2!=NULL)
    {
        tail->next = h2;

    }

    return dummy.next;
}

void display(Node*head)
{
    if(head==NULL) return;

    Node*temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<" NULL \n";
}

int main()
{
    LinkedList list1,list2;

    list1.insert(1);
    list1.insert(3);
    list1.insert(5);
    list1.insert(7);
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);
    list2.insert(8);

    cout<<"\n=====List 1====\n";
    list1.display();
    
    cout<<"\n=====List 2====\n";
    list2.display();

    Node*head1 = list1.head;
    Node*head2 = list2.head;
    Node*merged = merge(head1,head2);
    list1.head = nullptr;
    list2.head = nullptr;

    cout<<"\n=======Merged List======\n";
    display(merged);

    while(merged != nullptr) {
        Node* next = merged->next;
        delete merged;
        merged = next;
    }

}