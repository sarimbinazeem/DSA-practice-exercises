#include <iostream>
using namespace std;

bool wordSearch(char board[][4], int rows, int cols, int x, int y, char word[], int wordIndex)
{
    //check if the target word has reached its end
    if(word[wordIndex] == '\0') return false;
    //boundary checking
    if(x < 0 || x>=rows || y<0 || y>=cols ) return false;
    //if the character from word doesnt matches the board we skip
    if(board[x][y] != word[wordIndex]) return false;
    //we store the character from board array and mark it as visited
    char og = board[x][y];
    board[x][y] = '*';

    //now trying all directions
    bool flag = false;
    //up
    if(wordSearch(board,rows,cols,x-1,y,word,wordIndex+1)) flag = true;
    //down
    else if(wordSearch(board,rows,cols,x+1,y,word,wordIndex+1)) flag = true;
    //right
    else if(wordSearch(board,rows,cols,x,y+1,word,wordIndex+1)) flag = true;
    //left
    else if(wordSearch(board,rows,cols,x,y-1,word,wordIndex+1)) flag = true;

    //if it is invalid, we backtrack and restore original position
    board[x][y] = og;
    
    return flag;
}

int main()
{
    char board[3][4] =
    {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    char word[] = "ABCCED";

    bool found = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (wordSearch(board, 3, 4, i, j, word, 0))
            {
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (found)
        cout << "Word found";
    else
        cout << "Word not found";

    return 0;
}