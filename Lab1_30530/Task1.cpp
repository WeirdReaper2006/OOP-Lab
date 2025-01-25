#include <iostream>
#include "Student.cpp"
using namespace std;

int main()
{
    Student student1(1, "Rayyan", 3.5);
    student1.Courses.push_back("CSE 100");
    student1.Courses.push_back("CSE 200");
    student1.Courses.push_back("CSE 300");
    student1.displayCourses();
    cout << student1.getID() << endl;
    cout << student1.getName() << endl;
    cout << student1.getCGPA() << endl;
    student1.Courses.pop_back();
    student1.displayCourses();
    return 0;
}