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

void rotateQueue(int n){
    if(n==0) return;
    //put front to rear
    int temp = dequeue();
    enqueue(temp);

    rotateQueue(n-1);
}


void findInsertIndex(int value, int n, int pos, int &index)
{
    if(n == 0)
        return;

    int temp = dequeue();

    //if we find an index once that position isnt changed ine one turn
    if(index == -1 && temp > value)
        index = pos;

    enqueue(temp);

    findInsertIndex(value, n - 1, pos + 1, index);
}

void sortedInsertQueue(int value, int n)
{
    int index = -1;

    findInsertIndex(value, n, 0, index);

    //if no index then last index
    if(index == -1)
        index = n;

    rotateQueue(index);

    //we add the vlaue at the end after rotating
    enqueue(value);

    //then after adding we rotate the remaining elements
    rotateQueue(n - index);
}

void sortQueue(int n)
{
    if(n == 0)
        return;

    int temp = dequeue();

    sortQueue(n - 1);

    sortedInsertQueue(temp, n - 1);
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