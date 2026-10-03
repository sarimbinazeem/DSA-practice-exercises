#include <iostream>
using namespace std;

bool isPalindrome(char str[], int left, int right) {
    while(left < right){
        if(str[left] != str[right]) return false;

        left++;
        right--;
    }

    return true;
}

void partition(char str[], int start, char current[][100], int currentSize){
    //if the string is partioned
    if (str[start] == '\0')
    {
        cout << "[ ";

        for (int i = 0; i < currentSize; i++)
        {
            cout << current[i] << " ";

            if (i < currentSize - 1)
                cout << "| ";
        }

        cout << "]" << endl;
        return;
    }    

    int end = start;
    while(str[end] != '\0'){
        if(isPalindrome(str,start,end))
        {
            //storing the substring
            int k =0;
            for (int i = start; i <= end; i++)
            {
                current[currentSize][k] = str[i];
                k++;
            }
            
            //we move to next
            partition(str,end+1,current,currentSize+1);

            // Backtrack
            // We don't need to erase the string because currentSize tells us which partitions are valid
            //it back tracks it self through current Size.

        }
        end++;
    }
}

int main()
{
    char str[] = "aab";

    char current[100][100];

    partition(str, 0, current, 0);

    return 0;
}