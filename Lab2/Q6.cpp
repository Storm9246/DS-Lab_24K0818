/*Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/

#include <iostream>
using namespace std;

class SafePointer 
{
    int* data;
public:
    SafePointer() 
    {
        data = nullptr;
    }

    void setValue(int val) 
    {
        if (!data) 
        {
            data = new int;
        }
        *data = val;
    }

    int getValue() 
    {
        if (data) 
        {
            return *data;
        }
        return 0;
    }

    void release() 
    {
        delete data;
        data = nullptr;
    }

    ~SafePointer() 
    {
        release();
    }
};

int main() 
{
    SafePointer marks[5];

    for (int i = 0; i < 5; i++) 
    {
        int score;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> score;
        marks[i].setValue(score);
    }

    cout << "\nStudent Marks:" << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }

    for (int i = 0; i < 5; i++) 
    {
        marks[i].release();
    }

    return 0;
}
