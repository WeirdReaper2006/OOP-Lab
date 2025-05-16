#include <iostream>
using namespace std;
// Define a class DynamicArray that contains:
// • A dynamically allocated integer array.
// • A constructor to initialize the array with a given size.
// • A method set(int index, int value) to set a value at a specific index.
// • A method get(int index) to retrieve a value at an index.
// • A default copy constructor (compiler-generated) to demonstrate shallow copying.
// • A manual deep copy constructor that allocates new memory and copies elements individually.
// In the main function:
// 1. Create an object and fill it with values.
// 2. Copy it using the default copy constructor (shallow copy).
// 3. Modify the original object and observe the effect on the copied object.
// 4. Implement a deep copy constructor and repeat step 3 to confirm that the copied object is
// independent.
// Question: Why does modifying the original object affect the shallow copy but not the deep copy?
// Answer: The shallow copy constructor copies the address of the original object, so the copied object points to the same memory location. Therefore, modifying the original object will affect the copied object. In contrast, the deep copy constructor allocates new memory and copies the elements individually, so the copied object is independent of the original object.

class DynamicArray
{
private:
    int *array = new int[size = 0];
    int size = 0;

public:
    DynamicArray(int s) : size(s) {};
    DynamicArray(const DynamicArray &other)
    {
        delete[] this->array;
        size = other.size;
        this->array = new int[size];
        this->array = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->array[i] = other.array[i];
        }
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

    cout << "Deep Copy" << endl;
    DynamicArray array2 = DynamicArray(array1);

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