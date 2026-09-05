#include <iostream>
using namespace std;

//Node Class that contains two attributes in it (data of itself and address of next node)
class Node
{
    public:
        int data;
        Node*next;
};

class LinkedList
{
    private:
        //Each linked List have head (starting element) and tail (last element)
        Node*head;
        Node*tail;
        int size;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        //Inserting a node at the end
        void append(int elem)
        {
            //Create a new temporary node that is to be added to the end
            Node*temp = new Node; //Allocating new memory for new node
            temp->data = elem;
            temp->next = NULL; //Since this temp is now a tail, therefore its next node is NULL

            

            //If this is the first node
            if(head==NULL)
            {
                head = temp;
                tail = temp;
                size++;
            }
            else
            {
                //If it is not the first then make this node, TAIL of linked list
                tail->next = temp;  //the next of previous tail is now the new tail
                tail = temp; // replace tail with new node
                size++;
            }

        }

        //Inserting at beginning
        void front(int elem)
        {
            //Create temporary node that is to be added to the front
            Node*temp = new Node;
            temp->data = elem;
            temp->next = NULL; //for safety if there is no node at first

            if(head == NULL)
            {
                head = temp;
                tail = temp;
                size++;
            }

            else{
                //next of front is the previous head
                temp->next = head;
    
                //make temp the new head
                head = temp;
                size++;
            }
            
        }

        void insert(int elem,int idx)
        {
            //index boundary check
            if(idx>= size || idx <0 )
            {
                cout<<"Invalid Index...\n";
                return;
            }
            //Temporary node to be added
            Node*temp = new Node;
            temp->data = elem;

            //To go towards the position 

            //We keep track of current and previous nodes 
            Node*curr;
            Node*pre;

            //currently we stand at head
            curr = head;

            //We move one by one till the position
            for(int i=0;i<idx;i++)
            {
                //current becomes previous
                pre = curr;
                //current becomes next of current
                curr = curr->next;
            }

            if(idx==0)
            {
                //if the index is at the start, there is no previous
                temp->next = head;
                head = temp;

                //if the list was empty
                if(tail==NULL)
                {
                    tail = temp;
                }
                size++;
            }
            else
            {
                //When we reach the position we need to insert between current and previous
                //the next of temp becomes current node
                temp->next = curr;
    
                pre->next = temp;

                //If the node is inserted at the end we should change the tail 
                //the current becomes NULL if we are at the end of the list
                if(curr==NULL)
                {
                    //new tail assigned
                    tail = temp;
                }
                size++;
            }
            
        }

        //Searching and returning true or false
        bool search(int elem)
        {
            //creating temproray node to traverse through linked list   
            Node*t = head;

            //go till tail
            while(t != NULL)
            {
                if(t->data == elem)
                {
                    return true;

                }
                else{
                    //move to next
                    t = t->next;
                }
            }

            //didnt find
            return false;
        }

        //Display
        void display()
        {
            //Creating temporary node to traverse through linked list
            Node*t = head;

            //go till tails 
            while(t != NULL)
            {
                cout<< t->data << " ";
                t = t->next;
            }
        }

        //delete front node
        void deleteFront()
        {   
            if(head == NULL)
            {
                cout<<"List is Empty...\n";
                return;
            }
            //Temporary node to keep track of current front node
            Node*temp = head;

            //change head to next node
            head = head->next;

            //if it was a one-node list (Tail and head were the same)
            if(head == NULL)
            {
                //delete tail aswell
                tail = nullptr;
            }

            //delete the front element
            delete temp;
            size--;
        }

        //delete at positon
        void deleteAt(int idx)
        {
            if(head == NULL)
            {
                cout<<"List is Empty...\n";
                return;
            }

            if(idx >=size || idx<0)
            {
                cout<<"Invalid Index...\n";
                return;
            }
            //Create nodes to keep track of current and previous nodes
            Node*curr;
            Node*pre;

            //start from head and go till the position
            curr = head;
            for(int i=0;i<idx;i++)
            {
                pre = curr;
                curr = curr->next;
            }

            if(idx==0)
            {
                //if someone wants to delete at front
                head = head->next;

                //if it was a one-node list (Tail and head were the same)
                if(head == NULL)
                {
                    //delete tail aswell
                    tail = nullptr;
                }

                delete curr;
                size--;
            }

            else{
                //we need to delete the node between previous and current node
                //So we put next of current inside next of previous so it jumps one node that is to be deleted
                 pre->next = curr->next;

                 //if the node to be deleted is a tail, we assign previous node as tail
                 if(curr == tail){
                    tail = pre;
                 }
    
                 //delete the node
                 delete curr;
                 size--;

            }
        }


        //delete at end
        void deleteEnd()
        {
            //Empty List
            if(head == NULL)
            {
                cout<<"\nList is empty....\n";
                return;
            } 

            //Single node list
            if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
                size--;
                return;
            }


            //Create node to keep track of tail
            Node* temp = tail;
            Node* curr = head;

            //Create node to keep track of previous
            Node* pre;

            //we go to the node that is before tail
            while(curr->next != NULL)
            {
                pre = curr;
                curr = curr->next;
            }

            //curr now points to tail
            // Pre now points to second last node
            //We need to delete the tail and replace it with the previous node of tail
            pre->next = NULL;
            tail = pre;
            //delete tail
            delete temp;

           
            size--;
        }

        ~LinkedList()
        {
            Node*temp = head;

            while(temp!=NULL)
            {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
        }
};

int main()
{
    LinkedList list;


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