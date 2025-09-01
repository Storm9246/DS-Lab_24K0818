/*Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/

#include <iostream>
using namespace std;

int main() 
{
    int count;
    cout << "Enter initial number of months: ";
    cin >> count;

    double* costs = new double[count];
    for (int i = 0; i < count; i++) 
    {
        cout << "Expense for month " << i + 1 << ": ";
        cin >> costs[i];
    }

    char option;
    cout << "Add more months (Y) or Exit (E): ";
    cin >> option;

    if (option == 'Y' || option == 'y') 
    {
        int add;
        cout << "Enter number of additional months: ";
        cin >> add;

        double* extended = new double[count + add];
        for (int i = 0; i < count; i++) 
        {
            extended[i] = costs[i];
        }
        for (int i = count; i < count + add; i++) 
        {
            cout << "Expense for month " << i + 1 << ": ";
            cin >> extended[i];
        }

        delete[] costs;
        costs = extended;
        count += add;
    } 
    else if (option == 'E' || option == 'e') 
    {
        cout << "Goodbye!" << endl;
        delete[] costs;
        return 0;
    } 
    else {
        cout << "Invalid choice!" << endl;
        delete[] costs;
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) 
    {
        sum += costs[i];
    }
    double avg = sum / count;

    cout << "\nTotal Expenses: " << sum;
    cout << "\nAverage Expenses: " << avg << endl;

    delete[] costs;
    return 0;
}
