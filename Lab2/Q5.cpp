/*Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/

#include <iostream>
using namespace std;

int main() 
{
    int r, c;
    cout << "Rows: ";
    cin >> r;
    cout << "Cols: ";
    cin >> c;

    int** matA = new int*[r];
    int** matB = new int*[r];
    int** sum = new int*[r];
    int** diff = new int*[r];

    for (int i = 0; i < r; i++)
    {
        matA[i] = new int[c];
        matB[i] = new int[c];
        sum[i] = new int[c];
        diff[i] = new int[c];
    }

    cout << "Fill Matrix A:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matA[i][j];
        }
    }

    cout << "Fill Matrix B:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matB[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = matA[i][j] + matB[i][j];
            diff[i][j] = matA[i][j] - matB[i][j];
        }
    }

    cout << "\nMatrix Addition:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix Subtraction:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++)
    {
        delete[] matA[i];
        delete[] matB[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] matA;
    delete[] matB;
    delete[] sum;
    delete[] diff;

    return 0;
}
