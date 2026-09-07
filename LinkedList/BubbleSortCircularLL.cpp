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
                tail->next = head;
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
                temp = temp->next;
            }while(temp!=head);

            return size;
        }

        ~CircularLL()
        {
            if(head == NULL) return;
            //break the cycle first
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
        void bubblesort()
        {
            //check if it is an empty or a one node list
            if(head == nullptr || head->next == nullptr)
            {
                return;
            }

            //calculate size
            int size=getLenght();
            
            //it have n-1 iterations 
            for(int i=0;i<size-1;i++)
            {
          	  bool swapped = false;	
                Node *curr = head;
                //every iteration puts the large element in its correct position
                for(int j=0;j<size-i-1;j++)
                {
                    if(curr->data > curr->next->data)
                    {
                        int temp = curr->data;
                        curr->data = curr->next->data;
                        curr->next->data = temp;
                        swapped = true;
                    }

                    curr = curr->next;

                }
                
                if(!swapped)
                {
                	return;
				}
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

    list.bubblesort();
    
    cout<<"\n===After Sorting===\n";
    list.display();
    cout<<endl;
}