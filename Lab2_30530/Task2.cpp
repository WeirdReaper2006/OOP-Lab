#include <iostream>
using namespace std;

// Extend the DynamicArray class by implementing:
// • An overloaded assignment operator (operator=) that performs a deep copy.
// In the main function:
// 1. Create two DynamicArray objects and use operator= to assign one object to another.
// 2. Modify one of them and verify that the other remains unchanged.
// Note: Put a self-assignment check to prevent the data deleting itself during copying.

class DynamicArray
{
private:
    int *array = new int[size];
    int size;

public:
    DynamicArray(int s) : size(s) {};
    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            delete[] this->array;
            size = other.size;
            this->array = new int[size];
            for (int i = 0; i < size; i++)
            {
                this->array[i] = other.array[i];
            }
        }
        return *this;
    }
    void set(int index, int value) { array[index] = value; };
    int get(int index) { return array[index]; };
    ~DynamicArray()
    {
        delete[] array;
    }
};

int main()
{
    int size = 5;
    DynamicArray array1 = DynamicArray(size);
    for (int i = 0; i < size; i++)
    {
        array1.set(i, i);
    }

    cout << "Operator= Overloading" << endl;
    DynamicArray array2 = DynamicArray(size);
    array2 = array1;

    cout << "Original object" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array1.get(i) << endl;
    }

    cout << "Copied object" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array2.get(i) << endl;
    }

    array1.set(0, 10);

    cout << "After modifying the original object" << endl;

    cout << "Original object" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array1.get(i) << endl;
    }

    cout << "Copied object" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array2.get(i) << endl;
    }
    return 0;
}