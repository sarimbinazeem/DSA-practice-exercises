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

void inOrder(Node*root)
{

    //left -> root -> right
    if(root==NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node*root)
{

    //left -> right -> root
    if(root==NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(Node*root)
{

    //root -> left -> right
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);

    cout << "Inorder traversal: ";
    inOrder(root);

    cout << endl;

    cout << "PostOrder traversal: ";
    postOrder(root);

    cout << endl;

    cout << "PreOrder traversal: ";
    preOrder(root);

    cout << endl;

    destroy(root);

    return 0;
}