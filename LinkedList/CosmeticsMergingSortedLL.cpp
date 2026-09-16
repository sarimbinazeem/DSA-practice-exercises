/*Question 05:
A beauty company operates two branches, GlowCare and BeautyHub, and each branch
maintains its own Singly Linked List of beauty products. Each product node contains a Product
ID, Product Name, Category, Price, and pointer to the next node. The products in each
branch are maintained in ascending order of Product ID.
At the end of the month, the company wants to combine the product records of both branches
into a single master product list. Write a C++ program that dynamically creates the two Singly
Linked Lists and allows the user to add products to each list while maintaining the ascending
order of Product ID. The program must traverse and display both branch lists before merging,
then merge the two lists into a single sorted master list by correctly adjusting the existing next
pointers. The merged list must not contain duplicate Product IDs; if the same Product ID exists
in both lists, retain the product with the lower price and discard the other node. Finally, traverse
and display the complete master list and display the total number of products and the total
inventory value of the remaining products. The program must perform the operations using
linked-list pointers only and must not use arrays, STL lists, sort(), or any built-in merge function.
Your task is to design and implement the required Singly Linked List operations in C++. */ 

#include <iostream>
#include <string>
using namespace std;

class Product
{
    public:
        int id;
        string name;
        string category;
        double price;
        Product*next;

        Product(int i, string n , string c , double p)
        {
            id = i;
            name = n;
            category = c;
            price = p;
            next = nullptr;
        }
};

class LinkedList
{
    
    public:
    Product*head;
    Product*tail;

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void insert(Product*node)
        {
            if(head == NULL)
            {
                head = node;
                tail = node;
                tail->next = NULL;
                return;
            }

            Product*temp = head;
            Product*prev = temp;
            while(temp != NULL)
            {
                    // Duplicate ID
                    if(temp->id == node->id)
                    {
                        // New node is cheaper
                        if(node->price < temp->price)
                        {
                            node->next = temp->next;

                            if(temp == head)
                            {
                                head = node;
                            }
                            else
                            {
                                prev->next = node;
                            }

                            if(temp == tail)
                            {
                                tail = node;
                            }

                            delete temp;
                        }
                        else
                        {
                            // Existing node is cheaper
                            delete node;
                        }

                        return;
                    }
                
                //compare it with the node if it is lesser, then add it to it's left
                if(node->id < temp->id)
                {
                    if(head == tail)
                    {
                        node->next = head;
                        head = node;
                        return;                        

                    }
                    
                    //in case of multiple nodes
                    node->next = temp;
                    prev->next = node;

                    return;

                }
                
                else
                {
                    if(head==tail)
                    {
                        tail->next = node;
                        tail = node;
                        tail->next = NULL;
                        return;
                    }

                    else
                    {

                        if(temp == tail)
                        {
                            tail->next = node;
                            tail = node;
                            tail->next = NULL;
                            return;
                        }

                        prev= temp;
                        temp = temp->next;
                        
                    }

                }

            }

        }

        void display()
        {
            Product*temp=head;

            while(temp!=NULL)
            {
                cout<<"(ID: "<<temp->id<<" ,Name: "<<temp->name<<" ,Category: "<<temp->category<<" , Price: "<<temp->price<<" ) -> ";
                temp = temp->next;
            }

            cout<<" NULL\n";
            
        }

    
};

void input(LinkedList *l, int size)
{
   int id;
    string name, category;
    double price;

    for(int i =0 ; i<size ; i++)
    {
        cout<<"\n=== Product "<<i+1<<" ===\n";
        cout<<"Enter Proudct Id: ";
        cin>>id;
        cin.ignore();
        
        cout<<"Enter Product Name: ";
        getline(cin,name);

        cout<<"Enter Product Category: ";
        getline(cin,category);

  
        cout<<"Enter Product Price: ";
        cin>>price;
        
        l->insert(new Product(id,name,category,price));
    }
}

Product* merge(LinkedList *l1, LinkedList *l2 )
{
    //we make a node to attach after sorting every nodes
    Product dummy(0,"","",0);
    Product*tail = &dummy; 

    //save head nodes 
    Product* head1 = l1->head;
    Product*head2 = l2->head;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->id < head2->id)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else if(head2->id < head1->id)
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        else if(head2->id == head1->id)
        {
            //we check which have lower price
            if(head1->price <= head2->price)
            {
                tail->next = head1;
                tail  = tail->next;
                head1 = head1->next;
                
                Product* toDelete = head2;
                head2= head2->next;
                delete toDelete;
            }
            else
            {
                tail->next = head2;
                tail  = tail->next;
                //we need to discard the other one
                Product* toDelete = head1;
                head1 = head1->next;
                head2= head2->next;
                delete toDelete;
            }
        }
    }

    //fill the remaining nodes
    if(head1 != nullptr)
    {
      tail->next = head1;

    }
    else {
        tail->next = head2;
    }


    tail->next =NULL;
    return dummy.next;
}

void display(Product* head)
{
    Product*temp = head;
    while (temp!=NULL)
    {
        cout<<"(ID: "<<temp->id<<" ,Name: "<<temp->name<<" ,Category: "<<temp->category<<" , Price: "<<temp->price<<" ) -> ";
        temp = temp->next;    
    }
    cout<<" NULL\n";
    
}

int count(Product*head)
{
    int total = 0;

    Product* temp = head;

    while(temp != NULL)
    {
        total++;
        temp = temp->next;
    }

    return total;
}

double inventory(Product* head)
{
    double total = 0;

    Product* temp = head;

    while(temp != NULL)
    {
        total += temp->price;
        temp = temp->next;
    }

    return total;
}

int main()
{
    LinkedList GlowCare;
    LinkedList BeautyHub;
    
    int size;

    cout<<"Enter Number Of GlowCare Products: ";
    cin>>size;

    input(&GlowCare,size);
    
    cout<<endl;

    cout<<"Enter Number Of BeautyHub Products: ";
    cin>>size;

    input(&BeautyHub,size); 
 
    cout<<"\n===GlowCare Products===\n";
    GlowCare.display();
 
    cout<<"\n===Beauty Hub Products===\n";
    BeautyHub.display();

    cout<<"\n===Merging List===\n";
    Product* merged = merge(&GlowCare,&BeautyHub);

    //Since original list dont own the nodes in the merged list
    GlowCare.head = NULL;
    GlowCare.tail = NULL;

    BeautyHub.head = NULL;
    BeautyHub.tail = NULL;

    cout<<"\n===Master Sorted List===\n";
    display(merged);

    cout<<"Total Products: "<<count(merged)<<endl;
    cout<<"Total Inventory Value: "<<inventory(merged)<<endl;



}