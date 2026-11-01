#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 8;
const int COURSES = 4;

bool isSafe(int **board,int x, int y)
{
    //(3,3) is broken so we return false
    if(x == 2 &&  y==2) return false;

    for(int i = 0 ; i < ROWS ; i++)
    {
        for(int j = 0 ; j< COLUMNS; j++)
        {
            //if the placement is 1
            if(board[i][j] != 0)
            {
                //if its in same row
                if(x == i)
                {
                    return false;
                }
                if(y == j)
                {
                    return false;
                }

                //in diagonal
                int diff1 = (x>i)? x-i : i - x;
                int diff2 = (y>j)? y-j : j - y;

                if(diff1 == diff2)
                {
                    return false;
                }

            }
        }
    }

    return true;
}

void placement(int **board,int courses,int &arrangments)
{
    if(COURSES == courses)
    {
        arrangments++;
        cout<<"\n 1st Course: Programming\n";
        cout<<"\n 2nd Course: Database Systems\n";
        cout<<"\n 3rd Course: Operating Systems\n";
        cout<<"\n 4th Course: Computer Networks\n";

        cout<<"\n==Arrangements==\n";
        for(int i =0 ; i<ROWS ; i++)
        {
            for(int j = 0 ; j<COLUMNS;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    for(int i = 0 ; i<ROWS; i++)
    {
        //Programming should be in the first row
        if(courses == 0 && i != 0)
        {
            continue; 
        }

        for(int j = 0 ; j<COLUMNS; j++)
        {
            if(isSafe(board,i,j))
            {
                board[i][j] = courses + 1;
                placement(board,courses +1,arrangments);
                board[i][j] = 0;

            }
        }
    }
}

int main()
{
    int** solution = new int*[ROWS];
    for(int i =0 ; i < ROWS ; i++)
    {
        solution[i] = new int[COLUMNS];
        for(int j=0 ; j<COLUMNS;j++)
        {
            solution[i][j] = 0;
        }
    }   

    int total = 0;
    placement(solution,0,total);
    if(total == 0)
    {
        cout<<"No Solution Exits..\n";
        return 0;
    }

    cout<<"\n Total Valid Arrangments: "<<total;
    // Free dynamically allocated memory
    for(int i = 0; i < ROWS; i++)
    {
        delete[] solution[i];
    }

    delete[] solution;
}