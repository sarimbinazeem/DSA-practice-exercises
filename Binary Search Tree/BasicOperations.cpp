// Implement a BST class (integer keys, duplicates not allowed) with the following operations:
// 1. insert(key)
// 2. search(key)
// 3. delete(key) : must correctly handle all three cases: leaf, one child, two children (using inorder
// successor).
// 4. findMin() , findMax() , and height()
// 5. inorderSuccessor(key) without using parent pointers
// Analysis: Insert the keys 10, 20, 30, 40, 50, 25 into an empty BST and draw the result. State the
// best-case and worst-case time of each operation and explain what causes the worst case.
#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *right;
        Node *left;
};

class BST
{
    private:
        Node*root;

    public:
        Node*createNode(int key)
        {
            Node*temp = new Node;
            temp->data = key;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }

        Node* insert(Node*root,int key)
        {
            if(root == NULL) return createNode(key);

            if(key>root->data) root->right = insert(root->right,key);
            else if(key < root->data) root->left = insert(root->left,key);

            //we do nothing on duplicate values

            return root;
        }

        Node* search(Node*root, int key)
        {
            //if not found or the root becomes the target value
            if(root == NULL || root->data == key) return root;
            if(key<root->data)
                return search(root->left,key);
            return search(root->right, key);
        }

        Node* findMinNode(Node*root){
            if(root == NULL){
                return NULL;
            }
            //the minimum is at the extreme left of a tree
            while(root->left != NULL){
                root = root->left;
            }

            return root;
        }
        Node* findMaxNode(Node*root){
            if(root == NULL){
                return NULL;
            }
            //the maximum is at the extreme right of a tree
            while(root->right != NULL){
                root = root->right;
            }

            return root;
        }

        Node*deleteNode(Node*root,int key)
        {
            if(root == NULL) return NULL;

            if(key<root->data ){
                root->left = deleteNode(root->left,key);
            }
            else if(key> root->data){
                root->right = deleteNode(root->right,key);
            }
            else
            {
                //we are at the target node
                //check if no children of the node
                if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    return NULL;
                }
                //one child
                else if(root->right == NULL)
                {
                    Node*temp = root->left;
                    delete root;
                    return temp;
                }
                else if(root->left == NULL) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                //successor logic
                Node*successor = findMinNode(root->right);
                root->data = successor->data;
                root->right = deleteNode(root->right,successor->data);
            }
            return root;
        }

        int height(Node*root)
        {
            if(root== NULL)
            {
                return -1;
            }

            int leftH = height(root->left);
            int rightH = height(root->right);
            
            if(leftH > rightH){
                return 1 + leftH;
            }
            return 1 + rightH;
        }

        //display function
        void inorder(Node*root){
            if(root == NULL) return;
            
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        //destroying tree
        void destroy(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
            destroy(root->left);
            destroy(root->right);
            delete root;
        }

    public:
    //public functiosn to use
        BST()
        {
            root = NULL;
        }

        ~BST()
        {
            destroy(root);
        }

        void insert(int key)
        {
            root = insert(root,key);
        }

        bool search(int key)
        {
            return search(root,key);
        }

        void deleteKey(int key)
        {
            root = deleteNode(root,key);
        }

        bool findMin(int &result)
        {
            Node *temp = findMinNode(root);
            if(temp == NULL) return false;

            result = temp->data;
            return true;
            
        }
        bool findMax(int &result)
        {
            Node *temp = findMaxNode(root);
            if(temp == NULL) return false;

            result = temp->data;
            return true;

        }

        int height()
        {
            return height(root);
        }

        bool inorderSuccessor(int key,int &result)
        {
            Node *successor = NULL;
            Node *current = root;

            while(current != NULL && current->data != key)
            {
                if(key < current->data){
                    successor = current;
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }

            //key doesnt exists
            if(current == NULL){
                return false;
            }

            //if it exists then we find from the right subtree (minimum)
            if(current->right != NULL)
            {
                Node*temp = findMinNode(current->right);
                result = temp->data;
                return true;
            }

            //if no right subtree then use the successor previously stored 
            if(successor!=NULL)
            {
                result = successor->data;
                return true;
            }

            return false;
        }

        void display()
        {
            inorder(root);
            cout<<endl;
        }
};

int main()
{
    BST tree;

    tree.insert(60);
    tree.insert(35);
    tree.insert(55);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);

    cout << "Inorder Traversal Of The Tree: ";
    tree.display();

    if (tree.search(55))
    {
        cout << "55 found in the Tree!" << endl;
    }
    else
    {
        cout << "55 not found in the tree!" << endl;
    }

    
    int result;
    if (tree.findMin(result))
    {
        cout << "Minimum: " << result << endl;
    }
    if (tree.findMax(result))
    {
        cout << "Maximum: " << result << endl;
    }

    cout << "Height: " << tree.height() << endl;

    if (tree.inorderSuccessor(30, result))
    {
        cout << "Successor of 30: " << result << endl;
    }
    else
    {
        cout << "No successor exists!" << endl;
    }

    tree.deleteKey(60);

    cout << "After deleting 30: ";
    tree.display();

    return 0;
}