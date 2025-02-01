#include <iostream>
using namespace std;

// Create a class Fraction that represents a mathematical fraction with:
// • Two private attributes: numerator and denominator.
// • A friend function addFractions(const Fraction&, const Fraction&) that adds
// two Fraction objects and returns a new Fraction object.
// • A friend function multiplyFractions(const Fraction&, const Fraction&)
// that multiplies two Fraction objects.

// In the main function:
// • Define two Fraction objects.
// • Use the friend functions to add and multiply them.
// • Print the results using a display() method.

// Question: Why do we use a friend function instead of a regular member function here?

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}
    friend Fraction addFractions(const Fraction &f1, const Fraction &f2)
    {
        int n = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        int d = f1.denominator * f2.denominator;
        return Fraction(n, d);
    };
    friend Fraction multiplyFractions(const Fraction &f1, const Fraction &f2)
    {
        int n = f1.numerator * f2.numerator;
        int d = f1.denominator * f2.denominator;
        return Fraction(n, d);
    };
    void display()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction f1 = Fraction(1, 2);
    Fraction f2 = Fraction(1, 3);

    Fraction f3 = addFractions(f1, f2);
    Fraction f4 = multiplyFractions(f1, f2);

    cout << "Addition: ";
    f3.display();
    cout << "Multiplication: ";
    f4.display();

    return 0;
}