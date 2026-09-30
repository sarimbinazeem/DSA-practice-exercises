// Question 4:
// Start by comparing items that are far apart. Use a gap of N/2 and sort items separated by that gap. Then
// cut the gap in half and repeat. Continue until the gap becomes 1, then do a final check of adjacent items.
// Your function: diminishingDistanceScanner(int arr[], int size)
// What to do:
//  Sort the numbers using this gap method
// For each gap size, print:
//  The current gap size
//  The gap as a percentage of array size: (Gap / N) × 100%
//  Number of comparisons made in this phase
//  Number of swaps made in this phase

#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void diminishingDistanceScanner(int arr[], int size)
{
    for(int gap = size/2 ; gap >=1 ; gap /= 2)
    {
        int comparision = 0;
        int swaps = 0;

        for(int i = gap; i<size; i++)
        {
            int j = i;
            while(j>=gap)
            {
                comparision++;
                if(arr[j-gap] > arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[j - gap];
                    arr[j - gap] = temp;

                    swaps++;
                    j = j - gap;                    
                }
                else{
                    break;
                }
            }
        }

        double percentage = (double)gap / size * 100;
        cout << "\n========== Gap Phase ==========\n";
        cout << "Gap size: " << gap << endl;
        cout << "Gap percentage: " << percentage << "%" << endl;
        cout << "Comparisons: " << comparision << endl;
        cout << "Swaps: " << swaps << endl;
    
        cout << "Array after gap " << gap << ": ";
        display(arr, size);
    }
    cout << "\n========== Sorted Array ==========\n";
    display(arr, size);
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


    diminishingDistanceScanner(arr, size);

    delete[] arr;

    return 0;
}