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

bool searchQueue(int target,int number)
{
    if(number == 0) return false;

    int temp = dequeue();
    bool found = (target == temp);
    enqueue(temp);

    //check the rest
    bool rest = searchQueue(target,number-1);
    return rest || found;
}
int main() {
    // Insert initial values into the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Printing queue using standard loop: ";
    printQueue();

    // Example of using the search function
    int target = 30;
    if (searchQueue(target, countQ)) {
        cout << target << " found in the queue!\n";
    } else {
        cout << target << " not found.\n";
    }

    return 0;
}