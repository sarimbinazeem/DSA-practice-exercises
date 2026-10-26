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

int height(Node*root)
{
    if(root==NULL){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight>rightHeight){
        return leftHeight +1;
    }
    return rightHeight +1;
    
}

//find a depth till a certain node from root
int depth(Node*root,int key,int dep = 0)
{
    //not found
    if(root==NULL){
        return -1;
    }
    if(root->data == key){
        return dep;
    }

    if(key<root->data){
        return depth(root->left,key,dep+1);
    }

    return depth(root->right,key,dep+1);
    
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
    cout << "Depth: " << depth(root, value)<<endl;
    cout << "Height: " << height(root);
    destroy(root);

    return 0;
}