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
        
        void combSort()
        {
            int size = getLenght();
            int gap = size;

            float shrink = 1.3;
            bool swapped = true;

            //when it stopes swapping (swapped= false) then break
            while(swapped == true || gap != 1)
            {
                //if the gap shrinks to less than 1, we make it 1 as a flag that the loop should break.
                gap = ((gap/shrink) <1.0) ? 1 : gap/shrink;
                swapped = false;
                //then we apply normal bubble sorting
                //THe boundary is to control out of bound errors
                for(int i=0 ; i<size-gap;i++)
                {
                    if(getData(i) > getData(i+gap))
                    {
                        Node* nodeI = getNode(i);
                        Node* nodeGap = getNode(i+gap);

                        int temp = nodeGap->data;
                        nodeGap->data = nodeI->data;
                        nodeI->data = temp;

                        swapped = true;
                    }

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

	list.combSort();
	    
    cout<<"\n===After Sorting===\n";
    list.display();
    cout<<endl;
}