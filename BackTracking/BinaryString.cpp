#include <iostream>
using namespace std;

void binaryString(int size, int index , int current[])
{
    if(index == size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << current[i];
        }

        cout << endl;
        return;
    }

    current[index] = 0;
    binaryString(size, index+1, current);
    
    current[index] = 1;
    binaryString(size, index+1, current);
}