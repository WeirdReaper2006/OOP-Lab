// Algorithm Template Class
// Create a templated class Algorithm<T> with the following properties:
// • algorithmId (string): Unique identifier for the algorithm
// • name (string): Name of the algorithm (e.g., "Quick Sort", "Binary Search")
// • category (string): for e.g. Sorting, Searching
// • timeComplexity (string): Big O notation for time complexity
// • spaceComplexity (string): Big O notation for space complexity
// • implementationFunction: Function that implements the algorithm
// Include appropriate constructors, getters, and setters.

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <string>
#include <functional>

using namespace std;

// Algorithm Template Class
template <typename T>
class Algorithm
{
private:
    string algorithmId;
    string name;
    string category;
    string timeComplexity;
    string spaceComplexity;
    function<void(vector<T> &)> implementationFunction;

public:
    Algorithm(string id, string nm, string cat, string timeC, string spaceC,
              function<void(vector<T> &)> func)
        : algorithmId(id), name(nm), category(cat), timeComplexity(timeC), spaceComplexity(spaceC), implementationFunction(func) {}

    string getId() const { return algorithmId; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    string getTimeComplexity() const { return timeComplexity; }
    string getSpaceComplexity() const { return spaceComplexity; }

    void run(vector<T> &data) const
    {
        implementationFunction(data);
    }
};

#endif