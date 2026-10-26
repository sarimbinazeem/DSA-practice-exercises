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

Node* findSuccessor(Node*root,int key)
{
    //Minimum of the right subtree
    Node*current = root;
    Node*successor = NULL;
    while(current!= NULL)
    {
        if(key<current->data){
            successor = current;
            current = current->left;

        }
        else{
            current = current->right;
        }
    }
    return successor;
}

Node* findPredecessor(Node*root,int key)
{
    //Maximum of the left subtree
    Node*current = root;
    Node*predecessor = NULL;

    while(current!=NULL)
    {
        if(key>current->data)
        {
            predecessor = current;
            current = current->right;
        }
        else{
            current=current->left;
        }
    }

    return predecessor;
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
         Node* s = findSuccessor(root, value);
        Node* p = findPredecessor(root, value);

         if (s == NULL)
               cout << "No successor\n";
         else
            cout << "Successor: " << s->data << "\n";

         if (p == NULL)
               cout << "No predecessor\n";
        else
             cout << "Predecessor: " << p->data << "\n";
     }
    destroy(root);

    return 0;
}