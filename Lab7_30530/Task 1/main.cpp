// You are given a base class Base and a derived class Derived. The base class has a destructor that is not virtual.
// Your task is to observe what happens when you delete a derived class object using a base class pointer,
// and then modify the code to use a virtual destructor to fix the issue.

// Steps to Follow:
// 1) Create a class Base with a constructor and destructor that print messages.
// 2) Create a class Derived that inherits from Base and also has a constructor and destructor that print messages.
// 3) Dynamically allocate a Derived object using a Base* pointer and delete it.
// 4) Observe whether the Derived class destructor is called.
// 5) Modify the Base class to have a virtual destructor and observe the difference.
// Write down your observations in a text file

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor called" << endl;
    }
    virtual ~Base()
    {
        cout << "Base Destructor called" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived Constructor called" << endl;
    }
    ~Derived()
    {
        cout << "Derived Destructor called" << endl;
    }
};

int main()
{
    Base *bptr = new Derived();
    delete bptr;
    return 0;
}