/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category. */

#include <iostream>
using namespace std;

int main()
{
    int cats;
    cout << "Enter number of categories: ";
    cin >> cats;

    int* sizes = new int[cats];
    int** records = new int*[cats];

    for (int i = 0; i < cats; i++)
    {
        cout << "Enter number of books in category " << i + 1 << ": ";
        cin >> sizes[i];

        records[i] = new int[sizes[i]];

        cout << "Enter Book IDs for category " << i + 1 << ":" << endl;
        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> records[i][j];
        }
    }

    int target;
    cout << "\nEnter Book ID to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < cats; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            if (records[i][j] == target)
            {
                cout << "Book found in category " << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found)
    {
        cout << "Book not available in library." << endl;
    }

    for (int i = 0; i < cats; i++)
    {
        delete[] records[i];
    }
    delete[] records;
    delete[] sizes;

    return 0;
}
