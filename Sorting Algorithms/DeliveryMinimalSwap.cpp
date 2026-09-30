// Look through the unsorted part of the list and find the smallest number. Swap it with the first item of that
// unsorted part. Move to the next position and repeat until the whole list is sorted. This uses fewer swaps
// than other methods.
// Your function: minimalSwapCrane(int arr[], int size)
// What to do:
//  Sort the numbers using this method
//  If the smallest item is already in the right spot, skip the swap (count it as a &quot;skipped swap&quot;)
// Print:
//  Total actual swaps
//  Number of skipped swaps
//  Swap-to-Comparison Ratio: (Actual Swaps / Total Comparisons) × 100%
//  Note: Total comparisons for this method is always N(N-1)/2

#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

}

void minimalSwapCrane(int arr[], int size)
{
    int swaps = 0;
    int skipped = 0;
    
    for(int i=0 ;i<size-1 ; i++)
    {
        int minIndex = i;
        for(int j=i;j<size; j++ )
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        //if there is a new smallest index
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            
            swaps++;
        }
        else
        {
            skipped++;
        }
        
        cout<<"\n=======Pass "<<i+1<<"===\n";

        display(arr,size);
        cout<<endl;
    }

    int totalComparisons = size * (size - 1) / 2;    
    double ratio = 0.0;
    if(totalComparisons!=0) ratio = (double)swaps / totalComparisons * 100;

    cout<<"\n====Sorted Array====\n";
    display(arr,size);
    
    cout << "\nTotal actual swaps: " << swaps;
    cout << "\nNumber of skipped swaps: " << skipped;
    cout << "\nTotal comparisons: " << totalComparisons;
    cout << "\nSwap-to-Comparison Ratio: " << ratio << "%";

}
int main()
{
    int size;

    cout << "Enter number of items: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size" << endl;
        return 0;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        
       cout << "Enter tracking number "<<i+1<<"\n";
        cin >> arr[i];
    }


    minimalSwapCrane(arr, size);

    delete[] arr;

    return 0;
}