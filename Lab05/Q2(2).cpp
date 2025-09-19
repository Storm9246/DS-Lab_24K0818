#include <iostream>
using namespace std;

int funcB(int x); // forward declaration

int funcA(int x) {
    if (x <= 0) {
        return 1;
    }
    // changed structure a little (variables + clearer flow)
    int part1 = x - funcA(x - 1);
    int part2 = funcB(x - 1);
    return part1 + part2;
}

int funcB(int x) {
    if (x <= 0) {
        return 1;
    }
    // reorganized calculation (use variables)
    int part1 = x + funcA(x - 1);
    int part2 = funcB(x - 1);
    return part1 + part2;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Result A: " << funcA(number) << endl;
    cout << "Result B: " << funcB(number) << endl;

    return 0;
}
