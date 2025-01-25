#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
private:
    int ID;
    string Name;
    float CGPA;

public:
    vector<string> Courses;
    Student() {};
    Student(int id, string name, float cgpa) : ID(id), Name(name), CGPA(cgpa) {};
    void displayCourses()
    {
        for (int i = 0; i < Courses.size(); i++)
        {
            cout << Courses[i] << endl;
        }
    };
    void setID(int id) { ID = id; };
    void setName(string n) { Name = n; };
    void setCGPA(float c) { CGPA = c; };
    int getID() { return ID; };
    string getName() { return Name; };
    float getCGPA() { return CGPA; };
};