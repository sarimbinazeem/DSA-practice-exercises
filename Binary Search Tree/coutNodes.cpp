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

int countNodes(Node*root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,50);
    root = insert(root,10);
    root = insert(root,30);

    cout << "Total nodes: " << countNodes(root) << "\n";
    cout << "Leaf nodes: " << countLeaves(root);  
      
    delete root;

    return 0;
}