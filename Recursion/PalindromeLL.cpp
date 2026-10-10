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

//we pass by refrence becasue we want to move the actual pointers
bool checkPalindrome(Node* &left, Node* &right)
{
    //we move the right pointer to the end recursivel
    if(right == NULL){
        return true;
    }

    bool result = checkPalindrome(left, right->next);

    //if the result is false (left != right) then return false
    if(result == false){
        return false;
    }
    if(left->data != right->data){
        return false;
    }

    //if equal then we move the pointers to tis correct position
    left = left->next;
    return true;
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    cout << "Linked list: ";
    printList(head);

    Node* left = head;

    if(checkPalindrome(left, head))
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}
