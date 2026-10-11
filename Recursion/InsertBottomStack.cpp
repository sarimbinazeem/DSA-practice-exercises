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

int main() {
    // 1. Populate the st
    push(10);
    push(20);
    push(30);
    push(40);
    
    cout << "Original Stack (Top to Bottom): ";
    printStack(); 

    int bottom_val = 5;
    cout << "Inserting " << bottom_val << " at the bottom..." << endl;
    insertAtBottom(bottom_val);
    

    cout << "Updated Stack (Top to Bottom):  ";
    printStack(); 
    
    return 0;
}