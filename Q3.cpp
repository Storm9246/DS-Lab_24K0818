// Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
// Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
// Demonstrate the behavior of both shallow and deep copy using test cases.

#include <iostream>
using namespace std;

class Box 
{
  private:
    int* side;

  public:
    Box(int value) 
    {
        side = new int(value);
    }

    ~Box() 
    {
        delete side;
    }

    Box(const Box& other) 
    {
        side = new int(*other.side);
    }

    Box& operator=(const Box& other) 
    {
        if (this != &other) 
        {
            delete side;
            side = new int(*other.side);
        }
        return *this;
    }

    void display() const 
    {
        cout << "Side length: " << *side << endl;
    }

    void change(int value) 
    {
        *side = value;
    }
};

int main() 
{
    Box box1(5);
    Box box2 = box1;
    Box box3(10);

    box3 = box1;

    cout << "Initially:" << endl;
    box1.display();
    box2.display();
    box3.display();

    box1.change(20);

    cout << "After modifying box1:" << endl;
    box1.display();
    box2.display();
    box3.display();

    return 0;
}
