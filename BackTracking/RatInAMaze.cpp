#include <iostream>
using namespace std;

bool ratInMaze(int maze[][4], int solution[][4], int x,int y,int N)
{
    //invalid postion
    if(x<0 || x>=N || y <0 || y>=N) return false;

    //already visited
    if(solution[x][y] == 1) return false;

    //blockage
    if(maze[x][y] == 0) return false;

    solution[x][y] =1 ;

    //end if reached end
    if(x == N-1 && y == N-1) return true;

    //move down until there is a block, or already visited site. If it reaches destination then return true
    if(ratInMaze(maze,solution,x+1,y,N)) return true;

    //move up
    if(ratInMaze(maze,solution,x-1,y,N)) return true;

    //move right
    if(ratInMaze(maze,solution,x,y+1,N)) return true;

    //move left
    if(ratInMaze(maze,solution,x,y-1,N)) return true;
    
    //if this path leads to no where, we backtrack
    solution[x][y] = 0;
    return false;
}


int main()
{
    int maze[4][4] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int solution[4][4] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    ratInMaze(maze, solution, 0, 0, 4);

    return 0;
}