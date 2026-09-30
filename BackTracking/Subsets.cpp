#include <iostream>
using namespace std;

void subsequence(int arr[],int size, int index, int subsets[],int subsetSize)
{
    if(index == size) {
        cout<<"\n=== Subsets === \n";
        for(int i = 0 ; i < subsetSize; i++)
        {
            cout<< subsets[i] << " ";
        }
        cout<<endl;

        return;
    }

    //CHOICE 1: choose
    subsets[subsetSize] = arr[index];

    //WE PROCEED WIT HTHAT CHOICE
    subsequence(arr,size, index+1, subsets, subsetSize +1);
    
    //choice 2: DONT CHOOSE
    subsequence(arr,size, index+1, subsets, subsetSize );
    
}
int main()
{
    int arr[] = {1, 2, 3};
    int size = 3;

    int current[3];

    subsequence(arr, size, 0, current, 0);

    return 0;
}