// An office printer serves jobs strictly in the order they were submitted. One afternoon, IT
// support discovers that the first K jobs currently waiting were accidentally submitted in the
// wrong order by a faulty scanner app, and need to be reversed but every job after the first K
// was submitted correctly and must be left exactly where it is, in its original order. For
// example, if the print queue currently holds, from front to back, J1, J2, J3, J4, J5, J6, J7, and K
// = 3, the queue must become J3, J2, J1, J4, J5, J6, J7 only the first three jobs are reversed, and
// the remaining four are untouched, still in their original relative order at the back of the queue.
// Write a function void reverseFirstK(Queue &amp;q, int k) that reverses just the first k elements of
// the queue in place, leaving the rest exactly as they were, using one stack as your only extra
// storage. Test your function on the example above with K = 3.

#include <iostream>
using namespace std;

const int SIZE = 100;

class Queue
{
    private:
        string arr[SIZE];
        int front;
        int rear;
        int count;

    public:
        Queue()
        {
            front = 0;
            rear = -1;
            count = 0;
        }

        bool isEmpty()
        {
            return count == 0;
        }

        bool isFull()
        {
            return count == SIZE;
        }

        int getSize()
        {
            return count;
        }
        void enqueue(string job)
        {
            if (isFull())
            {
                cout << "Queue Overflow!" << endl;
                return;
            }

            rear = (rear + 1) % SIZE;
            arr[rear] = job;
            count++;
        }

        string dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue Underflow!" << endl;
                return "";
            }

            string job = arr[front];

            front = (front + 1) % SIZE;
            count--;

            return job;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Queue is empty!" << endl;
                return;
            }

            int index = front;

            for (int i = 0; i < count; i++)
            {
                cout << arr[index] << " ";
                index = (index + 1) % SIZE;
            }

            cout << endl;
        }
};

void reverseFirstK(Queue &q, int k)
{
    int size = q.getSize();

     if (k < 0 || k > size)
    {
        cout << "Invalid value of K!" << endl;
        return;
    }   

    //we make stack and put the first k into stack , then put back into queue
    string stack[SIZE];
    int top = -1;
    for(int i =0 ;i<k ; i++)
    {
        //take firt k and put i nstack
        string job = q.dequeue();
        top++;
        stack[top] = job;
    }

    //put the elements from stack back into queue
    while(top!= -1)
    {
        string job = stack[top];
        top--;
        q.enqueue(job);
    }

    //put the jobs to the back of the reversed elemenrts
    for(int i =0 ; i< size - k; i++)
    {
        string job = q.dequeue();
        q.enqueue(job);
    }
}
int main()
{
    Queue q;

    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    cout << "Queue (front to back): ";
    q.display();

    int k = 3;

    reverseFirstK(q, k);

    cout << "Queue after reversing First " << k << " jobs: ";
    q.display();

    return 0;
}