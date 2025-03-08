// 1) No accessors and mutators are allowed to be used.

// 2) The Display() function in ConsultantManager should be capable of displaying the values of all the data
// members declared in the scenario (name, code, yearsOfExperience, noOfTeams) without being
// able to alter the values.

// 3) The main function should contain only three program statements which are as follows:
// ● In the first statement, create object of ConsultantManager and pass the values for all the data members:
// ConsultantManager obj("Ali","S-123",17,5);
// ● In the second statement, call the Display() function.
// ● In the third statement, return 0.

// 4) All the values are required to be set through constructors’ parameters.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    string code;

public:
    Employee(string name, string code)
    {
        this->name = name;
        this->code = code;
    }
};

class Manager : public Employee
{
protected:
    int noOfTeams;

public:
    Manager(string name, string code, int noOfTeams) : Employee(name, code)
    {
        this->noOfTeams = noOfTeams;
    }
};

class Consultant : public Employee
{
protected:
    int yearsOfExperience;

public:
    Consultant(string name, string code, int yearsOfExperience) : Employee(name, code)
    {
        this->yearsOfExperience = yearsOfExperience;
    }
};

class ConsultantManager : public Manager, public Consultant
{
public:
    ConsultantManager(string name, string code, int yearsOfExperience, int noOfTeams) : Manager(name, code, noOfTeams), Consultant(name, code, yearsOfExperience)
    {
    }

    void Display()
    {
        cout << "Name: " << Manager::name << endl;
        cout << "Code: " << Manager::code << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
        cout << "Number of Teams: " << noOfTeams << endl;
    }
};

int main()
{
    ConsultantManager obj("Ali", "S-123", 17, 5);
    obj.Display();
    return 0;
}