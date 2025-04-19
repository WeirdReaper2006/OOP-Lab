// In this lab task, you will develop a program to manage employee records.
// The program should provide functionalities to add, delete, and display employee records,
// as well as to perform various operations on the records using functors, function pointers, and lambdas with STL.

// Task Instructions:
// Define a class named Employee with the following attributes:
// ● Employee ID (int)
// ● Name (std::string)
// ● Department (std::string)
// ● Salary (double)

// Implement a class named EmployeeManager to manage employee records.
// This class should have the following functionalities:
// 1. Add a new employee record.
// 2. Delete an existing employee record by ID.
// 3. Display all employee records.
// 4. Sort employee records based on different criteria using functors, function pointers, or lambdas.
// 5. Find employees with salaries above a certain threshold using a lambda function.
// 6. Calculate the average salary of all employees.
// 7. Customize display of employee records by providing different display options using function pointers.

// Note: Use std::map to store employee records.
// Task Requirements:
// 1. Implement the Employee class with the specified attributes.
// 2. Implement the EmployeeManager class with the specified functionalities.
// 3. Use functors, function pointers, or lambdas where appropriate to perform sorting, filtering, and
// 4. customization of display.
// 5. Test the program with various scenarios to ensure correctness and functionality.
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Employee class definition
class Employee
{
private:
    int EmployeeID;
    string name;
    string department;
    double salary;

public:
    // Constructor to initialize employee attributes
    Employee(int id, string name, string department, double salary)
    {
        this->EmployeeID = id;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    // Getters for employee attributes
    int getId() const { return EmployeeID; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }

    // Setter for employee attributes
    void setId(int id) { this->EmployeeID = id; }
    void setName(string name) { this->name = name; }
    void setDepartment(string department) { this->department = department; }
    void setSalary(double salary) { this->salary = salary; }
};

// EmployeeManager class definition
class EmployeeManager
{
private:
    map<int, Employee> employees; // Map to store employee records with EmployeeID as the key

public:
    // Function to add a new employee record
    void addEmployee(int id, string name, string department, double salary)
    {
        Employee newEmployee(id, name, department, salary);
        employees.insert({id, newEmployee});
    }

    // Function to delete an existing employee record by ID
    void deleteEmployee(int id)
    {
        employees.erase(id);
    }

    // Function to display all employee records
    void displayAllEmployees()
    {
        cout << "Employee Records:" << endl;
        for (const auto &pair : employees)
        {
            cout << "ID: " << pair.second.getId() << ", Name: " << pair.second.getName() << ", Department: " << pair.second.getDepartment() << ", Salary: " << pair.second.getSalary() << endl;
        }
    }

    // Function to sort employee records based on salary
    vector<Employee> sortBySalary()
    {
        vector<Employee> empList;
        for (const auto &pair : employees)
        {
            empList.push_back(pair.second);
        }
        sort(empList.begin(), empList.end(), [](const Employee &a, const Employee &b)
             { return a.getSalary() < b.getSalary(); });
        return empList;
    }

    // Function to find employees with salaries above a certain threshold using a lambda function
    void findHighSalaryEmployees(double threshold) const
    {
        cout << "Employees with salary above " << threshold << ":" << endl;
        for (const auto &pair : employees)
        {
            if (pair.second.getSalary() > threshold)
            {
                cout << "ID: " << pair.second.getId() << ", Name: " << pair.second.getName() << ", Department: " << pair.second.getDepartment() << ", Salary: " << pair.second.getSalary() << endl;
            }
        }
    }

    // Function to calculate the average salary of all employees
    double calculateAverageSalary() const
    {
        double totalSalary = 0;
        for (const auto &pair : employees)
        {
            totalSalary += pair.second.getSalary();
        }
        return totalSalary / employees.size();
    }
};

int main()
{
    // Create an instance of EmployeeManager
    EmployeeManager manager;

    // Add some employee records
    manager.addEmployee(1, "Alice", "HR", 100000);
    manager.addEmployee(2, "Bob", "IT", 70000);
    manager.addEmployee(3, "Charlie", "Finance", 40000);

    // Display all employee records
    manager.displayAllEmployees();
    cout << endl;

    // Sort and display employees by salary
    cout << "Employees sorted by salary:" << endl;
    vector<Employee> sortedEmployees = manager.sortBySalary();
    for (const auto &emp : sortedEmployees)
    {
        cout << "ID: " << emp.getId() << ", Name: " << emp.getName() << ", Department: " << emp.getDepartment() << ", Salary: " << emp.getSalary() << endl;
    }
    cout << endl;

    // Find and display employees with salary above a certain threshold
    double threshold = 55000;
    manager.findHighSalaryEmployees(threshold);
    cout << endl;

    // Calculate and display the average salary of all employees
    double averageSalary = manager.calculateAverageSalary();
    cout << "Average Salary: " << averageSalary << endl;
    cout << endl;

    // Delete an employee record
    manager.deleteEmployee(2);
    cout << "After deleting employee with ID 2:" << endl;
    manager.displayAllEmployees();
    cout << endl;

    return 0;
}