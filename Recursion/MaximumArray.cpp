#include <iostream>
using namespace std;

int arrayMaximum(int arr[], int size)
{
    if(size == 1) return arr[0];

    int max = arrayMaximum(arr+1, size-1);

    if(arr[0] > max) return arr[0];
    else return max;
    

}

int main()
{
    int arr[] = {4, 7, 2, 9, 5};
    int size = 5;

    cout << "Maximum: " << arrayMaximum(arr, size) << endl;

    return 0;
}