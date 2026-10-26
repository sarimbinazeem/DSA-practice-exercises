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

Node* insertIterative(Node*root,int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root==NULL){
        return newNode;
    }
    
    //somewhere in middle
    Node*current = root;
    Node*parent = NULL;

    while(current!=NULL)
    {
        parent = current;
        if(val < current->data)
        {   
            current = current->left;
        }else if (val>current->data){
            current= current->right;
        }
        else{
            delete newNode;
            return root;
        }
    }

    if(val < parent->data)
    {
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    return root;
}

int main()
{
    Node* root = NULL;
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,50);
    root = insert(root,10);
    root = insert(root,30);

    delete root;

    return 0;
}