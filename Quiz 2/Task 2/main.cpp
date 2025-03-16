#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    // Vehicle properties
    string make;
    string model;
    int year;
    double mileage;

public:
    // Constructor
    Vehicle(string make, string model, int year, double mileage)
    {
        this->make = make;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
    }

    // // Getter and Setter Methods
    // string getMake()
    // {
    //     return make;
    // }

    // void setMake(string Make)
    // {
    //     this->make = Make;
    // }

    // string getModel()
    // {
    //     return model;
    // }

    // void setModel(string Model)
    // {
    //     this->model = Model;
    // }

    // int getYear()
    // {
    //     return year;
    // }

    // void setYear(int Year)
    // {
    //     this->year = Year;
    // }

    // double getMileage()
    // {
    //     return mileage;
    // }

    // void setMileage(double Mileage)
    // {
    //     this->mileage = Mileage;
    // }

    // Virtual Functions
    virtual void startEngine() = 0;

    virtual void stopEngine() = 0;

    // Operator Overloading
    bool operator<(Vehicle &v)
    {
        return this->mileage < v.mileage;
    }

    friend ostream &operator<<(ostream &output, Vehicle &v)
    {
        output << "Make: " << v.make << endl;
        output << "Model: " << v.model << endl;
        output << "Year: " << v.year << endl;
        output << "Mileage: " << v.mileage << endl;
        return output;
    }
};

class ElectricVehicle : public virtual Vehicle
{
protected:
    // Electric Vehicle properties
    int batterCapacity;
    int batteryLevel;

public:
    // Constructor
    ElectricVehicle(string make, string model, int year, double mileage, int batteryCapacity, int batteryLevel) : Vehicle(make, model, year, mileage)
    {
        this->batterCapacity = batteryCapacity;
        this->batteryLevel = batteryLevel;
    }

    // // Getter and Setter Methods
    // int getBatteryCapacity()
    // {
    //     return batterCapacity;
    // }

    // void setBatteryCapacity(int BatteryCapacity)
    // {
    //     this->batterCapacity = BatteryCapacity;
    // }

    // int getBatteryLevel()
    // {
    //     return batteryLevel;
    // }

    // void setBatteryLevel(int BatteryLevel)
    // {
    //     this->batteryLevel = BatteryLevel;
    // }

    // Virtual Functions
    void startEngine() override
    {
        if (batteryLevel > 0)
        {
            cout << "Electric Vehicle Engine Started" << endl;
        }
        else
        {
            cout << "Battery Level is Low" << endl;
            cout << "Unable to start Engine" << endl;
        }
    }

    void stopEngine() override
    {
        cout << "Electric Vehicle Engine Stopped" << endl;
    }

    // General Method
    void chargeBattery(int charge)
    {
        if (batteryLevel + charge < batterCapacity)
        {
            batteryLevel += charge;
            cout << "Battery has been charged to " << batteryLevel << endl;
        }
        else
        {
            batteryLevel = batterCapacity;
            cout << "Battery has been fully charged to " << batteryLevel << endl;
        }
    }

    // Operator Overloading
    friend ostream &operator<<(ostream &output, ElectricVehicle &e)
    {
        output << "Make: " << e.make << endl;
        output << "Model: " << e.model << endl;
        output << "Year: " << e.year << endl;
        output << "Mileage: " << e.mileage << endl;
        output << "Fuel Level: " << e.batteryLevel << endl;
        return output;
    }
};

class GasolineVehicle : public virtual Vehicle
{
protected:
    // Gasoline Vehicle properties
    int fuelCapacity;
    int fuelLevel;

public:
    // Constructor
    GasolineVehicle(string make, string model, int year, double mileage, int fuelCapacity, int fuelLevel) : Vehicle(make, model, year, mileage)
    {
        this->fuelCapacity = fuelCapacity;
        this->fuelLevel = fuelLevel;
    }

    // // Getter and Setter Methods
    // double getFuelCapacity()
    // {
    //     return fuelCapacity;
    // }

    // void setFuelCapacity(int FuelCapacity)
    // {
    //     this->fuelCapacity = FuelCapacity;
    // }

    // double getFuelLevel()
    // {
    //     return fuelLevel;
    // }

