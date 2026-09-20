#include <iostream>
using namespace std;

class Node
{
    public:
        Node*next;
        char data;

        Node(char d)
        {
            data = d;
            next = nullptr;
        }
};

class Stack
{
private:
    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(char value)
    {
        Node* temp = new Node(value);

        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;
    }

    int peek()
    {
        if(top == NULL)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return top->data;
    }
};

int precedence(char op)
{
    if(op == '^')
        return 3;

    if(op == '*' || op == '/')
        return 2;

    if(op == '+' || op == '-')
        return 1;

    return 0;   
}
string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for(int i=0;i<infix.length() ; i++)
    {
        char ch = infix[i];

        //operand
        if((ch >= 'A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            while(!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.peek();
                s.pop();
            }

            //to pop (
            if(!s.isEmpty())
            {
                s.pop();
            }
        }
        else
        {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
            {
                //if top of stack precendence is greater then new operator then pop from stack to the string 
                postfix += s.peek();
                s.pop();
            }

            s.push(ch);

        }
    }

    while(!s.isEmpty())
    {
        postfix += s.peek();
        s.pop();
    }

    return postfix;


}
int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression:   " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}