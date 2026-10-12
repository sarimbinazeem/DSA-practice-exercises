#include <iostream>
using namespace std;

void merge(int arr[],int low ,int mid,int high)
{
    int size = high-low+1;

    int *temp = new int[size];

    int i = low; // from low to mid
    int j= mid+1; //from mid to high
    int k =0 ; //for the output array

    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    //now we copy the remaining elements if exists
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }

    //now copy to original array
    for(int i = 0; i < size; i++){
        arr[low + i] = temp[i];
    }
    delete[] temp;    
}

void mergeSort(int arr[],int low,int high){
    //if low passes high
    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int arr[] = {8, 3, 5, 1, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}