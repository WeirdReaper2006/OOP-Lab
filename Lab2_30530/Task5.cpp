#include <iostream>
using namespace std;

// Implement a program for a mechanic shop that operates on different cars. The program should include the following
// features:
// 1. Car Class:
// • Each car has a make, model, year, and a dynamically allocated array to store repair costs (to
// demonstrate deep copy).
// • Provide a constructor, destructor, copy constructor, and assignment operator to ensure proper
// memory management.

// 2. MechanicShop Class:
// • The mechanic shop maintains a list of cars and performs operations on them.
// • Use a dynamically allocated array to store the cars (to demonstrate deep copy).

// 3. Friend Function:
// • Implement a friend function calculateTotalRepairCost that calculates the total repair cost for a given
// car.

// 4. Operator Overloading:
// • Overload the + operator to combine the repair costs of two cars into a new car (simulating merging
// repair histories).
// • Overload the << operator to display car details and repair costs.

// 5. Deep Copy:
// • Ensure that all dynamically allocated memory (e.g., repair costs, list of cars) is properly copied using
// deep copy in the copy constructor and assignment operator