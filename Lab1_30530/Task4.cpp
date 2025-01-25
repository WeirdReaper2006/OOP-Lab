#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }
    void setRadius(float r)
    {
        radius = r;
    }
    float getRadius()
    {
        return radius;
    }
    void circumference()
    {
        cout << "Circumference: " << 2 * 3.14 * radius << endl;
    }
};

int main()
{
    Circle c1(5);
    c1.circumference();
    c1.setRadius(10);
    c1.circumference();
    return 0;
}