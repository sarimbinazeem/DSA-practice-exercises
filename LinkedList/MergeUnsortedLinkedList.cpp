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

        void merge(LinkedList &l2 )
        {
            if(l2.head == NULL)
            {
                return;
 
               }

            if(head == NULL)
            {
                return;
            }

            Node*temp = head;

            //until  last character
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = l2.head;


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

    LinkedList list2;

    list2.append(813);
    list2.append(21);
    list2.append(33);
    list2.append(48);
    list2.append(5);
    
    list.display();
    cout<<endl;
    list.merge();

    list.display();
}
