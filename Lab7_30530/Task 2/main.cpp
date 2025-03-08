// Implement exception handling in a program where multiple exceptions may be thrown. Use catch(...) to handle unknown exceptions gracefully.
// In the main function use the try-catch block to catch these errors and output what was caught.

#include <iostream>
#include <exception>
using namespace std;

void testException(int x)
{
    if (x == 1)
        throw 10;
    else if (x == 2)
        throw 2.5;
    else if (x == 3)
        throw 'A';
    else
        throw string("Unknown Error");
};

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    try
    {
        testException(x);
    }
    catch (int e)
    {
        cout << "Caught an integer exception: " << e << endl;
    }
    catch (double e)
    {
        cout << "Caught a double exception: " << e << endl;
    }
    catch (char e)
    {
        cout << "Caught a character exception: " << e << endl;
    }
    catch (string e)
    {
        cout << "Caught a string exception: " << e << endl;
    }
    return 0;
}