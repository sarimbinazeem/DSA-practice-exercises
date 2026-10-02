// arr = {2, 3, 6, 7}
// target = 7

// We want to find combinations whose sum is exactly 7.

// Valid combinations are:

// {2, 2, 3}
// {7}

#include <iostream>
using namespace std;

void combinationSum(int arr[], int size, int index, int current[], int currentSize,int sum, int target)
{
    if(sum == target) {
        cout << "{ ";

        for(int i = 0; i < currentSize; i++)
        {
            cout << current[i] << " ";
        }

        cout << "}" << endl;
        return;       
    }

    //if sum becomes greater than target we return
    if(sum > target) return;

    //if we go to the end of array therefore no items left
    if(index == size) return;

    //we put this into current 
    current[currentSize] = arr[index];

    //since we can use the same element 
    combinationSum(arr,size,index,current,currentSize+1,sum + arr[index], target);

    //back track 
    //if same element addition dont lead to anywhere, we move to another element
    combinationSum(arr,size,index+1,current,currentSize,sum,target);
}
int main()
{
    int arr[] = {2, 3, 6, 7};
    int size = 4;
    int target = 7;

    int current[10];

    combinationSum(arr, size, 0, current, 0, 0, target);

    return 0;
}