// Task 2:
// 1. Write a simple C++ program that demonstrates direct recursion. Create a function
// printNumbers(int n) that prints numbers from n down to 1 by calling itself
// directly.
// 2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
// and functionB(int n). functionA should call functionB, and functionB
// should call functionA, forming a cycle that prints numbers in a specific pattern.
// Ensure both programs have a base condition to prevent infinite loops




#include <iostream>
using namespace std;

void Pnum(int n);

int main() 
{
	int n;
	cout<<"enter number: ";
	cin>>n;
	Pnum(n);
}

void Pnum(int n) 
{
	if (n==1) 
	{
		cout<<1<<endl;
		return ;
	}
	else 
	{
		cout<<n<<endl;
		Pnum(n-1);
	}
}

