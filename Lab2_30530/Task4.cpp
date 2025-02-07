#include <iostream>
using namespace std;

// Implement a Matrix2x2 class in C++ that supports the following operations using operator overloading:
// 1. Matrix Addition (+): Add two 2x2 matrices.
// 2. Matrix Subtraction (-): Subtract one 2x2 matrix from another.
// 3. Matrix Multiplication (*): Multiply two 2x2 matrices.
// 4. Output (<<): Overload the << operator to display the matrix in a readable format.

// Note:
// For Matrix Addition and subtraction, add and subtract the numbers in the same positions.

// For matrix multiplication: Multiply rows of the first matrix by columns of the second matrix and add the results.
// Step-by-Step:
// 1. Take the first row of the first matrix and the first column of the second matrix.
// 2. Multiply the corresponding numbers and add them together.
// 3. Repeat for all rows and columns.

class Matrix2x2
{
private:
    int number1;
    int number2;
    int number3;
    int number4;

public:
    Matrix2x2(int num1, int num2, int num3, int num4)
    {
        this->number1 = num1;
        this->number2 = num2;
        this->number3 = num3;
        this->number4 = num4;
    }

    friend Matrix2x2 operator+(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2)
    {
        return Matrix2x2(matrix1.number1 + matrix2.number1, matrix1.number2 + matrix2.number2, matrix1.number3 + matrix2.number3, matrix1.number4 + matrix2.number4);
    }

    friend Matrix2x2 operator-(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2)
    {
        return Matrix2x2(matrix1.number1 - matrix2.number1, matrix1.number2 - matrix2.number2, matrix1.number3 - matrix2.number3, matrix1.number4 - matrix2.number4);
    }

    friend Matrix2x2 operator*(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2)
    {
        return Matrix2x2(matrix1.number1 * matrix2.number1 + matrix1.number2 * matrix2.number3, matrix1.number1 * matrix2.number2 + matrix1.number2 * matrix2.number4, matrix1.number3 * matrix2.number1 + matrix1.number4 * matrix2.number3, matrix1.number3 * matrix2.number2 + matrix1.number4 * matrix2.number4);
    }

    friend ostream &operator<<(ostream &output, const Matrix2x2 &matrix)
    {
        output << matrix.number1 << " " << matrix.number2 << endl;
        output << matrix.number3 << " " << matrix.number4 << endl;
        return output;
    }
};

int main()
{
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(5, 6, 7, 8);

    cout << "Matrix1: " << endl;
    cout << matrix1;
    cout << endl;

    cout << "Matrix2: " << endl;
    cout << matrix2;
    cout << endl;

    cout << "Sum of Matrix 1 and Matrix 2: " << endl;
    cout << matrix1 + matrix2;
    cout << endl;

    cout << "Difference of Matrix 1 and Matrix 2: " << endl;
    cout << matrix1 - matrix2;
    cout << endl;

    cout << "Product of Matrix 1 and Matrix 2: " << endl;
    cout << matrix1 * matrix2;
    cout << endl;

    return 0;
}