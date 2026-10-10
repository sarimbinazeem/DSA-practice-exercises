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
    {
        temp = temp->next;
    }

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

Node*mergeSorted(Node*head1,Node*head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    if(head1->data <= head2->data){
        head1->next = mergeSorted(head1->next,head2);
        return head1;
    }
    else{
        head2->next = mergeSorted(head1,head2->next);
        return head2;
    }

}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertAtEnd(head1, 10);
    insertAtEnd(head1, 30);
    insertAtEnd(head1, 50);

    insertAtEnd(head2, 20);
    insertAtEnd(head2, 40);
    insertAtEnd(head2, 60);

    cout << "First sorted list: ";
    printList(head1);

    cout << "Second sorted list: ";
    printList(head2);

    Node* mergedHead = mergeSorted(head1, head2);

    cout << "Merged sorted list: ";
    printList(mergedHead);

    return 0;
}
