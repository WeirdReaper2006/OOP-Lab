// Implement a Point class in C++ that supports basic 2D point operations using operator overloading and calculates the Euclidean distance from the origin.

// 1. Define a Point Class:
// o Private members: x and y (integers).
// o Public constructor: Point(int x = 0, int y = 0).

// 2. Overload Operators:
// o + Operator: Adds two Point objects (e.g., Point(1,2) + Point(3,4) = Point(4,6)).
// o - Operator: Subtracts two Point objects.
// o * Operator: Multiplies a Point by an integer scalar (e.g., Point(2,3) * 3 = Point(6,9)).
// o == Operator: Checks if two Point objects are equal.
// o = Operator: Assigns one Point to another.

// 3. Friend Function for Length:
// o Implement a friend function calculateLength that returns the Euclidean distance of
// the Point from the origin (0,0).

// o Formula: sqrt(x^2 + y^2).
// o Use sqrt() from <cmath> for the calculation.

// 4. Output Formatting:
// o Overload << to print points as Point(x, y).

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point &p)
    {
        Point temp;
        temp.x = x + p.x;
        temp.y = y + p.y;
        return temp;
    }

    Point operator-(const Point &p)
    {
        Point temp;
        temp.x = x - p.x;
        temp.y = y - p.y;
        return temp;
    }

    Point operator*(int scalar)
    {
        Point temp;
        temp.x = x * scalar;
        temp.y = y * scalar;
        return temp;
    }

    bool operator==(const Point &p)
    {
        return x == p.x && y == p.y;
    }

    Point &operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }

    friend double calculateLength(const Point &p)
    {
        return sqrt((p.x * p.x) + (p.y * p.y));
    }

    friend ostream &operator<<(ostream &out, const Point &p)
    {
        out << "Point(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main()
{
    Point p1(3, 4);
    Point p2(1, 2);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    Point p3 = p1 + p2;
    cout << "p1 + p2: " << p3 << endl;

    Point p4 = p1 - p2;
    cout << "p1 - p2: " << p4 << endl;

    Point p5 = p1 * 3;
    cout << "p1 * 3: " << p5 << endl;

    cout << "p1 == p2: " << (p1 == p2) << endl;

    cout << "Length of p1: " << calculateLength(p1) << endl;

    return 0;
}