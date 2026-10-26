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

Node* findParent(Node*root,int key)
{
    //not found and the root goes to the required data node
    if(root==NULL || root->data == key){
        return NULL;
    }
    //if the left of root is the required one the nreturn
    if(root->left != NULL && root->left->data == key)
    {
        return root;
    }
    //if the right of root is the required one then return 
    if(root->right != NULL && root->right->data == key){
        return root;
    }

    //going to left or right
    if(key<root->data){
        return findParent(root->left, key);
    }
    
    return findParent(root->right,key);
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

    int value;
    cout << "Value: ";
    cin >> value;
    {
        Node* parent = findParent(root, value);
            if (parent == NULL)
                 cout << "No parent (root or value absent)";
            else
                cout << "Parent: " << parent->data;
    }
    destroy(root);

    return 0;
}