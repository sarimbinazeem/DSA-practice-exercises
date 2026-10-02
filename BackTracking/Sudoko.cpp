#include <iostream>
using namespace std;

bool isSafe(int board[][9], int row, int col, int number)
{
    for(int i =0 ; i <9; i++)  {
        //we check if it exists in the row
        if(board[row][i] == number) return false; 

        //we check if it exists in the column
        if(board[i][col] == number) return false;
    }
    
    //we check the 3x3 grid
    //we find the starting postioon  
    int startRow = row - row%3;
    int startCol = col - col %3; 

    for(int i =0 ; i<3; i++){
        for(int j=0 ; j<3; j++){
            if(board[startRow + i][startCol +j] == number) return false;
        }
    }

    return true;
}

bool sudoko(int board[][9]){
    for(int i = 0 ; i < 9 ; i++){
        for(int j =0 ; j < 9 ; j++){
            if(board[i][j] == 0) {
                //try number from 1 to 9
                for(int num = 1 ; num<10; num++)
                {
                    if(isSafe(board,i,j,num)){
                        board[i][j] = num;

                        //if this solves the board
                        if(sudoko(board)) return true;

                        //if this doesnt solve the board then BACKTRACK
                        board[i][j] = 0;
                    }
                }
                //if there isnt a valid box 
                return false;
            }


        }
    }

    // No empty cells
    return true;
}

int main()
{
    int board[9][9] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(sudoko(board))
    {
        cout << "Solution:\n";

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
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