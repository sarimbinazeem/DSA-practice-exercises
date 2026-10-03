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

bool binarySearch(Node*head, int size, int target){
    int low = 0;
    int high = size-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        Node*curr = head;
        for(int i =0 ; i <mid; i++){
            curr = curr->next;
        }

        if(curr->data == target) return true;
        else if(target < curr->data) high = mid-1;
        else low = mid +1;
    }

    return false;
}

int main()
{
    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);

    int size = 7;
    int target;

    cout << "Enter target: ";
    cin >> target;

    if (binarySearch(head, size, target))
        cout << "Target found";
    else
        cout << "Target not found";

    return 0;
}