    // void setFuelLevel(int FuelLevel)
    // {
    //     this->fuelLevel = FuelLevel;
    // }

    // Virtual Functions
    void startEngine() override
    {
        if (fuelLevel > 0)
        {
            cout << "Gasoline Vehicle Engine Started" << endl;
        }
        else
        {
            cout << "Fuel Level is Low" << endl;
            cout << "Unable to start Engine" << endl;
        }
    }

    void stopEngine() override
    {
        cout << "Gasoline Vehicle Engine Stopped" << endl;
    }

    // General Method
    void refuel(int fuel)
    {
        if (fuelLevel + fuel < fuelCapacity)
        {
            fuelLevel += fuel;
            cout << "Fuel tank has been refueled to " << fuelLevel << endl;
        }
        else
        {
            fuelLevel = fuelCapacity;
            cout << "Fuel tank has been fully refueled to " << fuelLevel << endl;
        }
    }

    // Operator Overloading
    friend ostream &operator<<(ostream &output, GasolineVehicle &g)
    {
        output << "Make: " << g.make << endl;
        output << "Model: " << g.model << endl;
        output << "Year: " << g.year << endl;
        output << "Mileage: " << g.mileage << endl;
        output << "Fuel Level: " << g.fuelLevel << endl;
        return output;
    }
};

class HybridVehicle : public ElectricVehicle, public GasolineVehicle
{
protected:
    // Hybrid Vehicle properties
    bool ElectricMode;

public:
    // Constructor
    HybridVehicle(string make, string model, int year, double mileage, int batteryCapacity, int batteryLevel, int fuelCapacity, int fuelLevel, bool ElectricMode) : ElectricVehicle(make, model, year, mileage, batteryCapacity, batteryLevel), GasolineVehicle(make, model, year, mileage, fuelCapacity, fuelLevel), Vehicle(make, model, year, mileage)
    {
        this->ElectricMode = ElectricMode;
    }

    // Virtual Functions
    void startEngine() override
    {
        if (ElectricMode)
        {
            if (batteryLevel > 0)
            {
                cout << "Hybrid Vehicle Engine Started in Electric Mode" << endl;
            }
            else
            {
                cout << "Battery Level is Low" << endl;
                switchMode();
                if (fuelLevel > 0)
                {
                    cout << "Hybrid Vehicle Engine Started in Gasoline Mode" << endl;
                }
                else
                {
                    cout << "Fuel Level is also low" << endl;
                    cout << "Unable to start Engine" << endl;
                }
            }
        }
        else
        {
            if (fuelLevel > 0)
            {
                cout << "Hybrid Vehicle Engine Started in Gasoline Mode" << endl;
            }
            else
            {
                cout << "Fuel Level is Low" << endl;
                switchMode();
                if (batteryLevel > 0)
                {
                    cout << "Hybrid Vehicle Engine Started in Electric Mode" << endl;
                }
                else
                {
                    cout << "Battery Level is also low" << endl;
                    cout << "Unable to start Engine" << endl;
                }
            }
        }
    }

    void stopEngine() override
    {
        cout << "Hybrid Vehicle Engine Stopped" << endl;
    }

    // General Method
    void switchMode()
    {
        ElectricMode = !ElectricMode;
        cout << "Mode Switched" << endl;
    }

    // Operator Overloading
    friend ostream &operator<<(ostream &output, HybridVehicle &h)
    {
        output << "Make: " << h.make << endl;
        output << "Model: " << h.model << endl;
        output << "Year: " << h.year << endl;
        output << "Mileage: " << h.mileage << endl;
        output << "Mode: " << ((h.ElectricMode) ? "Electric" : "Gasoline") << endl;
        output << "Fuel Level: " << h.fuelLevel << endl;
        output << "Battery Level: " << h.batteryLevel << endl;
        return output;
    }
};

int main()
{
    HybridVehicle obj1 = HybridVehicle("Toyota", "Corolla", 2025, 8.5, 100, 1, 100, 0, 0);
    cout << obj1;
    cout << endl;
    obj1.startEngine();
    cout << endl;
    cout << obj1;
    cout << endl;
    obj1.chargeBattery(100);
    cout << endl;
    obj1.refuel(100);
    cout << endl;
    cout << obj1;
}