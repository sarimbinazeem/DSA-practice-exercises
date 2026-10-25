#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*left;
        Node*right;
};

Node* createNode(int val)
{
    Node *temp = new Node;

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int main()
{
    Node* root = createNode(50);
    Node*temp;
    
    temp = createNode(30);
    root->left = temp;
    temp= createNode(70);
    root->right = temp;


    cout << "Root data: " << root->data << endl;
    cout << "Left child: " << root->left->data << endl;
    cout << "Right child: " << root->right->data << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}