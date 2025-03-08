// You are building a program to check the strength of a password. The program should enforce the following rules:
// • The password must be at least 8 characters long.
// • The password must contain at least one digit.
// • If the password does not meet these requirements, the program should throw an exception.

// Write a function void checkPassword(const std::string& password) that:
// • Throws a std::runtime_error if the password is less than 8 characters long.
// • Throws a std::runtime_error if the password does not contain at least one digit.
// • Prints "Password is strong and valid." if both conditions are met.

// In main(), prompt the user to enter a password, call checkPassword, and handle any exceptions.

// Note: In addition to using the standard std::isdigit function from the <cctype> header, you can check if a
// character is a digit by comparing its ASCII value directly. This method involves verifying whether the character
// falls within the ASCII range for numeric digits ('0' to '9').

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

void checkPassword(const string password) // User inputs the PW
{
    // Check if the password is at least 8 characters long
    if (password.length() < 8)
    {
        throw runtime_error("Password must be at least 8 characters long.");
    }

    // Check if the password contains at least one digit
    bool hasDigit = false;
    for (char c : password)
    {
        if (isdigit(c))
        {
            hasDigit = true;
            break;
        }
    }

    // If the password does not contain at least one digit
    if (!hasDigit)
    {
        throw runtime_error("Password must contain at least one digit.");
    }

    // If the password meets requirements
    cout << "Password is strong and valid." << endl;
}

int main()
{
    // Prompt the user to enter a password
    string password;
    cout << "Enter a password: ";
    cin >> password;

    // Call checkPassword and handle any exceptions
    try
    {
        checkPassword(password);
    }
    catch (const runtime_error &e)
    {
        // Print the error message (if any)
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}