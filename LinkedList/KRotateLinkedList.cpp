#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
};

class LinkedList
{
    private:
        Node*head;
        
    public:
        LinkedList()
        {
            head = nullptr;
        }

        void append(int elem)
        {
            Node*temp = new Node;
            temp->data = elem;
            temp->next = NULL;

            if(head == NULL)
            {
                head = temp;
                head->next = NULL;
                return;
            }

            Node*curr = head;

            while(curr->next != NULL)
            {
                curr= curr->next;
            }

            curr->next = temp;
            temp->next = NULL;
        }

        void display()
        {
            Node*temp = head;

            while(temp != NULL)
            {
                cout<< temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void rotate(int k)
        {
            //safet
            if(head == NULL || head->next == NULL)
            {
                return;
            }

            Node*tail = head;
            

            //we go till tail and find the postion of last ndoe
            int size=0;
            while(tail!=NULL)
            {
                tail= tail->next;
                size++;
            }

            //To avoid unecesarry rotation we use %
            //if k =4 , then 4%3 = 1, we can achieve the same goal with 1 rotation as with 4 rotations
            k = k % size;

            if(k==0) return;

            //the node before tail (newhead )
            Node *pre = head;
            for(int i =1 ; i<size -k; i++)
            {
                pre = pre->next;

            }

            Node*newHead = pre->next;

            //breaking the list
            pre->next = NULL;
            //conect old tail with old  head
            tail->next = head;

            head = newHead;
            


        }

        ~LinkedList()
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;
            }

            head = nullptr;
        }
};

int main()
{
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.display();
    cout<<endl;
    list.rotate(2);

    list.display();
}
