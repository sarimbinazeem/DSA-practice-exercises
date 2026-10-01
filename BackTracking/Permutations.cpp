#include <iostream>
using namespace std;

void permutations(int arr[], int size, int current[], int currentSize, bool used[])
{
    if(currentSize == size)    {
        cout << "{ ";

        for (int i = 0; i < size; i++)
        {
            cout << current[i] << " ";
        }

        cout << "}" << endl;
        return;
    }

    //we try element , and choose one element then use it
    //we explore other elements, then make an element unused by going bACK, and then trying new combinations
    for (int i = 0; i < size; i++)
    {
        if(used[i] == false)
        {
            current[currentSize] = arr[i];
            used[i] = true;

            permutations(arr,size,current,currentSize+1,used);

            //make it unsue
            used[i] = false;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    int size = 3;

    int current[3];
    bool used[3] = {false, false, false};

    permutations(arr, size, current, 0, used);

    return 0;
}