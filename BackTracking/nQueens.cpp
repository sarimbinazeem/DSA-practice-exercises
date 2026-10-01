#include <iostream>
using namespace std;

bool isSafe(int arr[][4], int size, int x, int y)
{
    //check if not in same column
    for(int i = 0 ; i <y; i ++) 
    {
        if(arr[x][i]) return false;
    }

    //check if in upper-left diagonal
    int i = x- 1;
    int j = y-1;

    while(i>=0 && j>=0)
    {
        if(arr[i][j] == 1) return false;
        i--;
        j--;
    }

    // Check upper-right diagonal
    i = x - 1;
    j = y + 1;

    while(i >= 0 && j < size)
    {
        if(arr[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;

}

bool nQueens(int board[][4], int x, int size) {
    //if all queens are palced
    if(x == size)
    {
        return true;
    }

    for(int i=0; i < size;  i++)
    {
        if(isSafe(board,size,x,i))
        {
            board[x][i] = 1;

            //now explore other 
            if(nQueens(board,x+1,size)) return true;
            
            //if not true then back track
            board[x][i] = 0;
        }
    }

    return false; 
}
int main()
{
    int board[4][4] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(nQueens(board, 0, 4))
    {
        cout << "Solution found:\n";

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}