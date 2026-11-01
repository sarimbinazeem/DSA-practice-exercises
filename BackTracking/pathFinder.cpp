/*
Question 8:
A rescue robot is deployed inside a damaged building represented by an (N x N) grid. The robot starts
at the top-left cell (0, 0) and must reach the victim at the bottom-right cell (N-1, N-1). Some cells
contain obstacles that the robot cannot cross.
The robot can move only up, down, left, or right. It must not visit the same cell more than once in a
single path.
Write a recursive C++ program that finds and displays all possible valid paths from the starting cell to
the destination. If no path exists, display an appropriate message.
Requirements:
● Use recursion and backtracking to explore possible paths.
● Mark visited cells to avoid cycles.
● Undo the visited marking when backtracking.
● Do not use built-in library functions to find or generate paths.
*/

#include<iostream>
using namespace std;

bool pathFinder(int N,int **maze,int **solution, int x, int y)
{
    //boundary check
    if(x<0 || x>=N || y<0 || y>=N)
    {
        return false;
    }

    //check if there is ab obstacle
    if(maze[x][y] == 0)
    {
        return false;
    }
    if(solution[x][y] == 1)
    {
        return false;
    }

    solution[x][y] = 1;

    //destination reached
    if(x==N-1 && y==N-1){
        return true;
    }

    //Down
    if(pathFinder(N,maze,solution,x+1,y)) return true;
    //Up
    if(pathFinder(N,maze,solution,x-1,y)) return true;
    //Right
    if(pathFinder(N,maze,solution,x,y+1)) return true;
    //left
    if(pathFinder(N,maze,solution,x,y-1)) return true;

    solution[x][y] = 0;
    return false;
}

int main()
{
    int N;
    cout<<"Enter Size of Maze(NxN): ";
    cin>>N;

    int** maze = new int*[N];
    int** solution = new int*[N];
    for(int i =0 ; i < N ; i++)
    {
        maze[i] = new int[N];
        solution[i] = new int[N];
        for(int j=0 ; j<N;j++)
        {
            solution[i][j] = 0;
        }
    }


    cout<<"Input the Maze: \n";
    for(int i = 0 ; i<N;i++){
        for(int j = 0 ; j<N;j++)
        {
            cout<<"Enter For ("<<i<<","<<j<<"): ";
            cin >> maze[i][j];
        }
    }

    cout<<"Maze: \n";
    for(int i = 0 ; i<N;i++){
        for(int j = 0 ; j<N;j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    
   if( pathFinder(N,maze,solution,0,0))
    {
        cout<<"Solution: \n";
        for(int i = 0 ; i<N;i++){
            for(int j = 0 ; j<N;j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

    }
    else{
        cout<<"No Solution Exists\n";
    }
    
}