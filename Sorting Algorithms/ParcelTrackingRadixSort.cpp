/*

Question 7:
A national logistics enterprise processes 5,000,000 parcels globally every day. Each parcel object
contains a unique, non-negative numeric tracking number (ranging from 0 up to 999,999,999), a
sender name, a destination city, and a region routing code.
Develop a C++ program to sort these parcel records under two distinct scenarios. You must write your
sorting algorithms completely from scratch without using any built-in language sorting features.

Part 1: Tracking Number Sorting
Your system must sort all 5 million parcels by their tracking numbers in ascending order.
• The Constraints: To prevent system timeouts during peak hours, your sorting routine must run in
strictly linear time O(n) relative to the number of records. Furthermore, your algorithm must elegantly
handle tracking numbers with radically different digit lengths (ranging from 1 digit up to 9 digits)
without breaking down or allocating massive, unmanageable blocks of continuous memory.
*/

#include <iostream>
using namespace std;

class Parcel
{
    public:
        int trackingNum;
        string sender;
        string destination;
        int regionCode;
};

//maximum function to get how many places to go
int getMax(Parcel arr[], int n)
{
    int maximum = arr[0].trackingNum;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].trackingNum > maximum)
        {
            maximum = arr[i].trackingNum;
        }
    }

    return maximum;
}

//counting sort that counts (0-9) and sorts
void countSort(Parcel arr[], int n, int div)
{
    Parcel*temp = new Parcel[n];
    int count[10] = {0};

    //count occurences
    for(int i =0 ; i<n ; i++)
    {
        count[(arr[i].trackingNum/div)%10]++; 
    }

    //calculate the position of each digit
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    //output array in reverse
    for(int i = n-1; i >=0 ; i--)
    {
        // -1 for index
        temp[count[(arr[i].trackingNum/div)%10] - 1] = arr[i];
        count[(arr[i].trackingNum/div)%10]--;
    }

    // Copy output back
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp;

}

//radix sorting
void radixSort(Parcel arr[], int n)
{
    int maximum = getMax(arr, n);

    // Process units, tens, hundreds, etc.
    for (int div = 1; maximum / div > 0; div *= 10)
    {
        countSort(arr, n, div);
    }
}

void display(Parcel arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].trackingNum << "\t"<< arr[i].sender << "\t" << arr[i].destination << "\t"<< arr[i].regionCode << endl;
    }
}

int main()
{
    int number;

    cout << "Enter number of parcels: ";
    cin >> number;

    Parcel* arr = new Parcel[number];

    for (int i = 0; i < number; i++)
    {
        cout << "\nEnter tracking number: ";
        cin >> arr[i].trackingNum;

        cout << "Enter sender name: ";
        cin >> arr[i].sender;

        cout << "Enter destination city: ";
        cin >> arr[i].destination;

        cout << "Enter region code: ";
        cin >> arr[i].regionCode;
    }

    radixSort(arr, number);

    cout << "\n=====SORTED TRACKING NUMBERS =====\n";

    display(arr, number);

    delete[] arr;

    return 0;
}