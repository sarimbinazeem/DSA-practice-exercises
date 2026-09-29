// Question 2:
// Think of this like holding cards in your hand. The first item is considered &quot;sorted.&quot; Take the next item
// (the &quot;key&quot;) and compare it with items to its left. If a left item is bigger, shift it right to make space. Place
// the key in its correct spot. Repeat for all items.
// Your function: insertionArmSorter(int arr[], int size)
// What to do:
//  Sort the numbers using this method
//  After placing each key, print the current array state
//  if the key is already in the right place, print &quot;No shift required&quot;
//  For each key, print how many positions it shifted
//  At the end, print the total shift distance (sum of all shifts)


#include <iostream>
using namespace std;

void insertionArmSorter(int arr[], int size)
{
    int totalShift = 0;

    // Start from the second element
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        int shifts = 0;

        // Shift bigger elements to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }

        // Place key in its correct position
        arr[j + 1] = key;

        totalShift += shifts;

        cout << "Key: " << key << endl;

        if (shifts == 0)
        {
            cout << "No shift required" << endl;
        }
        else
        {
            cout << "Shifted: " << shifts << " position(s)" << endl;
        }

        cout << "Array: ";
        for (int k = 0; k < size; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "\nTotal shift distance: " << totalShift << endl;
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

    insertionArmSorter(arr, size);

    delete[] arr;

    return 0;
}