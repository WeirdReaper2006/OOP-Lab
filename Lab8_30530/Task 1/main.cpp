// Design a class template named NumberStats that can store and calculate basic statistics (minimum, maximum, and average) for a collection of numbers.
// The template should accept a data type (T) as a parameter.
// Implement member functions for:
// ● Adding a number to the collection.
// ● Calculating the minimum, maximum, and average of the stored numbers.

// Test your NumberStats class with different data types like int and double.
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class NumberStats
{
private:
    vector<T> numbers; // Vector to store the numbers
    T minValue;        // Minimum value
    T maxValue;        // Maximum value
    double average;    // Average value

public:
    // Constructor
    NumberStats() : minValue(1000), maxValue(-1000), average(0)
    {
    }

    // Function to add a number to the collection
    void addNumber(T number)
    {
        numbers.push_back(number);
        calculateStats(); // Recalculate stats after adding a number
    }

    // Function to calculate minimum, maximum, and average
    void calculateStats()
    {
        // If (numbers.size() == 0)
        if (numbers.empty())
            return;

        // Update minValue and maxValue by iterating through the vector
        for (const auto &num : numbers)
        {
            if (num < minValue)
                minValue = num; // Update minimum value
            if (num > maxValue)
                maxValue = num; // Update maximum value
        }
        double sum = 0;
        for (const auto &num : numbers)
            sum += num;
        average = sum / numbers.size();
    }

    // Function to get the minimum value
    T getMin() const { return minValue; }

    // Function to get the maximum value
    T getMax() const { return maxValue; }

    // Function to get the average value
    double getAverage() const { return average; }
};

int main()
{
    // Test with int data type
    NumberStats<int> intStats;
    intStats.addNumber(5);
    intStats.addNumber(10);
    intStats.addNumber(3);
    intStats.addNumber(20);
    // Output the stats for int data type
    cout << "Int Stats:" << endl;
    cout << "Min = " << intStats.getMin() << endl;
    cout << "Max = " << intStats.getMax() << endl;
    cout << "Average = " << intStats.getAverage() << endl;
    cout << endl;

    // Test with double data type
    NumberStats<double> doubleStats;
    doubleStats.addNumber(5.5);
    doubleStats.addNumber(10.2);
    doubleStats.addNumber(3.8);
    doubleStats.addNumber(20.2);
    // Output the stats for double data type
    cout << "Double Stats:" << endl;
    cout << "Min = " << doubleStats.getMin() << endl;
    cout << "Max = " << doubleStats.getMax() << endl;
    cout << "Average = " << doubleStats.getAverage() << endl;
    cout << endl;

    return 0;
}