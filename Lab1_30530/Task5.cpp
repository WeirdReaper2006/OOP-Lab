#include <iostream>
using namespace std;

class InstanceCounter
{
private:
    static int count;

public:
    InstanceCounter()
    {
        count++;
    }
    static int getCount()
    {
        return count;
    }
};

int InstanceCounter::count = 0;

int main()
{
    InstanceCounter a;
    cout << "The number of instances is: " << a.getCount() << endl;
    InstanceCounter b;
    cout << "The number of instances is: " << b.getCount() << endl;
    InstanceCounter c;
    cout << "The number of instances is: " << c.getCount() << endl;
    return 0;
}