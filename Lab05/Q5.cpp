/*Implement a Sudoku solver using backtracking*/

#include<iostream>
using namespace std;

bool isSafe(int grid[9][9], int r, int c, int val)
{
    for(int i=0; i<9; i++)
    {
        if(grid[r][i] == val || grid[i][c] == val) 
            return false;
    }

    int sr = r - r % 3, sc = c - c % 3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(grid[sr+i][sc+j] == val) 
                return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[9][9])
{
    for(int r=0; r<9; r++)
    {
        for(int c=0; c<9; c++)
        {
            if(grid[r][c] == 0)
            {
                for(int val=1; val<=9; val++)
                {
                    if(isSafe(grid, r, c, val))
                    {
                        grid[r][c] = val;
                        if(solveSudoku(grid)) 
                            return true;
                        grid[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int grid[9][9];
    cout << "Enter Sudoku (0 for empty):\n";
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(solveSudoku(grid))
    {
        cout << "Solved Sudoku:\n";
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else 
    {
        cout << "No solution";
    }

    return 0;
}
