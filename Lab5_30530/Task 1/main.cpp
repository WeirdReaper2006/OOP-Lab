// Create a simple program with two classes:
// 1. Person Class
// a. Has two protected member variables: name (string) and age (int).
// b. Add a constructor that sets name and age when a Person object is created.

// 2. Student Class (inherits publicly from Person)
// a. Adds a new member variable: studentID (int).

// b. Add a constructor that initializes:
// i. The Person part (name and age)
// ii. The studentID

// c. Add a display()that prints:
// i. "Name: [name], Age: [age], ID: [studentID]"

// 3. Test the Program
// a. In main(), create a Student object
// b. Call the display() function to show all details.

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        name = "";
        age = 0;
    }

    Person(string name = "", int age = 0)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
private:
    int studentID;

public:
    Student(string name, int age, int studentID) : Person(name, age)
    {
        this->studentID = studentID;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }
};

int main()
{
    Student student1("Ammar", -20, 44810);
    Student student2("Afnan", 12, 15480);
    Student student3("Adam", 30, 48125);
    student1.display();
    student2.display();
    student3.display();
    return 0;
}