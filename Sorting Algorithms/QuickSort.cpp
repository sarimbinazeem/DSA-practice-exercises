#include <iostream>
using namespace std;

void swapValues(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;    
}

int medianOfThree(int arr[],int low,int high)
{
    int mid = low + (high - low) / 2;

    //we sort the low,mid and high
    //we put the least at low and highest at high
    if(arr[low] > arr[mid])
        swapValues(arr[low], arr[mid]);

    if(arr[low] > arr[high])
        swapValues(arr[low], arr[high]);

    if(arr[mid] > arr[high])
        swapValues(arr[mid], arr[high]);

    // The median is now at the middle index.
    return mid;    
}

int partition(int arr[],int low,int high)
{
    int medianIdx = medianOfThree(arr,low,high);

    //we mid to the end
    swapValues(arr[medianIdx],arr[high]);
    int pivot = arr[high];
    int i = low -1;

    //we compare the element with the pivot and if it is less than the pivot then we swap it
    //if it is not less than the pivot then the j pointer moves forward until we find the lesser
    //one and then swap it

    for(int j=low; j<high ; j++)
    {
        if(arr[j] <= pivot){
            i++;
            swapValues(arr[i],arr[j]);
        }
    }

    //we swap the pivot back to its correct position
    swapValues(arr[i+1],arr[high]);

    //return pivot
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low>=high) return;

    int pivotIndex = partition(arr,low,high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);    
}

int main()
{
    int arr[] = {8, 3, 5, 1, 9, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}