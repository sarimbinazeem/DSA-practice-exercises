// To find a specific tracking number, look at the middle of the sorted list. If it&#39;s the number you want, stop.
// If your number is smaller, ignore the right half. If it&#39;s larger, ignore the left half. Keep splitting the list in
// half until you find the number or run out of items to check.
// Your function: midpointSplitSearch(int arr[], int size, int targetID)
// What to do:
//  First check if the array is sorted. If not, print &quot;Error: Conveyor is unsorted. Search aborted.&quot; and
// return -1
//  Use this formula for the middle: `mid = low + (high - low) / 2`
// For each step, print:
//  The low, mid, and high indices
//  Remaining search space percentage: `((high - low + 1) / N) × 100%`
//  Steps taken so far vs theoretical max steps: `floor(log2(N)) + 1`
// Return the index where the target was found, or -1 if not found

#include <iostream>
#include <cmath>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;

}
int midpointSplitSearch(int arr[], int size, int target)
{
    if(!isSorted(arr,size))
    {
        cout << "Error: Conveyor is unsorted. Search aborted." << endl;
        return -1;        
    }

    int low = 0;
    int high = size-1;
    int steps =0;

    int theoriticalSteps = floor(log2(size)) +1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        steps++;
        double percentage =(double)(high - low + 1) / size * 100;

        cout << "\n========== Search Step " << steps << " ==========\n";
        cout << "Low: " << low << endl;
        cout << "Mid: " << mid << endl;
        cout << "High: " << high << endl;
        cout << "Remaining search space: " << percentage << "%" << endl;
        cout << "Steps: " << steps << " / " << theoriticalSteps << endl;

        if(arr[mid] == target)
        {
            return mid;
        }
        if(target > arr[mid])
        {
            low = mid +1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
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

    cout << "Enter tracking numbers:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Enter tracking number " << i + 1 << ": ";
        cin >> arr[i];
    }

    int targetID;

    cout << "\nEnter tracking number to search: ";
    cin >> targetID;

    int result = midpointSplitSearch(arr, size, targetID);

    if (result != -1)
    {
        cout << "\nTarget found at index: " << result << endl;
    }
    else
    {
        cout << "\nTarget not found." << endl;
    }

    delete[] arr;

    return 0;
}