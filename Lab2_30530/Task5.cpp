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
// deep copy in the copy constructor and assignment operator.

class Car
{
private:
    string make;
    string model;
    int year;
    int *repairCosts;
    int repairCostsSize;

public:
    Car(string make, string model, int year, int *repairCosts, int repairCostsSize)
    {
        this->make = make;
        this->model = model;
        this->year = year;
        this->repairCosts = new int[repairCostsSize];
        this->repairCostsSize = repairCostsSize;
        for (int i = 0; i < repairCostsSize; i++)
        {
            this->repairCosts[i] = repairCosts[i];
        }
    }

    Car(const Car &other)
    {
        this->make = other.make;
        this->model = other.model;
        this->year = other.year;
        delete[] this->repairCosts;
        this->repairCostsSize = other.repairCostsSize;
        this->repairCosts = new int[other.repairCostsSize];
        for (int i = 0; i < other.repairCostsSize; i++)
        {
            this->repairCosts[i] = other.repairCosts[i];
        }
    }

    Car &operator=(const Car &other)
    {
        if (this != &other)
        {
            delete[] this->repairCosts;
            this->make = other.make;
            this->model = other.model;
            this->year = other.year;
            this->repairCosts = new int[other.repairCostsSize];
            this->repairCostsSize = other.repairCostsSize;
            for (int i = 0; i < other.repairCostsSize; i++)
            {
                this->repairCosts[i] = other.repairCosts[i];
            }
        }
        return *this;
    }

    ~Car()
    {
        delete[] repairCosts;
    }

    friend int calculateTotalRepairCost(const Car &car)
    {
        int totalRepairCost = 0;
        for (int i = 0; i < car.repairCostsSize; i++)
        {
            totalRepairCost += car.repairCosts[i];
        }
        return totalRepairCost;
    }
    friend Car operator+(const Car &car1, const Car &car2)
    {
        int *repairCosts = new int[car1.repairCostsSize + car2.repairCostsSize];
        for (int i = 0; i < car1.repairCostsSize; i++)
        {
            repairCosts[i] = car1.repairCosts[i];
        }
        for (int i = 0; i < car2.repairCostsSize; i++)
        {
            repairCosts[car1.repairCostsSize + i] = car2.repairCosts[i];
        }
        return Car("Merged", "Merged", 0, repairCosts, car1.repairCostsSize + car2.repairCostsSize);
    }
    friend ostream &operator<<(ostream &output, const Car &car)
    {
        output << "Make: " << car.make << endl;
        output << "Model: " << car.model << endl;
        output << "Year: " << car.year << endl;
        output << "Repair Costs: ";
        for (int i = 0; i < car.repairCostsSize; i++)
        {
            output << car.repairCosts[i] << ", ";
        }
        output << endl;
        return output;
    }
};

class MechanicShop
{
private:
    Car *cars;
    int carsSize;

public:
    MechanicShop(Car *cars, int carsSize)
    {
        // this->cars = new Car[carsSize];
        // this->carsSize = carsSize;
        for (int i = 0; i < carsSize; i++)
        {
            this->cars[i] = cars[i];
        }
    }

    MechanicShop(const MechanicShop &other)
    {
        // delete[] this->cars;
        // this->cars = new Car[other.carsSize];
        this->carsSize = other.carsSize;
        for (int i = 0; i < other.carsSize; i++)
        {
            this->cars[i] = other.cars[i];
        }
    }

    MechanicShop &operator=(const MechanicShop &other)
    {
        if (this != &other)
        {
            // delete[] this->cars;
            // this->cars = new Car[other.carsSize];
            this->carsSize = other.carsSize;
            for (int i = 0; i < other.carsSize; i++)
            {
                this->cars[i] = other.cars[i];
            }
        }
        return *this;
    }

    ~MechanicShop()
    {
        delete[] cars;
    }
};

int main()
{
    int repairCosts1[] = {100, 200, 300};
    Car car1("Toyota", "Corolla", 2010, repairCosts1, 3);
    cout << car1;
    cout << "Total Repair Cost: " << calculateTotalRepairCost(car1) << endl;

    int repairCosts2[] = {400, 500, 600};
    Car car2("Honda", "Civic", 2015, repairCosts2, 3);
    cout << car2;
    cout << "Total Repair Cost: " << calculateTotalRepairCost(car2) << endl;

    Car car3 = car1 + car2;
    cout << car3;
    cout << "Total Repair Cost: " << calculateTotalRepairCost(car3) << endl;

    return 0;
}