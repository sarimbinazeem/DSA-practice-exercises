/*A delivery routing system stores stops as a looping sequence of connected records, where each record is linked to the next record. Due to a software bug, the last stop (6th stop) accidentally points back to the 3rd stop instead of pointing to NULL, creating an infinite loop in the route. The system must detect this loop and break it so the route becomes a proper one-way sequence that terminates correctly at the last stop.
find the starting point of the loop, and remove the loop so the sequence becomes a proper one-way sequence ending with Null.
Input  [1] → [2] → [3] → [4] → [5] → [6]
                              ↑                   
                              └───────────┘
        (6th record points back to 3rd record)

Expected Output:  [1] → [2] → [3] → [4] → [5] → [6] → NULL
*/

#include <iostream>
using namespace std;


class Node{
    public:
        Node*next;
        int data;

        Node()
        {
            next = nullptr;
            data = 0;
        }
        Node(int d)
        {
            data = d;
            next= nullptr;
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

        void insert(int elem)
        {
            Node*temp = new Node(elem);
            if(head == NULL)
            {
                head = temp;
                tail = temp;

                tail->next = NULL;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        void display()
        {
            if(head==NULL) return;

            Node*temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }

            cout<<" NULL";
            cout<<endl;
        }
        
        void detectandRemove()
        {
            Node*slow = head;
            Node*fast = head;
            while(fast!=NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;

                //if there is a cycle then slow==fast
                if(slow==fast)
                {
                    cout<<"Loop detected! \n";

                    slow = head;
                    //we find the starting point where the loop starts
                    //we start slow from head and loop until fast == slow
                    while(slow!= fast)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }

                    Node* start = slow;

                    cout<<"Loop Starts from: "<<start->data <<endl;

                    Node*temp = start;
                    //we loop until the end of the cycle
                    while(temp->next != start)
                    {
                        temp = temp->next;
                    }
                    temp->next = NULL;
                    tail = temp;
                    return;
                }
            }
            cout << "No loop found." << endl;
        }
        ~LinkedList()
        {
            Node* temp = head;

            while(temp != NULL)
            {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }

            head = tail = nullptr;
        }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    // Create loop:
    // 6 -> 3
    Node* node3 = list.head->next->next;
    Node* node6 = list.head->next->next->next->next->next;

    node6->next = node3;

    list.detectandRemove();

    cout << "After removing loop:" << endl;
    list.display();

    return 0;
}