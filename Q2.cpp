// Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
// complete with a shallow copy implementation? Define attributes such as student name, exam
// date, and score within the class, and include methods to set these attributes and display exam
// details. As part of this exercise, intentionally omit the implementation of the copy constructor

// Lab Manual 01

// and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
// shallow copy, and observe any resulting issues?

#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* StdName;
    char* exmDate;
    int score;

public:
    Exam(const char* name, const char* date, int s) 
    {
        StdName = new char[strlen(name) + 1];
        strcpy(StdName, name);
        exmDate = new char[strlen(date) + 1];
        strcpy(exmDate, date);
        score = s;
    }

    ~Exam() 
    {
        delete[] StdName;
        delete[] exmDate;
    }

    void display() 
    {
        cout << "Student: " << StdName << endl;
        cout << "Date: " << exmDate << endl;
        cout << "Score: " << score << endl;
    }

    void updateName(const char* newName) 
    {
        strcpy(StdName, newName);
    }

    void updateDate(const char* newDate) 
    {
        strcpy(exmDate, newDate);
    }

    void updateScore(int newScore) 
    {
        score = newScore;
    }
};

int main() 
{
    Exam exam1("Ahmed", "2025-08-20", 92);
    exam1.display();

    Exam exam2 = exam1;
    exam2.display();

    exam1.updateName("Hina");
    exam1.updateDate("2025-09-05");
    exam1.updateScore(81);

    cout << "After modifying exam1:" << endl;
    exam1.display();
    exam2.display();

    return 0;
}

// ISSUE!!
//   Since we didn’t write our own copy constructor or assignment operator,
//   C++ just copied the memory addresses (shallow copy). That means both objects
//   point to the same name and date. So, when we change one object, the other one
//   also changes. And when the program ends, both objects try to delete the same
//   memory, which can crash the program.
