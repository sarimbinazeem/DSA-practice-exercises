/*
Lowest Common Ancestor

the common (lowest number) parent/ancestor of a child node
*/

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

Node* LCA(Node*root,int a, int b)
{
    if(root == NULL) return NULL;

    //if both childs are lesser then its in left
    if(a<root->data && b<root->data){
        return LCA(root->left,a,b);
    }
    else if (a>root->data && b>root->data){
        return LCA(root->right,a,b);
    }

    return root;
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

    int a,b;
    cout << "Enter two values: ";
    cin >> a;
    cin>>b;
     Node* lca = LCA(root, a, b);
        if (lca != NULL)
            cout << "LCA: " << lca->data;

    destroy(root);

    return 0;
}