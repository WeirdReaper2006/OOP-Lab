// Design a Generic GenericSorter<T> Using Comparable/Comparator
// What to do:
// • Create a class GenericSorter<T> with a method:
// o void insertionSort(List<T> list, Comparator<T> cmp);
// • Implement the insertion‐sort logic so it can order any T according to cmp.compare(a,b).
// • Define a simple Student class (fields: String name, double gpa) and two comparators: one by  name (alphabetical) and one by GPA (descending).
// • In Main, build a List<Student>, call your insertionSort() twice (once per comparator), and print the sorted lists.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class GenericSorter
{
public:
    void insertionSort(vector<T> &list, bool (*cmp)(const T &, const T &))
    {
        while (true)
        {
            bool swapped = false;
            for (size_t i = 1; i < list.size(); ++i)
            {
                if (cmp(list[i], list[i - 1]))
                {
                    swap(list[i], list[i - 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
};

class Student
{
private:
    string name;
    double gpa;

public:
    Student(string n, double g) : name(n), gpa(g) {}
    string getName() const { return name; }
    double getGPA() const { return gpa; }
    void print() const { cout << "Name: " << name << ", GPA: " << gpa << endl; }
};

bool compareByName(const Student &a, const Student &b)
{
    return a.getName() < b.getName();
}

bool compareByGPA(const Student &a, const Student &b)
{
    return a.getGPA() > b.getGPA(); // Descending order
}

int main()
{
    GenericSorter<Student> sorter;
    vector<Student> students = {Student("Bob", 3.5), Student("Alice", 3.8), Student("David", 3.2), Student("Charlie", 3.9)};

    cout << "Original list:" << endl;
    for (const auto &student : students)
    {
        student.print();
    }

    sorter.insertionSort(students, compareByName);
    cout << "\nSorted by name:" << endl;
    for (const auto &student : students)
    {
        student.print();
    }

    sorter.insertionSort(students, compareByGPA);
    cout << "\nSorted by GPA:" << endl;
    for (const auto &student : students)
    {
        student.print();
    }

    return 0;
}