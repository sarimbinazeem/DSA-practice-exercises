#include <iostream>
using namespace std;

const int SIZE = 100;

int q[SIZE];
int front = 0;
int rear = -1;
int countQ = 0;

bool isEmpty()
{
    return countQ == 0;
}

bool isFull()
{
    return countQ == SIZE;
}

void enqueue(int value)
{
    if(isFull())
        return;

    rear = (rear + 1) % SIZE;
    q[rear] = value;
    countQ++;
}

int dequeue()
{
    if(isEmpty())
        return -1;

    int value = q[front];
    front = (front + 1) % SIZE;
    countQ--;

    return value;
}

void printQueue()
{
    for(int i = 0; i < countQ; i++)
        cout << q[(front + i) % SIZE] << " ";

    cout << endl;
}

void reverse(int k)
{
    if(k==0) return;

    int temp = dequeue();
    reverse(k-1);
    enqueue(temp);

}

void reverseFirstKQueue(int k)
{
    int n = countQ;

    if(k < 0 || k > n)
        return;

    reverse(k);

    for(int i = 0; i < n - k; i++)
    {
        int temp = dequeue();
        enqueue(temp);
    }
}

int main() {
    // Insert initial values into the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Original queue: ";
    printQueue();


    // Example of reversing the first K elements (e.g., K = 3)
    cout << "\nReversing the first 3 elements...\n";
    reverseFirstKQueue(3);
    
    cout << "Queue after reversal: ";
    printQueue();

    return 0;
}