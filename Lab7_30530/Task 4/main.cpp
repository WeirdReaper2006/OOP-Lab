// Demonstrate the use of dynamic_cast and catch a failed cast exception

// Requirements:
// ● Create a base class (e.g., Shape) with a virtual function and a virtual destructor.
// ● Derive at least one class (e.g., Circle).
// ● Create an object that is not a Circle (or use a base class object).
// ● Attempt to cast to Circle& using dynamic_cast and catch the std::bad_cast exception.

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void print() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void print() override
    {
        cout << "Circle" << endl;
    }
};

class Square : public Shape
{
public:
    void print() override
    {
        cout << "Square" << endl;
    }
};

int main()
{
    Shape *shape = new Square();
    try
    {
        Circle &circle = dynamic_cast<Circle &>(*shape);
        circle.print();
    }
    catch (std::bad_cast &e)
    {
        cout << "Failed to cast to Circle" << endl;
    }

    delete shape;
    return 0;
}