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

Node* insert(Node*root,int val)
{
    //if we go to the last node
    if(root==NULL){
        return createNode(val); //we create node
    }
    //if lesser node then we recursively go the the left
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }

    return root;
}

int findMax(Node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int findMin(Node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

int main()
{
    Node* root = NULL;
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,50);
    root = insert(root,10);
    root = insert(root,30);

    cout << "Minimum: " << findMin(root) << endl;
    cout << "Maximum: " << findMax(root) << endl;

    delete root;

    return 0;
}