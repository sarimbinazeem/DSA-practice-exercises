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

void sortInsert(int val){
    if(isEmpty() || st[top] <= val){
        push(val);
        return;
    }

    //if the value is greater than top then we have to palce it somewhere in middle so we move 
    //to the right by popping
    int temp= pop();
    sortInsert(val);
    //after inserting the value we put the old values back by unwinding
    push(temp);
}

void sortStack(){
    //to emptu the stack
    if(isEmpty()){
        return;
    }

    //we empty the stack
    int temp = pop();
    sortStack();

    //we now insert into stack element by element
    sortInsert(temp);

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

    sortStack();

    cout << "Sorted stack (top to bottom): ";
    printStack();

    return 0;
}