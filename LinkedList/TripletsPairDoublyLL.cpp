/*
A financial fraud detection system stores transaction amounts in a two-way sequence of connected records. Each record holds a transaction amount and is linked to both the next record and the previous record, allowing analysts to move forward and backward through the data. An analyst wants to find how many triplets of transactions sum exactly to a suspicious value x. Each triplet must consist of three distinct records.
count the number of triplets (three distinct records) whose values sum to X. Return the count.
Input: NULL ← [1] ⇄ [2] ⇄ [3] ⇄ [4] ⇄ [5] → NULL , X = 6
Expected Output:  
All triplets checked:
(1,2,3) = 6  ✓
(1,2,4) = 7  ✗
(1,2,5) = 8  ✗
(1,3,4) = 8  ✗
(1,3,5) = 9  ✗
(1,4,5) = 10 ✗
(2,3,4) = 9  ✗
(2,3,5) = 10 ✗
(2,4,5) = 11 ✗
(3,4,5) = 12 ✗
Matching: 1


*/
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

int countTriplets(Node*head, Node*tail , int suspicious)
{
    int count = 0 ;
    Node*first = head;

    while(first!=NULL)
    {
        //we make triplets (first,left,right) where right starts from tail and go backwards
        Node*left = first->next;
        Node*right = tail;

        
        //left!=right to avoid matching elemets
        //left!= right->next so that left dont go after right pointer
        while(left!=NULL && right !=NULL && left!=right && left != right->next)
        {
            int sum = left->data + right->data + first->data;

            if(sum == suspicious)
            {
                count++;
                left = left->next;
                right = right->prev;
            }
            else if(sum<suspicious)
            {
                //since its a ordered list , if sum is less we move to right
                left = left->next;
            }
            else{
                right = right->prev;
            }

        }
        first = first->next;
    }

    return count;
}
int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List:" << endl;
    list.display();

    cout<<endl;

    int x;
    cout<<"Enter Suspicious Value: ";
    cin>>x;
    int count = countTriplets(list.head,list.tail,x);

    cout << "\nTotal Triplets Detected: " << count <<endl;


    return 0;
}