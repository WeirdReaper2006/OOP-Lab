// I. Create the derived classes (Spider, Cat, and Fish) with their proper inheritance relationships
// II. Implement collections (using vectors or lists) that store Animals and Pets separately
// III. Test which methods can be called on objects from each collection
// Submission Guidelines:
// ?? Include any challenges you faced and how you overcame them.
// Evaluation Criteria:
// 1. Proper implementation of all the required classes and their relationships.
// 2. Correct use of inheritance, polymorphism, and abstract class.
// 3. Code readability and proper comments.
// 4. Creativity in solving the problems

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Creating the Animal class
class Animal
{
protected:
    int legs;

public:
    // Constructor
    Animal(int legs)
    {
        this->legs = legs;
    }

    // General Methods
    virtual void walk()
    {
        cout << "The animal is walking with " << legs << " legs." << endl;
    };

    virtual void eat()
    {
        cout << "The animal is eating." << endl;
    };
};

// Creating the Pet class
class Pet
{
protected:
    string name;

public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual void play()
    {
        cout << "The pet is playing." << endl;
    };
};

// Creating the derived classes
// Creating the Spider class
class Spider : public Animal
{
public:
    // Constructor
    Spider() : Animal(8)
    {
    }

    // General Methods
    void walk()
    {
        cout << "The spider is walking with " << legs << " legs." << endl;
    };

    void eat()
    {
        cout << "The spider is eating." << endl;
    };
};

// Creating the Cat class
class Cat : public Animal, public Pet
{
public:
    // Constructor
    Cat() : Animal(4)
    {
    }

    Cat(string name) : Animal(4)
    {
        this->name = name;
    }

    // Getter and Setter Methods
    string getName() override
    {
        return name;
    }

    void setName(string name) override
    {
        this->name = name;
    }

    // General Methods
    void play() override
    {
        cout << "The cat is playing." << endl;
    };

    void walk() override
    {
        cout << "The cat is walking with " << legs << " legs." << endl;
    };

    void eat() override
    {
        cout << "The cat is eating." << endl;
    };
};

// Creating the Fish class
class Fish : public Animal, public Pet
{
public:
    // Constructor
    Fish() : Animal(0)
    {
    }

    // Getter and Setter Methods
    string getName() override
    {
        return name;
    }

    void setName(string name) override
    {
        this->name = name;
    }

    // General Methods
    void play() override
    {
        cout << "The fish is playing." << endl;
    };

    void walk() override
    {
        cout << "The fish is swimming." << endl;
    };

    void eat() override
    {
        cout << "The fish is eating." << endl;
    };
};

// Main function
int main()
{
    // Creating a vector of Animals
    vector<Animal *> animals;
    // Adding objects of the derived classes to the Animals collection
    animals.push_back(new Spider());
    animals.push_back(new Cat());
    animals.push_back(new Fish());

    // Testng the methods to call on objects from the Animals collection
    for (Animal *animal : animals)
    {
        animal->walk();
        animal->eat();
    }

    // Creating a vector of Pets
    vector<Pet *> pets;
    // Adding objects of the derived classes to the Pets collection
    pets.push_back(new Cat("Whiskers"));
    pets.push_back(new Fish());

    // Testing the methods to call on objects from the Pets collection
    for (Pet *pet : pets)
    {
        cout << "Name: " << pet->getName() << endl;
        pet->setName("New Name");
        pet->play();
    }

    return 0;
}