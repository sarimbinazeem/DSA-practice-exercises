// A text editor stores the last 8 editing operations in a stack. Each operation is represented by
// an integer code. The editor receives the following operations:
// 12, 25, 17, 31, 44, 19
// The user then presses Undo three times, performs a new operation 52, and presses Undo
// twice again. Implement the system using an array-based stack. After every operation, display
// the current top operation. At the end, display the operations that remain in the stack from top
// to bottom.
// Your program should also handle an Undo request when the stack is empty.

#include <iostream>
using namespace std;

const int SIZE = 8;

class Stack
{
    private:
        int arr[SIZE];
        int top;

    
    public:
        Stack()
        {
            top = -1;
        }

        void displayTop()
        {
            if(top==-1) cout<<"Stack is Empty . No Top. \n";
            else cout<<"Current Top: "<< arr[top] <<endl;
            
        }

        void push(int value)
        {
            if(top == SIZE - 1)
            {
                cout<<"Stack Overflow...\n";
                return;
            }

            top++;
            arr[top] = value;
            displayTop();
        }

        void pop()
        {
            if(top == -1)
            {
                cout<<"Undo not possible. Stack is empty! \n";
                displayTop();
                return;
            }
            cout<<"Undo operation: "<<arr[top]<<endl;
            top--;
            displayTop();
        }

        void display()
        {
            cout << "\nRemaining operations (top to bottom): ";
            if (top == -1)
            {
                cout << "Stack is empty";
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    cout << arr[i] << " ";
                }
            }

            cout << endl;
        }
        
};

int main()
{
    Stack s;

    cout << "Performing editing operations:" << endl;
    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);

    cout << "\nUndoing three times:" << endl;
    s.pop();
    s.pop();
    s.pop();


    cout << "\nPerforming new operation:" << endl;
    s.push(52);


    cout << "\nUndoing twice:" << endl;
    s.pop();
    s.pop();


    s.display();

    return 0;
}