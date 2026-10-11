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
void insertAtBottom(int val)
{
    //recursively empty the stack to put the value at bottom
    if(isEmpty()){
        push(val);
        return;
    }

    //store the value to fill the stack later
    int temp = pop();
    insertAtBottom(val); //this empties the stack and puts at the bottom

    //this unwinds and push into the stack
    push(temp);
}

void reverse()
{
    //recursively empty the stack
    if(isEmpty())
    {
        return;
    }
    int temp = pop();
    reverse();
    insertAtBottom(temp);

}

int main() {
    // 1. Populate the stack
    push(10);
    push(20);
    push(30);
    push(40);
    
    cout << "Original Stack (Top to Bottom):" << endl;
    printStack();
    cout << "---------------------------------------" << endl;

    cout << "---------------------------------------" << endl;
    
    // 3. Reverse the stack recursively
    cout << "Reversing the entire stack recursively..." << endl;
    reverse();
    
    cout << "Final Reversed Stack (Top to Bottom):" << endl;
    printStack();
    cout << "---------------------------------------" << endl;
    
    return 0;
}
