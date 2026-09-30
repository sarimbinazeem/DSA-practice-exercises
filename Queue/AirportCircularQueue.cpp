// An airport boarding gate has limited space for passengers waiting to board an aircraft. The
// passengers are managed according to their arrival order, where the passenger who arrives
// first is boarded first. The gate has a capacity of six passengers and uses a circular queue to
// efficiently reuse the positions that become available after passengers are boarded. Initially,
// passengers with IDs 101, 102, 103, 104, 105, and 106 enter the boarding queue. The first three
// passengers are then boarded, after which passengers 107, 108, and 109 arrive at the gate. The
// boarding process continues with two more passengers being boarded, followed by the arrival
// of passenger 110. One more passenger is then boarded, after which passengers 111 and 112
// arrive. Implement this scenario using an array-based circular queue and display the final
// passengers in their actual boarding order along with the final front and rear positions.

#include <iostream>
using namespace std;

const int SIZE = 6;

class CircularQueue
{
    private:
        int airport[SIZE];
        int front,rear,count;

    public: 
        CircularQueue(): front(0), rear(-1), count(0) {}

        void enqueue(int id)
        {
            if(count == SIZE)
            {
                cout<<"Queue is Full. \n";
                return;
            }
            
            rear = (rear +1 )% SIZE;
            airport[rear] = id;
            count++;
        }

        int dequeue()
        {
            if(count == 0)
            {
                cout<<"Queue is Empty...\n";
                return -1;
            }
            cout << "Passenger boarded: " << airport[front] << endl;
            int temp = airport[front];
            if (count == 1)
            {
                front = 0;
                rear = -1;
                count = 0;
            }
            else
            {
                front = (front + 1) % SIZE;
                count--;
            }

            return temp;
        }

        void display()
        {
            if (count == 0)
            {
                cout << "Queue is Empty\n";
                return;
            }

            cout << "\nPassengers in boarding order: ";

            int i = front;     
            for (int j = 0; j < count; j++)
            {
                cout << airport[i] << " ";
                i = (i + 1) % SIZE;
            }      
            
            cout <<endl;
            cout<<"Front: "<<front<<endl;
            cout<<"Rear: "<<rear<<endl;
        }
};

int main()
{
    CircularQueue q;

    for (int i = 101; i <= 106; i++)
    {
        q.enqueue(i);
    }

    q.dequeue();
    q.dequeue();
    q.dequeue();

    //adding more passaengfers
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    // Two more passengers 
    q.dequeue();
    q.dequeue();

    // one more passenger comes
    q.enqueue(110);

    // One more passenger boards
    q.dequeue();

    // two  passenger comes
    q.enqueue(111);
    q.enqueue(112);

    // Display final queue
    q.display();

    return 0;
}