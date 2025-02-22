// Design a class hierarchy to model zoo animals with basic behaviors and feeding requirements:
// 1. Base Class Animal
// a. Properties:
// i. name (string)
// ii. age (int ≥ 0)

// b. Methods:
// i. void makeSound() (default: "makes a generic animal sound!")
// ii. void displayInfo() (shows name and age)

// 2. Subclasses:
// a. Lion (inherits Animal):
// i. Overrides makeSound() to print "[name] roars loudly!"
// ii. Overrides displayInfo() to prefix output with "Lion"

// b. Snake (inherits Animal):
// i. Adds property: venomous (bool)
// ii. Overrides makeSound() to print "[name] hisses softly!"
// iii. Overrides displayInfo() to show venom status

// c. Monkey (inherits Animal):
// i. Make your own implementation

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string name, int age)
    {
        this->name = name;
        while (age < 0)
        {
            cout << "Please enter a valid age: ";
            cin >> age;
        }
        this->age = age;
    }

    void makeSound(string sound = "makes a generic animal sound!")
    {
        cout << sound << endl;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Lion : public Animal
{
public:
    Lion(string name, int age) : Animal(name, age) {}

    void makeSound()
    {
        cout << name << " roars loudly!" << endl;
    }

    void displayInfo()
    {
        cout << "Lion" << endl;
        Animal::displayInfo();
    }
};

class Snake : public Animal
{
private:
    bool venomous;

public:
    Snake(string name, int age, bool venomous) : Animal(name, age)
    {
        this->venomous = venomous;
    }

    void makeSound()
    {
        cout << name << " hisses softly!" << endl;
    }

    void displayInfo()
    {
        cout << "Snake" << endl;
        Animal::displayInfo();
        cout << "Venomous: " << (venomous ? "Yes" : "No") << endl;
    }
};

class Monkey : public Animal
{
public:
    Monkey(string name, int age) : Animal(name, age) {}

    void makeSound()
    {
        cout << name << "eeh eeh aah aah" << endl;
    }

    void displayInfo()
    {
        cout << "Monkey" << endl;
        Animal::displayInfo();
    }
};

int main()
{
    Lion lion("lion1", 5);
    Snake snake("snake1", 3, true);
    Monkey monkey("monkey1", 2);

    lion.displayInfo();
    lion.makeSound();
    cout << endl;

    snake.displayInfo();
    snake.makeSound();
    cout << endl;

    monkey.displayInfo();
    monkey.makeSound();
    cout << endl;

    return 0;
}