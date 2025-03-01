// We have to calculate the percentage of marks obtained in three subjects (each out of 100) by student A and
// in four subjects (each out of 100) by student B.
// Create an abstract class 'Marks' with a pure virtual method 'getPercentage()'.
// It is inherited by two other classes 'A' and 'B', each having a method with the same name that returns the percentage of the students.
// The constructor of student A takes the marks in three subjects as its parameters and
// the marks in four subjects as its parameters for student B.
// Create an object for each of the two classes and print the percentage of marks for both the students.

#include <iostream>
using namespace std;

// Abstract class of Marks
class Marks
{
public:
    virtual float getPercentage() = 0;
};

// Class A
class A : public Marks
{
protected:
    float marks[3];

public:
    A(float m1, float m2, float m3)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float getPercentage() override
    {
        return (marks[0] + marks[1] + marks[2]) / 3;
    }
};

// Class B
class B : public Marks
{
protected:
    float marks[4];

public:
    B(float m1, float m2, float m3, float m4)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
    }

    float getPercentage() override
    {
        return (marks[0] + marks[1] + marks[2] + marks[3]) / 4;
    }
};

int main()
{
    A studentA(90, 80, 70);
    B studentB(90, 80, 70, 60);

    cout << "Percentage of student A: " << studentA.getPercentage() << "%" << endl;
    cout << "Percentage of student B: " << studentB.getPercentage() << "%" << endl;

    return 0;
}