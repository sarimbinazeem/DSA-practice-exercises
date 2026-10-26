

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

void kthHelper(Node*root,int k , int &count, int &answer)
{
    if(root == NULL || count >= k){
        return;
    }

    //going to left subtree
    kthHelper(root->left,k,count,answer);

    count++;
    if(count == k)
    {
        answer = root->data;
        return;
    }

    kthHelper(root->right,k,count,answer);
}

void kthSmallest(Node*root,int k)
{
    int count = 0;
    int answer = -1;
    kthHelper(root,k,count,answer);
    cout<<"Smallest: "<<answer<<endl;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    if (k > 0)
          kthSmallest(root, k);

    destroy(root);

    return 0;
}