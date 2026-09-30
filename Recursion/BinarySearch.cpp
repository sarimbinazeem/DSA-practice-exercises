#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    if(low > high) return -1;
    int mid = low + (high-low)/2;
    if(arr[mid] == target) return mid;
    if(target < arr[mid]) return binarySearch(arr,low,mid -1 , target);
    else return binarySearch(arr,mid+1,high , target);
}

int main()
{
    int arr[] = {2, 4, 7, 9, 12, 15, 20};
    int size = 7;
    int target;

    cout << "Enter target: ";
    cin >> target;

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}