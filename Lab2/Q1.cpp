// Task #1:
// Implement a program that dynamically allocates a 1D array of integers.
// => The size should be given by the user.
// => Initialize all elements with zero.
// => Then, let the user update values at different positions.
// => Finally, print the array and deallocate memory properly.


#include <iostream>
using namespace std;

void update(int *ptr, int pos, int newValue, int size) 
{
    if (pos >= 0 && pos < size) 
    {
        ptr[pos] = newValue;
        cout << "Element at index " << pos << " updated successfully." << endl;
    }
    else
    {
        cout << "Wrong index";
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *numbers = new int[n];

    for (int i = 0; i < n; i++) 
    {
        numbers[i] = 0;
    }

    int position, value;
    cout << "Enter the index you want to modify: ";
    cin >> position;
    cout << "Enter the new value: ";
    cin >> value;

    update(numbers, position, value, n);

    cout << "\nFinal Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << ": " << numbers[i] << endl;
    }

    delete[] numbers;
    return 0;
}
