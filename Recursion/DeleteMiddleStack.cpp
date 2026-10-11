#include <iostream>
using namespace std;

int st[100];
int top = -1;

void push(int value)
{
    st[++top] = value;
}

int pop()
{
    return st[top--];
}

bool isEmpty()
{
    return top == -1;
}

void printStack()
{
    for(int i = top; i >= 0; i--)
        cout << st[i] << " ";

    cout << endl;
}

void deleteMiddle(int count)
{
    if(count==0)
    {
        //this is the middle and we delete
        pop();
        return;
    }
    int temp = pop();
    deleteMiddle(count-1);
    push(temp);
}

int main() {
    // Push test elements into the stack
    push(30);
    push(-5);
    push(18);
    push(14);
    push(-3);

    cout << "Original stack (top to bottom): ";
    printStack();

    deleteMiddle(top/2);
    
    cout << "Stack after deleting the middle element:" << endl;
    printStack();

    return 0;
}