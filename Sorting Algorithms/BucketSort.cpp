/*
Bucket Sort

it distributes an array into different buckets, Sorts it then Merges it

Example:
[29, 13, 25, 11, 28, 17, 12]

Bucket 1 (10-19) : 13,11,17,12
Bucket 2 (20-29) : 25,28,29
*/

#include <iostream>
using namespace std;

//if there is a capcaity of 100 then there can be 10 buckets
const int BUCKET =10;
const int CAPACITY = 100;

void insertionSort(int arr[],int size)
{
    for(int i = 1; i<size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] =key;
    }
}

void bucketSort(int arr[],int size)
{
    
    int bucket[BUCKET][CAPACITY] = {0};
    int count[BUCKET] = {0};

    //now we put each number into its bucket (10s row in its bucket and so on)
    for(int i = 0 ; i <size; i ++)
    {
        int index = arr[i]/10 -1;

        bucket[index][count[index]] = arr[i];
        //we update the occurances
        count[index]++;
    }

    //now we sort each bucket
    for(int i =0 ; i <BUCKET;i++){
        insertionSort(bucket[i],count[i]);
    }

    //we merge the buckets
    int k =0;
    for(int i =0 ; i<BUCKET; i++)
    {
        for (int j = 0; j < count[i] ; j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
        
    }
}

int main()
{
    int arr[] = {29, 13, 25, 11, 28, 17, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}