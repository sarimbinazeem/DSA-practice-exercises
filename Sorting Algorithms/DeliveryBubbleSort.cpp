// Welcome to your shift at the Midnight Delivery Depot! The automated sorting machines have
// lost their software settings. Your job is to write sorting and searching programs for the robots.
// Each package has a unique tracking number.
// Take input for the number of items and their tracking numbers from the user. Write a separate
// C++ function for each task below.
// Question 1:
// Start at the beginning of the list. Compare each pair of neighboring items. If the left item is bigger than
// the right one, swap them. Move to the next pair and repeat until you reach the end. The biggest item move
// to the end. Go back to the start and repeat until the whole list is sorted.
// Your function: adjacentSwapper(int arr[], int size)
// What to do:
//  Sort the numbers using this method
//  Stop early if a full pass has no swaps (means it&#39;s already sorted)
// Print:
//  Total number of swaps made
//  Total comparisons made
//  How many passes you saved compared to the worst case (size-1 passes)
//  Show the theoretical worst-case comparisons next to your actual count: N(N-1)/2Welcome to your shift at the Midnight Delivery Depot! The automated sorting machines have
// lost their software settings. Your job is to write sorting and searching programs for the robots.
// Each package has a unique tracking number.
// Take input for the number of items and their tracking numbers from the user. Write a separate
// C++ function for each task below.
// Question 1:
// Start at the beginning of the list. Compare each pair of neighboring items. If the left item is bigger than
// the right one, swap them. Move to the next pair and repeat until you reach the end. The biggest item move
// to the end. Go back to the start and repeat until the whole list is sorted.
// Your function: adjacentSwapper(int arr[], int size)
// What to do:
//  Sort the numbers using this method
//  Stop early if a full pass has no swaps (means it&#39;s already sorted)
// Print:
//  Total number of swaps made
//  Total comparisons made
//  How many passes you saved compared to the worst case (size-1 passes)
//  Show the theoretical worst-case comparisons next to your actual count: N(N-1)/2

#include <iostream>
using namespace std;

void adjacentSwapper(int arr[], int size)
{
    int swaps = 0;
    int comparisions = 0;
    int passes = 0;

    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        passes++;

        for (int j = 0; j < size - 1 - i; j++)
        {
            comparisions++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }

    int worstCaseComparisons = size * (size - 1) / 2;
    int passesSaved = (size - 1) - passes;

    cout << "\n=====Sorted array======\n ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "Total swaps: " << swaps<< endl;
    cout << "Total comparisons: " << comparisions<< endl;
    cout << "Passes performed: " << passes<< endl;
    cout << "Passes saved: " << passesSaved<< endl;

    cout << "Theoretical worst-case comparisons: "<< worstCaseComparisons << endl;

}

int main()
{
    int size;

    cout << "Enter number of items: ";
    cin >> size;

    int* arr = new int[size];


    for (int i = 0; i < size; i++)
    {
        
       cout << "Enter tracking number "<<i+1<<"\n";
        cin >> arr[i];
    }

    adjacentSwapper(arr, size);

    delete[] arr;

    return 0;
}