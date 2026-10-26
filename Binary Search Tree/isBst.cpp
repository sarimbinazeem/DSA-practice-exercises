#include <iostream>
#include <climits>
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

bool isBST(Node*root, long long minValue, long long maxValue)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data <= minValue || root->data >= maxValue)
    {
        return false;
    }

    //min to mid and then mid to max
    return isBST(root->left,minValue,root->data) && isBST(root->right,root->data,maxValue);

}


void destroy(Node*root){
    if(root == NULL)
    {
        return;
    }

    //we destrroy left and right subtree
    destroy(root->left);
    destroy(root->right);

    delete root;
}

int main()
{
    Node* root = NULL;
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,50);
    root = insert(root,10);
    root = insert(root,30);

    cout << (isBST(root, LLONG_MIN, LLONG_MAX) ? "Valid BST" : "Invalid BST");
    destroy(root);

    return 0;
}