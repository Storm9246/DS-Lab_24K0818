/*A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.
*/

#include <iostream>
using namespace std;

int main()
{
    int depCount;
    cout << "Enter number of departments: ";
    cin >> depCount;

    int** pay = new int*[depCount];
    int* empCount = new int[depCount];

    for (int d = 0; d < depCount; d++)
    {
        cout << "Enter number of employees in department " << d << ": ";
        cin >> empCount[d];

        pay[d] = new int[empCount[d]];

        cout << "Enter salaries for department " << d << ":" << endl;
        for (int e = 0; e < empCount[d]; e++)
        {
            cin >> pay[d][e];
        }
    }

    double topAvg = -1e9;
    int topDept = -1;

    for (int d = 0; d < depCount; d++)
    {
        if (empCount[d] == 0)
        {
            cout << "Department " << d << " has no employees." << endl;
            continue;
        }

        int maxSal = pay[d][0];
        double total = pay[d][0];

        for (int e = 1; e < empCount[d]; e++)
        {
            if (pay[d][e] > maxSal)
            {
                maxSal = pay[d][e];
            }
            total += pay[d][e];
        }

        double avgSal = total / empCount[d];
        cout << "Department " << d << " -> Highest Salary = " << maxSal 
             << ", Average Salary = " << avgSal << endl;

        if (avgSal > topAvg)
        {
            topAvg = avgSal;
            topDept = d;
        }
    }

    if (topDept != -1)
    {
        cout << "\nDepartment with highest average salary is " << topDept 
             << " (Average = " << topAvg << ")" << endl;
    }

    for (int d = 0; d < depCount; d++)
    {
        delete[] pay[d];
    }
    delete[] pay;
    delete[] empCount;

    return 0;
}
