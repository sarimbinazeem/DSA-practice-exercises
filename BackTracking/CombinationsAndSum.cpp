// Question 10:
// A university's security system requires a special access code containing \(N\) digits. Each digit must
// be selected from a given set of allowed digits. However, the system imposes the following
// restrictions:
// - No digit can appear more than once.
// - The sum of all digits must equal a given target value S.
// - The digits must appear in strictly increasing order.

// Write a recursive C++ program that generates all valid access codes satisfying these conditions.
// For example, if the allowed digits are {1, 2, 3, 4, 5}, N=3, and S=9, the program should display:

// 1 3 5
// 2 3 4
// Requirements:
// - Use recursion to select digits and construct combinations.
// - Use backtracking to remove a selected digit when exploring another possibility.
// - Display all valid combinations and count them.
// - If no valid combination exists, display an appropriate message.
// - Do not use built-in library functions for generating combinations or checking the conditions.
// Note: Students should implement their own logic using arrays, loops, functions, recursion, and
// backtracking.

#include <iostream>
using namespace std;

void codesCombinations(int allowed[],int selected[],int limit,int sum,int start, int count,int s,int &combinations,int size)
{
    //if the limit is reached
    if(count == limit)
    {
        if(s== sum)
        {
            combinations++;
            //print the combination
            for(int i =0;i<limit;i++)
            {
                cout<<selected[i] << " ";
            }
            cout<<endl;
        }
        return;
    }

    //trying different combinations by entry by entry
    for(int i =start; i < size ; i++)
    {
        selected[count] = allowed[i];

        //moving on to the next entry
        codesCombinations(allowed,selected,limit,sum,i+1,count+1,s+allowed[i],combinations,size);

        //back track:
        // to check for all possibile comboination when the recursive call returns we go to next iteration

    }

}

int main()
{
    int size,limit,sum;
    cout<<"Enter Total Number of Allowed Digits: ";
    cin>>size;

    int *arr = new int[size];
    int *selected = new int[size];
    
    cout<<"Enter Allowed Digits in increasing order: ";
    for(int i = 0 ; i<size;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter Limit of Code: ";
    cin>>limit;
    
    cout<<"Enter Target Sum: ";
    cin>>sum;

    if(limit < 0 || limit >size )
    {
        cout<<"Invalid Input.\n";
        return 0;
    }

    cout<<"\n===Valid Codes===\n";
    int combinations = 0;
    codesCombinations(arr,selected,limit,sum,0,0,0,combinations,size);

    if (combinations == 0)
        cout << "No valid combination exists." << endl;
    else
        cout << "\nTotal valid combinations: "<< combinations << endl;
}