/*Modify the Rat in a Maze program to allow movement in 4 directions*/

#include<iostream>
using namespace std;

#define n 4

bool isSafe(int maze[n][n], int x, int y, bool visited[n][n])
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(int maze[n][n], int x, int y, int sol[n][n], bool visited[n][n])
{
    if(x == n-1 && y == n-1)
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y, visited))
    {
        visited[x][y] = true;
        sol[x][y] = 1;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++)
        {
            if(solveMaze(maze, x + dx[i], y + dy[i], sol, visited))
                return true;
        }

        sol[x][y] = 0;
        visited[x][y] = false;
    }

    return false;
}

int main()
{
    int maze[n][n] = { {1,0,0,0},
                       {1,1,0,1},
                       {0,1,0,0},
                       {1,1,1,1} };

    int sol[n][n] = {0};
    bool visited[n][n] = {0};

    if(solveMaze(maze, 0, 0, sol, visited))
    {
        cout << "Path found:\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << sol[i][j] << " ";
            cout << "\n";
        }
    }
    else 
    {
        cout << "No path found";
    }

    return 0;
}
