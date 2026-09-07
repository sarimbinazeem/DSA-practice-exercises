#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*next;
};

class LinkedList
{
    private:
        Node*head;
        Node*tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void append(int elem)
        {
            Node*temp = new Node;
            temp->data = elem;
            temp->next = NULL;

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;

            }
        }

        void display()
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                cout<< temp->data <<" ";
                temp = temp->next;
            }

            cout<< endl;
        }

        int getLenght()
        {
            int size =0;
            Node*temp = head;
            while(temp != NULL)
            {
                size++; 
                temp= temp->next;
            }

            return size;
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
            tail = nullptr;
        }

        Node* getNode(int pos)
        {
            int size = getLenght();

            if(pos>=0 && pos<size)
            {
                Node*temp = head;
               for(int i=0; i<pos; i++)
                {
                    temp = temp->next;
                }

                return temp;
            }
            else
            {
            	cout<<"Invalid Index";
            	return nullptr;
			}

        }
        void selectionSort()
        {
            int size = getLenght();

            for(int i=0 ;i<size-1;i++)
            {
                int minIndex = i;

                for(int j=i+1;j<size;j++)
                {
                    Node* nodeA = getNode(minIndex);
                    Node* nodeB = getNode(j);
                    if(nodeA->data > nodeB->data)
                    {
                        minIndex = j;

                    }

                }

                if(minIndex != i)
                {
                    Node* nodeA = getNode(minIndex);
                    Node* nodeB = getNode(i);
                    int temp = nodeA->data;
                    nodeA->data = nodeB->data;
                    nodeB->data = temp;

                }
                
            }

        }

};

int main()
{
    LinkedList list;

    list.append(20);
    list.append(10);
    list.append(30);
    list.append(70);
    list.append(3);
    list.append(1);

    cout<<"\n===Before Sorting===\n";
    list.display();

    cout<<endl;

	list.selectionSort();
	    
    cout<<"\n===After Sorting===\n";
    list.display();
    cout<<endl;
}