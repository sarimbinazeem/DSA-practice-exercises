// A banking security system stores a user's entered PIN digits as a chain of connected boxes. Before granting access, the system must verify whether the digit sequence reads the same forwards and backwards (i.e., it is a mirror sequence). The verification must not use extra memory.

// Input : [1] → [2] → [3] → [2] → [1] → NULL


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

bool isPalindrome(Node*head)
{
    //we do the reversing from the second half
    Node*slow = head;
    Node*fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //now reverse only the second half (if second half is == first half then palindrome)
    Node*prev = NULL;
    Node*curr = slow; //start from middle
    Node*next= NULL;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //now the list becomes like thsi 1->2-> 3-> NULL
    //                                      |-> 2-> 1

    //which means we check from first half to null and second half to null
    Node*h1 = head;
    Node*h2 = prev;

    while(h2 != NULL)
    {
        if(h1->data != h2->data)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout<<"\n===List===\n";
    list.display();

    Node*head = list.head;
    if(isPalindrome(head))
    {
        cout<<"Given List is a Mirror Sequence \n";
    }
    else{
        cout<<"Given List is not a Mirror Sequence.\n";
    }
}