#include <iostream>

class Node {
    public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};


int countNodes(Node* head) {
    if (head == nullptr)
        return 0;

    return 1 + countNodes(head->next);
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);


    int totalNodes = countNodes(head);
    std::cout << "Total number of nodes: " << totalNodes << std::endl;

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}