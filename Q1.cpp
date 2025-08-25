// Q1. Suppose you are developing a bank account management system, and you have defined the
// BankAccount class with the required constructors. You need to demonstrate the use of these
// constructors in various scenarios.
// 1. Default Constructor Usage: Create a default-initialized BankAccount object named
// account1. Print out the balance of account1.
// 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
// an initial balance of $1000. Print out the balance of account2.
// 3. Copy Constructor Usage: Using the account2 you created earlier, create a new
// BankAccount object named account3 using the copy constructor. Deduct $200 from
// account3 and print out its balance. Also, print out the balance of account2 to ensure it
// hasn't been affected by the transaction involving account3.

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balanceAmount;

public:
    BankAccount() 
    {
        balanceAmount = 0.0;
    }

    BankAccount(double initial) 
    {
        balanceAmount = initial;
    }

    BankAccount(const BankAccount &other) 
    {
        balanceAmount = other.balanceAmount;
    }

    void withdraw(double value) 
    {
        balanceAmount -= value;
    }

    void showBalance() const 
    {
        cout << "Current balance: $" << balanceAmount << endl;
    }
};

int main() 
{
    BankAccount acc1;
    acc1.showBalance();

    BankAccount acc2(1000);
    acc2.showBalance();

    BankAccount acc3(acc2);
    acc3.withdraw(200);
    acc3.showBalance();

    acc2.showBalance();

    return 0;
}
