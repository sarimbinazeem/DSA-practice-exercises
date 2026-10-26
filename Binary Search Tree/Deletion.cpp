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

Node* deleteNode(Node*root,int key)
{
    if(root== NULL)
    {
        return NULL;
    }

    if(key<root->data)
    {
        root->left = deleteNode(root->left,key);
    }
    else if (key>root->data)
    {
        root->right = deleteNode(root->right,key);
    }
    else{
        //no child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL; //this null connects to prvvious pointers through recuirsion
        }

        //one child
        if(root->left == NULL)
        {
            //swap with right
            Node*temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL)
        {
            //swap with left
            Node*temp = root->left;
            delete root;
            return temp;
        }

        //two child -> successor logic
        Node*successor = root->right;
        while(successor->left != NULL)
        {
            successor = successor->left;
        }
        //swap the sccuessor with root
        root->data = successor->data;

        //now delete the previous spot of successor
        root->right = deleteNode(root->right,successor->data);
    }

    return root; // this 

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
    cout << "Delete value: ";
     cin >> value;
    root = deleteNode(root, value);
    destroy(root);

    return 0;
}