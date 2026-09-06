/*
The only difference is that the tail points to head address instead of NULL
*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*next;
};

class CircularLinked
{
    private:
        Node*head;
        Node*tail;
        int size;

    public:
        //Default constructor
        CircularLinked()
        {
            head = nullptr;
            tail = nullptr;
            size =0;
        }

        //Append (Insert at end)
        void append(int elem)
        {
            //create node to be inserted
            Node*temp = new Node;
            temp->data = elem;

            if(head==NULL)
            {
                //empty list
                head = temp;
                tail = temp;
                
                tail->next = head;
                size++;
            }
            else{
                //assign new tail
                tail->next = temp;
                tail = temp;

                tail->next = head;
                size++;
            }
        }

        //Insert node at front
        void front(int elem)
        {
            //create a node to be added
            Node*temp = new Node;
            temp->data = elem;

            //empty list
            if(head==NULL)
            {
                head = temp;
                tail = temp;

                tail->next = head;
                size++;
            }
            else{
                //the next of new node becomes current head
                 temp->next = head;

                 //assign new head
                 head = temp;

                 //change the tail->next address to new head
                 tail->next = head;

                 size++;
            }

            
        }

        //Insert at a postiion
        void insert(int elem,int pos)
        {
            //invalid index boundary
            /*
            if there are size 3 of a linked list.
            Insertion at 0th positon means inserting before 0th index
            Insertion at 3rd postion means inserting after 3th index
            */
    
            if(pos>size || pos<0)
            {
                cout<<"Invalid Size...\n\n";
                return;
            }
            //create node to be inserted
            Node*temp = new Node;
            temp->data = elem;

            //previous and current node to keep track
            Node*curr = head;
            Node*pre;
            for(int i=0;i<pos;i++)
            {
                pre = curr;
                curr = curr->next;
            }

            //if to be inserted at start
            if(pos == 0)
            {
                if(head == NULL)
                {
                    head = temp;
                    tail=temp;

                    tail->next = head;
                    size++;
                    return;
                }
                temp->next = head;
                head = temp;

                tail->next = head;
                size++;
            }
            else{
                temp->next = curr;
                pre->next = temp;

                //if we have reached tail
                if(curr == head)
                {
                    tail = temp;
                    tail->next = head;
                }

                size++;
            }
        }

        //delete front
        void deleteFront()
        {
            //empty
            if(head == NULL)
            {
                cout<<"List is empty...\n";
                return;
            }

            //single node list
            if(head == tail)
            {
                //delete the node
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }

            //To delete front we store it in temporary node
            Node*temp = head;
            
            head = head->next;
            tail->next = head;
            delete temp;
            size--;

        }

        //delete at end
        void deleteEnd()
        {
            //empty
            if(head == NULL)
            {
                cout<<"List is empty..\n";
                return;
            }

            //single node
            if(head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }

            Node*curr =head;
            Node*pre;

            //We go til curr becomes the tail and pre becomes the second last node
            while(curr->next != head)
            {
                pre = curr;
                curr = pre->next;

            }

            tail = pre;
            tail->next = head;

            delete curr;
            size--;
        }

        void deleteAt(int pos)
        {
            if(pos<0 || pos>=size)
            {
                cout<<"Invalid Index Entered...\n";
                return;
            }

            if(head == NULL)
            {
                cout<<"List is empty..\n";
                return;
            }

            Node*temp = head;

            //add at front
            if(pos==0)
            {
                if(head == tail)
                {
                    delete temp;
                    head = nullptr;
                    tail = nullptr;
                    size--;
                    return;

                }
                head = head->next;
                tail->next = head;

                delete temp;
                size--;
            }
            else{
                Node*pre;
                Node*curr = head;

                for(int i =0 ; i<pos; i++)
                {
                    pre = curr;
                    curr = curr->next;
                }

                pre->next = curr->next;

                //if tail gets erased
                if(curr==tail)
                {
                    tail = pre;
                    tail->next = head;
                }
                
                delete curr;
                size--;
            }
        }

        void display()
        {
            if (head == NULL)
            {
                cout<<"Empty List...\n";
                return;
            }
            
            
            //start from head
            Node *temp = head;

            //Using do while loop so that we can reach tail node 
            do
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp!=head);

        }

        bool search(int elem)
        {
            if (head == NULL)
            {
                cout<<"Empty List...\n";
                return false;
            }
            Node*temp = head;

            do
            {
                if(temp->data == elem)
                {
                    return true;
                }

                temp = temp->next;
            }while(temp->next != head);

            return false;
        }

        ~CircularLinked()
        {
            //If already empty
            if(head == NULL)
            {
                return;
            }

            //we break the cycle of the linked lsit then delete all the nodes
            tail->next = NULL;
            Node *temp = head;

            while(temp != NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;

            }

            head = nullptr;
            tail = nullptr;
            size=0;
        }
};

int main()
{
    CircularLinked list;


    cout<<"\n===Adding Nodes===\n";
    list.append(5);
    list.append(65);
    
    cout<<"\n===Linked List===\n";
    list.display();
    
	
	cout<<endl;
	
    cout<<"\n===Inserting Nodes at front===\n";
    list.front(10);
    list.front(687);

    cout<<"\n===Linked List===\n";
    list.display();
	
	cout<<endl;
	

    cout<<"\n===Inserting Node at 3rd===\n";
    list.insert(60,3);

    cout<<"\n===Linked List===\n";
    list.display();
	
	cout<<endl;
	

    cout<<"\n===Searching for 60===\n";
    bool flag = list.search(60);
    cout<<"60 exists: "<< ((flag)? "Yes": "No" )<<endl;

	
	cout<<endl;
	
    cout<<"\n===Delete Node at front===\n";
    list.deleteFront();

    cout<<"\n===Linked List===\n";
    list.display();
	
	cout<<endl;
	

    cout<<"\n===Delete Node at End===\n";
    list.deleteEnd();

    cout<<"\n===Linked List===\n";
    list.display();
	
	cout<<endl;
	
    cout<<"\n===Delete Node at 2nd ===\n";
    list.deleteAt(2);

    cout<<"\n===Linked List===\n";
    list.display();


}