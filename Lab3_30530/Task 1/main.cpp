// Implement a StringProcessor class in C++ with three overloaded process methods to
// manipulate strings in different ways:

// 1. std::string process(const std::string& input)
// Reverses the input string.
// Example: process("hello") → "olleh".

// 2. std::string process(const std::string& str1, const std::string& str2)
// Concatenates the two strings with a space.
// Example: process("Hello", "World") → "Hello World".

// 3. std::string process(const std::string& input, int repeat)
// Repeats the input string repeat times.
// Example: process("ha", 3) → "hahaha".

#include <iostream>
#include <string>
using namespace std;

class StringProcessor
{
public:
    string process(const string &input)
    {
        string reversed = "";
        for (int i = input.size() - 1; i >= 0; i--)
        {
            reversed += input[i];
        }
        return reversed;
    }

    string process(const string &str1, const string &str2)
    {
        return str1 + " " + str2;
    }

    string process(const string &input, int repeat)
    {
        string repeated = "";
        for (int i = 0; i < repeat; i++)
        {
            repeated += input;
        }
        return repeated;
    }
};

int main()
{
    StringProcessor obj;
    cout << obj.process("hello") << endl;
    cout << obj.process("Hello", "World") << endl;
    cout << obj.process("ha", 3) << endl;
    return 0;
}