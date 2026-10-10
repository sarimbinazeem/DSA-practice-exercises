
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int value)
{
    Node* newNode = new Node(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node* reverseK(Node* head, int k)
{
    if(head == NULL || k<=1){
        return head;
    }
    
    //WE REVERSE THE LIST TILL KTH
    Node*curr = head;
    Node*prev = NULL;
    Node*next = NULL;

    int count = 0;
    while(count < k && curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //this connects alll the links of new reversed lists after unwinding
    if(next != NULL){
        head->next = reverseK(next,k);
    }

    return prev;
}

int main()
{
    Node* head = NULL;

    for(int i = 1; i <= 8; i++)
        insertAtEnd(head, i);

    cout << "Original list: ";
    printList(head);

    int k = 3;

    head = reverseK(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
