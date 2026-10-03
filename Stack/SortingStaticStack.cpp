#include <iostream>
using namespace std;

class Stack
{
    private:
        int stack[100];
        int top;

    public:
        Stack()
        {
            top = -1;
        }

        void push(int elem)
        {
            top++;
            stack[top] = elem;
        }

        void display()
        {
            for(int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }

            cout << endl;
        }

        void bubbleSort(){
            for(int i = 0 ; i <top; i++){
                bool swapped =false;
                for(int j =0 ; j <= top - i - 1 ;j++){
                    if(stack[j] > stack[j+1]){
                        int temp = stack[j];
                        stack[j] = stack[j+1];
                        stack[j+1] = temp;

                        swapped =true;
                    }

                }

                if(!swapped) return;
             }
        }

        void insertionSort()
        {
            for(int i = 1; i <= top; i++)
            {
                int key = stack[i];
                int j = i - 1;

                while(j >= 0 && stack[j] > key)
                {
                    stack[j + 1] = stack[j];
                    j--;
                }

                stack[j + 1] = key;
            }
        }
        void selectionSort()
        {
            for(int i = 0; i < top; i++)
            {
                int minIndex = i;

                for(int j = i + 1; j <= top; j++)
                {
                    if(stack[j] < stack[minIndex])
                    {
                        minIndex = j;
                    }
                }

                if(minIndex != i)
                {
                    int temp = stack[i];
                    stack[i] = stack[minIndex];
                    stack[minIndex] = temp;
                }
            }
        }
        void shellSort()
        {
            int size = top + 1;

            for(int gap = size / 2; gap > 0; gap = gap / 2)
            {
                for(int i = gap; i < size; i++)
                {
                    int key = stack[i];
                    int j = i;

                    while(j >= gap && stack[j - gap] > key)
                    {
                        stack[j] = stack[j - gap];
                        j = j - gap;
                    }

                    stack[j] = key;
                }
            }
        }
};

int main()
{
    Stack s;

    s.push(20);
    s.push(10);
    s.push(30);
    s.push(70);
    s.push(3);
    s.push(1);

    cout << "\n=== Before Sorting ===\n";
    s.display();


    cout << "\n=== After Sorting ===\n";
    s.display();

    return 0;
}