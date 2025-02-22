// Create a program to model temporary computer resources:
// 1. Base Class: MemoryResource
// a. Constructor prints "MemoryResource base allocated"
// b. Destructor prints "MemoryResource base freed"

// 2. Derived Class: NetworkBuffer (inherits from MemoryResource)
// a. Constructor prints "NetworkBuffer derived allocated"
// b. Destructor prints "NetworkBuffer derived freed"

// 3. In main():
// a. Create a NetworkBuffer object
// b. Observe what happens when the object goes out of scope

// Q. Why does the MemoryResource constructor run before the NetworkBuffer constructor?
// Ans) The MemoryResource constructor runs before the NetworkBuffer constructor because the NetworkBuffer class is derived from the MemoryResource class.
// When an object of the derived class is created, the base class constructor is called first, then the derived class constructor is called.
// When the object goes out of scope, the derived class destructor is called first, then the base class destructor is called.

#include <iostream>
using namespace std;

class MemoryResource
{
public:
    MemoryResource()
    {
        cout << "MemoryResource base allocated" << endl;
    }
    ~MemoryResource()
    {
        cout << "MemoryResource base freed" << endl;
    }
};

class NetworkBuffer : public MemoryResource
{
public:
    NetworkBuffer()
    {
        cout << "NetworkBuffer derived allocated" << endl;
    }
    ~NetworkBuffer()
    {
        cout << "NetworkBuffer derived freed" << endl;
    }
};

int main()
{
    NetworkBuffer buffer;
    return 0;
}