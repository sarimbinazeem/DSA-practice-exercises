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

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node * head)
{
    if(head == NULL || head->next == NULL) return head;

    //get the tail
    Node* newHead = reverse(head->next);

    // 30->40 -> NULL becomes 40->30->NULL
    head->next->next = head;
    head->next = NULL;

    return newHead;

}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original linked list: ";
    printList(head);

    head = reverse(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}