// Question 5:
// A shipping company&#39;s only available storage equipment is a set of stack-style bins, crates can
// only be added or removed from the top. Management now wants shipments processed strictly in
// the order they were received (first in, first out), but nobody is willing to buy new equipment. You
// are asked to prove this is possible by building a queue that is internally made of nothing but two
// stack bins working together, exposing only enqueue(item) and dequeue() to the rest of the
// system, which must never know that stacks are involved underneath. For example, if items A, B,
// and C are enqueued in that order, calling dequeue() three times in a row must return A, then B,
// then C true, FIFO behaviour even though every underlying operation is a stack push or pop..
// Logical Hint: Use one stack purely for incoming items and a second stack purely for
// outgoing items. Whenever the outgoing stack is empty and a dequeue() is requested, pour
// the entire incoming stack into the outgoing stack one item at a time (which reverses their
// order back to arrival order), then pop from the outgoing stack. If the outgoing stack already
// has items, just pop from it directly, don&#39;t touch the incoming stack at all in that case.
// Your Task (C++): Implement a class MyQueue with enqueue(int) and dequeue() methods,
// using two stacks. Test it with the sequence enqueue(A), enqueue(B), dequeue(), enqueue(C),
// dequeue(), dequeue() and confirm the dequeues return A, B, C in that order

#include <iostream>
using namespace std;

const int SIZE = 100;
class MyQueue
{
    private:
        char inStack[SIZE];
        char outStack[SIZE];
        int inTop,outTop;

    public:
        MyQueue()
        {
            inTop = -1;
            outTop = -1;
        }       

        //push onto instack
        void enqueue(char item)
        {
            if(inTop == SIZE -1)
            {
                cout << "Incoming stack is full\n";
                return;                
            }
            inStack[++inTop] = item;
        }

        //push onto outstack
        char dequeue()
        {
            //if the output stck is eempty we transfter instack into outstack
            if(outTop == -1)
            {
                // if instack is empty
                if(inTop == -1)
                {
                    cout << "Queue is Empty\n";
                    return '\0';                    
                }
                //transfer
                while(inTop != -1)
                {
                    outStack[++outTop] = inStack[inTop--];
                }
            }

            //return the top element
            return outStack[outTop--];
        }

};

int main()
{
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue('C');

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;

}