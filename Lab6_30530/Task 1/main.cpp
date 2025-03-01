// Create an abstract class Employee with properties name and salary and a pure virtual method calculateBonus().
// Create two classes Manager and Programmer that extend Employee and implement the calculateBonus() method.
// Create an abstract class IPromotable with a pure virtual method promote(double newSalary) and implement this abstract class in both Manager and Programmer.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double salary;

public:
    // Constructors
    Employee(string name, double salary) : name(name), salary(salary) {}

    // General Method
    virtual double calculateBonus() = 0;
};

class IPromotable
{
public:
    virtual void promote(double newSalary) = 0;
};

class Manager : public Employee, public IPromotable
{
public:
    // Constructors
    Manager(string name, double salary) : Employee(name, salary) {}

    // Getter and Setter Methods
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    double getSalary() { return salary; }
    void setSalary(double salary) { this->salary = salary; }

    // General Method
    double calculateBonus() override
    {
        return salary * 0.2;
    }

    void promote(double newSalary) override
    {
        salary = newSalary;
        cout << "Manager " << this->getName() << " has been promoted to " << this->getSalary() << endl;
    }
};

class Programmer : public Employee, public IPromotable
{
public:
    // Constructors
    Programmer(string name, double salary) : Employee(name, salary) {}

    // Getter and Setter Methods
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    double getSalary() { return salary; }
    void setSalary(double salary) { this->salary = salary; }

    // General Method
    double calculateBonus() override
    {
        return salary * 0.15;
    }

    void promote(double newSalary) override
    {
        salary = newSalary;
        cout << "Programmer " << this->getName() << " has been promoted to " << this->getSalary() << endl;
    }
};

int main()
{
    Manager manager("Aaron", 10000);
    Programmer programmer("Jonas", 5000);

    cout << "Manager's bonus: " << manager.calculateBonus() << endl;
    cout << "Programmer's bonus: " << programmer.calculateBonus() << endl;

    manager.promote(20000);
    programmer.promote(10000);

    cout << "Manager's new salary: " << manager.getSalary() << endl;
    cout << "Programmer's new salary: " << programmer.getSalary() << endl;
    cout << "Manager " << manager.getName() << "'s new bonus: " << manager.calculateBonus() << endl;
    cout << "Programmer " << programmer.getName() << "'s new bonus: " << programmer.calculateBonus() << endl;

    return 0;
}