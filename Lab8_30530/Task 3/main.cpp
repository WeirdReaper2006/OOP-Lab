// Design a template class Complex to represent complex numbers.
// Implement addition, subtraction, multiplication, and division operations for complex numbers.
// Create template specializations for integer and floating-point complex numbers to optimize operations.
// Test the class and its specializations with different complex number operations.

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Complex
{
private:
    T real;
    T imag;

public:
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag - imag * c.real);
    }

    Complex operator/(const Complex &c) const
    {
        T denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
        cout << endl;
    }
};

template <>
class Complex<int>
{
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag - imag * c.real);
    }

    Complex operator/(const Complex &c) const
    {
        int denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
        cout << endl;
    }
};

template <>
class Complex<float>
{
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag - imag * c.real);
    }

    Complex operator/(const Complex &c) const
    {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
        cout << endl;
    }
};

int main()
{
    // Test the Complex class with integer specializations
    Complex<int> c1(3, 4), c2(1, 2);
    cout << "Integer Complex Addition: ";
    Complex<int> c3 = c1 + c2;
    c3.display();
    cout << "Integer Complex Subtraction: ";
    Complex<int> c4 = c1 - c2;
    c4.display();
    cout << "Integer Complex Multiplication: ";
    Complex<int> c5 = c1 * c2;
    c5.display();
    cout << "Integer Complex Division: ";
    Complex<int> c6 = c1 / c2;
    c6.display();

    // Test the Complex class with float specializations
    Complex<float> c7(3.5, 4.5), c8(1.5, 2.5);
    cout << "Float Complex Addition: ";
    Complex<float> c9 = c7 + c8;
    c9.display();
    cout << "Float Complex Subtraction: ";
    Complex<float> c10 = c7 - c8;
    c10.display();
    cout << "Float Complex Multiplication: ";
    Complex<float> c11 = c7 * c8;
    c11.display();
    cout << "Float Complex Division: ";
    Complex<float> c12 = c7 / c8;
    c12.display();

    // Test the Complex class with double data type
    Complex<double> c13(3.8, 18.5), c14(4.5, 7.5);
    cout << "Double Complex Addition: ";
    Complex<double> c15 = c13 + c14;
    c15.display();
    cout << "Double Complex Subtraction: ";
    Complex<double> c16 = c13 - c14;
    c16.display();
    cout << "Double Complex Multiplication: ";
    Complex<double> c17 = c13 * c14;
    c17.display();
    cout << "Double Complex Division: ";
    Complex<double> c18 = c13 / c14;
    c18.display();

    return 0;
}