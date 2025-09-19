// Task 1:
// Write a recursive C++ function calculateFactorial(int n) that computes the factorial
// of a given integer n . The function should have a base condition to stop the recursion when n is
// 0 or 1, and should call itself with a smaller value of n (e.g., n-1) to solve the problem.

#include<iostream>
using namespace std;

int calculateFactorial(int n);

int main()
{
    int n;
    cout << "Enter integer: ";
    cin >> n;
    if(n < 0)
    {
        cout << "integer can not be negative, re enter: ";
        cin >> n;
    }
    int factorial =  calculateFactorial(n);
    cout<< n << "! = " <<  factorial;

}

int calculateFactorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    
    return n * calculateFactorial(n - 1);
}
