// You are provided with a list of elements containing information about their name, symbol, and atomic number.
// Utilize functors and STL algorithms to achieve the following:
// ● Sort: Create a custom functor to sort the elements based on two criteria:
//  o Primary: Atomic number (ascending order)
//  o Secondary: Element name (alphabetical order)

// ● Count: After sorting, determine the number of elements with names longer than 5 characters using a custom filter functor.

// ● Transform: Create a new list containing the element symbols transformed to uppercase using a lambda function.

// Task Instructions:
// 1. Complete the main function by initializing the elements vector with your desired element data (name,
// symbol, atomic number).
// 2. Implement the logic to process the sorted elements, long name count, and uppercase symbols as needed.
// 3. Modify the code to allow users to specify a custom minimum atomic number for filtering elements
// during sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype> // For std::toupper

using namespace std;

// Element class to hold information about each element
class Element
{
private:
    string name;
    string symbol;
    int atomicNumber;

public:
    // Constructor to initialize element data
    Element(string n, string s, int a) : name(n), symbol(s), atomicNumber(a) {}

    // Getters for element properties
    string getName() const { return name; }
    string getSymbol() const { return symbol; }
    int getAtomicNumber() const { return atomicNumber; }

    // Setters for element properties
    void setName(const string &n) { name = n; }
    void setSymbol(const string &s) { symbol = s; }
    void setAtomicNumber(int a) { atomicNumber = a; }
};

// Functor to sort elements based on atomic number and name
struct SortElements
{
    vector<Element> operator()(vector<Element> &a)
    {
        // Sort elements based on atomic number (ascending) and name (alphabetical order)
        sort(a.begin(), a.end(), [](const Element &e1, const Element &e2)
             {
                 if (e1.getAtomicNumber() != e2.getAtomicNumber())
                     return e1.getAtomicNumber() < e2.getAtomicNumber();
                 return e1.getName() < e2.getName(); });
        return a;
    }
};

// Functor to count elements with names longer than a specified length
struct CountLongNames
{
    int operator()(const vector<Element> &elements, int length)
    {
        // Count elements with names longer than the specified length
        return count_if(elements.begin(), elements.end(), [length](const Element &e)
                        { return e.getName().length() > length; });
    }
};

// Functor to transform element symbols to uppercase
struct TransformSymbols
{
    vector<string> operator()(const vector<Element> &elements)
    {
        // Transform element symbols to uppercase
        vector<string> symbols;
        transform(elements.begin(), elements.end(), back_inserter(symbols), [](const Element &e)
                  { 
                      string symbol = e.getSymbol();
                      transform(symbol.begin(), symbol.end(), symbol.begin(), ::toupper);
                      return symbol; });
        return symbols;
    }
};

int main()
{
    vector<Element> elements = {
        Element("Hydrogen", "H", 1),
        Element("Helium", "He", 5),
        Element("Lithium", "Li", 3),
        Element("Beryllium", "Be", 2),
        Element("Boron", "B", 5),
        Element("Carbon", "C", 6),
        Element("Nitrogen", "N", 6),
        Element("Oxygen", "O", 8),
        Element("Fluorine", "F", 9),
        Element("Neon", "Ne", 10)};

    // Sort elements using the custom functor
    elements = SortElements()(elements);

    // Print sorted elements
    cout << "Sorted Elements:" << endl;
    for (const auto &element : elements)
    {
        cout << "Name: " << element.getName() << ", Symbol: " << element.getSymbol() << ", Atomic Number: " << element.getAtomicNumber() << endl;
    }
    cout << endl;

    // Count elements with names longer than 5 characters
    int longNameCount = CountLongNames()(elements, 5);
    cout << "Number of elements with names longer than 5 characters: " << longNameCount << endl;
    cout << endl;

    // Transform symbols to uppercase using the custom functor
    vector<string> uppercaseSymbols = TransformSymbols()(elements);
    cout << "Uppercase Symbols:" << endl;
    for (const auto &symbol : uppercaseSymbols)
    {
        cout << symbol << " ";
    }
}