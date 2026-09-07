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
            else
            {
            	cout<<"Invalid Index..\n";
            	return 0;
            	
			}
        }
        
        void shellShort()
        {
            int size = getLenght();

            for(int gap = size/2; gap>0 ; gap/=2)
            {
                for(int i=gap; i<size;i++)
                {
                    int key = getData(i);

                    int j=i;

                    while(j>=gap && getData(j-gap)> key)
                    {
                        //insert starting element in the place of gap element
                        Node* nodeJ = getNode(j);
                        Node* nodeGap = getNode(j-gap);

                        nodeJ->data = nodeGap->data;
                        j = j-gap;
                    }

                    //replace the starting elements with the key 

                    Node* nodeGap = getNode(j);
                    nodeGap->data = key;
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

	list.shellShort();
	    
    cout<<"\n===After Sorting===\n";
    list.display();
    cout<<endl;
}