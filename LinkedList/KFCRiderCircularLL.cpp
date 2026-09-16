#include <iostream>
using namespace std;

//RiderNode
class Rider{
    public:
        int id;
        string name;
        int orders;
        Rider* next;

        Rider(int id, string n, int o)
        {
            this->id = id;
            name = n;
            orders = o;
            next = NULL;
        }
};

class RidersList{
    private:
        Rider*head;
        Rider*tail;

    public:
        RidersList(){
            head = nullptr;
            tail = nullptr;
        }

        void insertEnd(Rider* node)
        {
            //empty list
            if(head == NULL)
            {
                head = node;
                tail = node;
                
                tail->next = head;
            }
            else{
                //if it isnt an empty list
                tail->next = node;
                tail = node;
                tail->next = head;
            }
        }

        void insertBeginning(Rider*node)
        {
            //empty list
            if(head == NULL)
            {
                head = node;
                tail = node;
                tail->next = head;
            }
            else{
                node->next = head;
                head = node;
                tail->next = head;
            }
        }

        //count function
        int getLenght()
        {
            if(head == NULL) return 0;
            int size =0;
            Rider*temp = head;
            do
            {
                size++;
                temp = temp->next;
            }while(temp != head);
            return size;
        }

        void insertAt(int pos, Rider*node)
        {
            //empty list
            if(head == NULL)
            {
                head = node;
                tail = node;
                tail->next = head;
                return;
            }

            //boundary check
            int size = getLenght();
            while(pos>=size || pos<0)
            {
                cout<<"Invalid Position! Enter Valid Position (0 to "<<size-1<<" ): ";
                cin>>pos;
            }

            //insert beginning
            if(pos == 0)
            {
                insertBeginning(node);
                return;
            }
            else if(pos== size)
            {
                insertEnd(node);
                return;
            }
            else{
                //somewhere in the list
                Rider*pre = head;
                
                
                //for inserting AT we go one position behind
                for(int i=0;i<pos-1; i++)
                {
                    pre = pre->next;
                    
                }

                node->next = pre->next;
                pre->next = node;

            }   

        }

        void deleteBeginning()
        {
            if(head == NULL){
                cout<<"List is Empty..\n";
                return;
            }

            //if single node
            if(head == tail)
            {
                Rider*temp = head;
                head = nullptr;
                tail = nullptr;
                delete temp;
                return;
            }

            Rider*temp = head;
            head = head->next;
            delete temp;
            tail->next = head;
        }

        void deleteEnd()
        {
            if(head == NULL)
            {
                cout<<"List is Empty...\n";
                return;
            }

            //single node
            if(head == tail)
            {
                Rider*temp = head;
                head = nullptr;
                tail = nullptr;
                delete temp;
                return;
            }

            Rider *temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }

            Rider*t = tail;
            tail = temp;
            tail->next = head;
            delete t;
        }

        void deleteAt(int pos)
        {
            if(head == NULL)
            {
                cout<<"List is Empty..\n";
                return;
            }
            int size = getLenght();
            
            while(pos>=size || pos<0)
            {
                cout<<"Invalid! Enter Correct Position (0 to "<<size-1<<" ): ";
                cin>>pos;
            }

            if(pos==0)
            {
                deleteBeginning();
                return;
            }
            if(pos == size-1)
            {
                deleteEnd();
                return;
            }

            Rider*pre=head;
            

            for(int i=0;i<pos-1;i++)
            {
                pre = pre->next;
               
            }

            Rider*curr = pre->next;

            pre->next = curr->next;

            delete curr;

        }

        //Search by Id
        void search(int id)
        {
            if(head == NULL)
            {
                cout<<"List is Empty..";
                return;
            }

            Rider*temp = head;
            do{
                if(temp->id == id)
                {
                    cout<<"Rider Found with: "<<endl;
                    cout<<"ID: "<<id<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Orders: "<<temp->orders;
                    return;
                }
                temp = temp->next;
            }while(temp!=head);

            cout<<"Rider with ID "<<id<<" not found.\n";
        }
        
        //Update by ID
        void update(int id, string name, int orders )
        {
            if(head == NULL)
            {
                cout<<"List is Empty..";
                return;
            }
        
            Rider*temp = head;
            do{
                if(temp->id == id)
                {
                    temp->name = name;
                    temp->orders = orders;
                    cout<<"Updated Rider Information...\n "<<endl;
                    return;
                }
                temp = temp->next;
            }while(temp!=head);
        
            cout<<"Rider with ID "<<id<<" not found.\n";

        }

        void display()
        {
            if(head == NULL){
                cout<<"List is empty..\n";
                return;
            }

            Rider*temp = head;
            do
            {
                cout<<"ID: "<<temp->id<<endl;
                cout<<"Name: "<<temp->name<<endl;
                cout<<"Assigned Orders: "<<temp->orders<<endl;
                
                temp = temp->next;
            }while(temp!=head);


        }
        
        void traverseFrom(int id)
        {
            if(head == NULL) {
                cout<<"List is Empty..\n";
                return;
            }

            int size = getLenght();

            Rider *selected = head;
            //find the selected rider
            do
            {
                if(selected->id == id)
                {
                    break;
                }
                selected = selected->next;
            } while (selected != head);
            
            if(selected->id != id)
            {
                cout<<"Rider Not Found! \n";
                return;
            }

            Rider *temp = selected;
            do
            {
                cout<<temp->id<<" -> ";

                
                temp = temp->next;
            }while(temp!=selected);
            cout<<" (back to the selected rider ) "<<selected->id<<endl;
        }

        ~RidersList()
        {
            if(head == NULL) return;
            //break cycle
            tail->next = NULL;
            Rider*temp = head;

            while(temp != NULL)
            {
                Rider*next = temp->next;
                delete temp;
                temp = next;
            }

            head = nullptr;
            tail = nullptr;
        }
};

int main()
{
    RidersList KFC;

    Rider r1(101,"Sarim",2);
    Rider r2(102,"kamran",200);
    Rider r3(103,"Yahya",1000);
    Rider r4(104,"Ahmed",60);

    cout<<"\n===Inserting At End===\n";
    KFC.insertEnd(new Rider(101,"Sarim",2));
    
    cout<<"\n===Inserting at beginning===\n";
    KFC.insertBeginning(new Rider(102,"kamran",200));
    
    cout<<"\n====Riders===\n";
    KFC.display();
    
    cout<<"\n===Inserting at 2nd and 1st Position===\n";
    KFC.insertAt(2, new Rider(103,"Yahya",1000));
    KFC.insertAt(1,new Rider(104,"Ahmed",60));
    
    cout<<"\n====Riders===\n";
    KFC.display();
    
    cout<<"\n===Updating at Id 102===\n";
    KFC.update(102,"farhan",600);

    
    cout<<"\n====Riders===\n";
    KFC.display();

    cout<<"\n===Searching for ID 104===\n";
    KFC.search(104);

    cout<<"\n===Riders===\n";
    KFC.display();
    
    cout<<"\n===Traversing From ID 102====\n";
    KFC.traverseFrom(102);

    cout<<"\n===Deleting at Index 2===\n";
    KFC.deleteAt(2);

    cout<<"\n===Riders===\n";
    KFC.display();

    cout<<"\n===Deleting at End===\n";
    KFC.deleteEnd();

    cout<<"\n===Riders===\n";
    KFC.display();
    
    cout<<"\n===Deleting at Beginning===\n";
    KFC.deleteBeginning();
    
        cout<<"\n===Riders===\n";
        KFC.display();

    


}