#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*next;
};

class CircularLL
{
    private:
        Node*head;
        Node*tail;

    public:
        CircularLL()
        {
            head = nullptr;
            tail = nullptr;
        }

        void append(int elem)
        {
            Node*temp = new Node;
            temp->data = elem;
            temp->next = head;

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
                tail->next = head;

            }
        }

        void display()
        {
            Node*temp = head;

            do
            {
                cout<< temp->data <<" ";
                temp = temp->next;
            }while(temp!=head);

            cout<< endl;
        }

        int getLenght()
        {
            int size =0;
            Node*temp = head;
            do
            {
                size++; 
                temp= temp->next;
            }while(temp!=head);

            return size;
        }

        ~CircularLL()
        {
            if (head == NULL) return;

            tail->next = NULL;

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

        int getData(int pos)
        {
            int size = getLenght();

            if(pos>=0 && pos<size)
            {
                Node*temp = head;
                for(int i=0;i<pos;i++)
                {
                    temp = temp->next;
                }

                return temp->data;
            }
        }
        
        void insertionSort()
        {
            int size = getLenght();

            for(int i=1;i<size;i++)
            {
                Node * temp = getNode(i);
                int key =  temp->data;
                int j=i-1;

                while(j>=0 && key < getData(j))
                {
                    //Move the correct element to the right
                    Node*nodeJ = getNode(j);
                    nodeJ->next->data = nodeJ->data;
                    j--;
                }

                //insert the key at the left (its correc positon)
                Node*nodeJ = getNode(j+1);
                nodeJ->data = key;

            }

        }

};

int main()
{
    CircularLL list;

    list.append(20);
    list.append(10);
    list.append(30);
    list.append(70);
    list.append(3);
    list.append(1);

    cout<<"\n===Before Sorting===\n";
    list.display();

    cout<<endl;

	list.insertionSort();
	    
    cout<<"\n===After Sorting===\n";
    list.display();
    cout<<endl;
}