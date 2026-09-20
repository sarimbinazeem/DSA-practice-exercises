// A Hospital emergency room stores patient records in a two-way sequence of connected records. Each record holds:
// Patient ID (integer)
// Severity Score (integer)
// Each record is linked to both the next record and the previous record, allowing nurses to move forward and backward through the queue.
// Due to a system bug, the records are not sorted by severity score. The head doctor wants the patients arranged in ascending order of severity so that the most critical patients appear first. The sorting must be done using Shell Sort by rearranging the links of the doubly linked list (not by copying values into an array).
// Input: NULL ← [ID:101, Sev:50] ⇄ [ID:102, Sev:20] ⇄ [ID:103, Sev:80] ⇄ [ID:104, Sev:10] ⇄ [ID:105, Sev:60] ⇄ [ID:106, Sev:30] → NULL

// Expected Output: NULL ← [ID:104, Sev:10] ⇄ [ID:102, Sev:20] ⇄ [ID:106, Sev:30] ⇄ [ID:101, Sev:50] ⇄ [ID:105, Sev:60] ⇄ [ID:103, Sev:80] → NULL
#include <iostream>
using namespace std;
class Node{
    public:
        int id;
        int severity;
        Node*next;
        Node*prev;

        Node()
        {
            next = nullptr;
            prev = nullptr;
            id = 0;
            severity = 0;
        }
        Node(int i, int s)
        {
            id = i;
            severity = s;
            next= nullptr;
            prev = nullptr;
        }

};

class LinkedList
{
    public:
        Node*head;
        Node*tail;

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void insert(int id,int sev)
        {
            Node*temp = new Node(id,sev);
            if(head == NULL)
            {
                head = temp;
                tail = temp;

                tail->next = NULL;
                head->prev = NULL;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = tail->next;
                tail->next = NULL;
            }
        }


        void display()
        {
            if(head==NULL) return;

            Node*temp = head;
            cout<<"NULL <-> ";
            while(temp!= NULL)
            {
                cout << "[ID:" << temp->id << ", Severity:" << temp->severity << "] <->";
                temp = temp->next;
            }
            cout<<" NULL";
            cout<<endl;
        }

        int getSize()
        {
            int count = 0;

            Node* temp = head;

            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            return count;
        }
        Node*getNode(int pos)
        {
            Node*temp = head;

            for(int i=0;i<pos;i++)
            {
                temp = temp->next;
            }
            return temp;
        }

        void swapNodes(Node*a , Node*b)
        {
            if(a== b) return;

            //b is immediately after a
            if(a== b->next)
            {
                Node*aprev = a->prev;
                Node*bnext = b->next;

                if(aprev != NULL)
                {
                    aprev->next =b;
                }
                else{
                    head = b;
                }

                if(bnext != NULL)
                {   
                    bnext->prev = a;
                }
                else{
                    tail = a;
                }

                b->prev =aprev;
                a->next = bnext;

                a->prev = b;
                b->next = a;
            }
            else if(b== a->next)
            {
                swapNodes(b,a);
            }
            else
            {
                Node *aprev = a->prev;
                Node*bprev = b->prev;
                Node*anext = a->next;
                Node*bnext = b->next;

                if(aprev!=NULL)
                {
                    aprev->next = b;
                }
                else{
                    head = b;
                }
                if(anext != NULL)
                {
                    anext->prev = b;
                }
                else
                {
                    tail = b;
                }

                if(bprev != NULL)
                {
                    bprev->next = a;
                }
                else
                {
                    head =a;  
                }
                if(bnext !=NULL)
                {
                    bnext->prev = a;
                }
                else{
                    tail = a; 
                }

                a->prev = bprev;
                a->next = bnext;
                b->prev = aprev;
                b->next = anext;
            }

        }

        void shellSort()
        {
            int size = getSize();

            for(int gap=size/2; gap>0 ; gap/=2)
            {
                for(int i =gap ; i<size ; i++)
                {
                    Node*temp = getNode(i);
                    int j=i;
                    while(j>=gap)
                    {
                        Node*curr = getNode(j);
                        Node*prev = getNode(j-gap);
                        
                        if(prev->severity <= curr->severity)
                        {
                            break;
                        }

                        swapNodes(curr,prev);
                        j = j-gap;

                    }
                }
            }
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
            head = tail = nullptr;
        }

};



int main()
{
    LinkedList list;

    list.insert(101, 50);
    list.insert(102, 20);
    list.insert(103, 80);
    list.insert(104, 10);
    list.insert(105, 60);
    list.insert(106, 30);

    cout << "Original List:" << endl;
    list.display();

    list.shellSort();

    cout << "\nSorted List:" << endl;
    list.display();

    return 0;
}