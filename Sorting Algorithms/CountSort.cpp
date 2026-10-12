/*
Count Sort
it counts the occurances of the entries and sort accordingly
for example
[4, 2, 2, 8, 3, 3, 1]

then we go from 1 to 9 and put that many occurances at each number
since one appears only 1 time it puts it forward and so on 
[1, 2, 2, 3, 3, 4, 8]

*/

#include <iostream>
using namespace std;

void countSort(int arr[],int size)
{
    //we find the maximum number that exists for count array
    int max = arr[0];
    for(int i =1 ;i<size;i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int*count = new int[max+1];

    //intiliaze count with 0
    for(int i = 0 ; i<=max;i++)
    {
        count[i] = 0;
    }

    for(int i = 0 ; i<size; i++)
    {
        count[arr[i]]++;
    }

    int index =0;
    for(int i = 0 ; i<=max; i++)
    {
        while(count[i]>0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, size);

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}