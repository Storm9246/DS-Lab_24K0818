// Task #3:
// Design a program to handle marks of students in different courses using a jagged array
// (since each student is enrolled in a different number of courses).
// => Input the number of courses each student takes.
// => Dynamically allocate memory for each student accordingly.
// => Calculate and display each student’s average marks.

#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "Enter number of students: ";
    cin >> students;

    int **marks = new int*[students];
    int *courseCount = new int[students];

    for (int i = 0; i < students; i++) {
        cout << "\nHow many courses for student " << i + 1 << "? ";
        cin >> courseCount[i];

        marks[i] = new int[courseCount[i]];
        cout << "Enter marks for " << courseCount[i] << " courses:" << endl;

        for (int j = 0; j < courseCount[i]; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nStudent Averages:" << endl;
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < courseCount[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (double)sum / courseCount[i];
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courseCount;

    return 0;
}
