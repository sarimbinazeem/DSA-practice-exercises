#include <iostream>
using namespace std;

int linearSearch(int arr[],int size ,int target,int index)
{
    if(size == 0) return -1;

    if(arr[0] == target) return index;

    return linearSearch(arr+1, size-1, target,index+1);
}

int main()
{
    int arr[] = {4, 7, 2, 9, 5};
    int size = 5;
    int target;

    cout << "Enter target: ";
    cin >> target;

    int index = linearSearch(arr, size, target, 0);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}