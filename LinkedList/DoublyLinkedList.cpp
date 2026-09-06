/*
The only difference is that a node have address of next node and previous node
*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*next;
        Node*prev;

};

class DoublyLinkedList
{
    private:
        Node*head;
        Node*tail;
        int size;

    public:
        DoublyLinkedList()
        {
            head = NULL;
            tail = NULL;
            size =0;
        }

        void append(int elem)
        {

            Node *temp = new Node;
            temp->data = elem;

            
            if(head == NULL)
            {
                head = temp;
                tail = temp;
                
                //theere is nothing before and after head and tail in ONE NODE List
                head->prev = NULL;
                head->next = NULL;
                
                tail->next = NULL;
                tail->prev = NULL;

                size++;
            }
            else{
                //since this temp is the new tail 

                temp->prev = tail;
                temp->next = NULL;

                tail->next = temp;
                tail = temp;
                size++;
            }

        }

        void front(int elem)
        {
            Node *temp = new Node;
            temp->data = elem;

            if(head == NULL)
            {
                head = temp;
                tail = temp;

                //theere is nothing before and after head and tail in ONE NODE List
                head->prev = NULL;
                head->next = NULL;
                
                tail->next = NULL;
                tail->prev = NULL;
    
                size++;
                
            }
            else
            {
                //we need to add before our previous head
                head->prev = temp;
                temp->next = head;

                temp->prev = NULL;
                head = temp;
                size++;
            }
        }

        void insert(int elem,int pos)
        {
            if(pos<0 ||pos>size)
            {
                cout<<"Invalid Index Entered..\n";
                return;
            }

            Node*temp = new Node;
            temp->data = elem;
            
            //if to be inserted at the start
            if(pos==0)
            {
                if(head == NULL)
                {
                    head = temp;
                    tail = temp;

                    //theere is nothing before and after head and tail in ONE NODE List
                    head->prev = NULL;
                    head->next = NULL;
                    
                    tail->next = NULL;
                    tail->prev = NULL;
            
                    size++;
                    return;
                }
                temp->next = head;
                temp->prev = NULL;

                head->prev = temp;

                head = temp;
                size++;
            }   
            else
            {
                Node*pre;
                Node*curr = head;

                for(int i =0 ;i<pos;i++)
                {
                    pre = curr;
                    curr = curr->next;
                }

                //if inserting at the end
                if(curr == NULL)
                {
                    temp->prev = pre;
                    temp->next = NULL;

                    pre->next = temp;
                    tail = temp;
                    size++;
                    return;
                }

                //if in the middle
                temp->next = curr;
                temp->prev = pre;
                pre->next = temp;
                curr->prev = temp;

                size++;
            }
            
        }

        void deleteFront()
        {
            if(head == NULL)
            {
                cout<<"List is empty...\n";
                return;
            }

            Node*temp = head;
            if(head == tail)
            {
                delete temp;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }

            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }

        void deleteEnd()
        {
            if(head == NULL)
            {
                cout<<"List is Empty..\n";
                return;
            }

            Node*temp = tail;

            if(head == temp)
            {
                delete temp;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }

            Node*pre = tail->prev;
            pre->next = NULL;
            tail = pre;
            delete temp;
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
                cout<<"Empty List..\n";
                return;
            }

            if(head == tail)
            {
                Node*temp = head;
                delete temp;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }
            
            if(pos==0)
            {   
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
                size--;
                return;

            }
            else{
                Node*pre;
                Node*curr = head;

                for(int i=0;i<pos;i++)
                {
                    pre = curr;
                    curr = curr ->next;

                }
                if(curr == tail)
                {
                    pre->next = NULL;
                    tail = pre;
                    delete curr;
                    size--;
                    return;
                }

                pre->next =curr->next;
                //chaning the next of current's previous 
                curr->next->prev = pre;


                delete curr;
                size--;
            }
        }

        bool search(int elem)
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                if(temp->data == elem)
                {
                    return true;
                }

                temp=temp->next;
            }
            return false;
        }   
        
        void display()
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }

        }

        ~DoublyLinkedList()
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                Node*next = temp->next;
                delete temp;
                temp = next;

            }
        }
};

int main()
{
    DoublyLinkedList list;


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