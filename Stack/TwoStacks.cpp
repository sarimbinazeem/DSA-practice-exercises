#include <iostream>
using namespace std;

class TwoStacks
{
    private:
        int *arr;
        int size;
        int top1;
        int top2;
    
    public:
        TwoStacks(int n)
        {
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;

        }

        void push1(int elem)
        {
            if(top1 >= top2 -1)
            {
                cout<<"Overflow in Stack 1. \n";
                return;
            }
            

        }


        ~TwoStacks()
        {
            delete[] arr;
        }
};