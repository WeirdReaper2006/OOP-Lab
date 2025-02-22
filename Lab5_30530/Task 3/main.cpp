// Create a program to simulate basic cache replacement strategies using inheritance:
// 1. Base Class: Cache
// a. Attributes:
// i. capacity (maximum items)
// ii. currentItems (list of cached items)

// b. Methods:
// i. void addItem(int item) (adds item to cache)
// ii. void printCache() (displays current cached items)

// 2. Derived Classes (Implement specific replacement strategies):
// a. FIFOCache: First-In-First-Out
// i. Evicts the oldest item when cache is full

// b. LRUCache: Least Recently Used
// i. Evicts the least recently accessed item when cache is full

#include <iostream>
#include <vector>
using namespace std;

class Cache
{
protected:
    int capacity;
    vector<int> currentItems;

public:
    Cache(int capacity)
    {
        this->capacity = capacity;
    }

    void addItem(int item)
    {
        if (currentItems.size() < capacity)
        {
            currentItems.push_back(item);
        }
    }

    void printCache()
    {
        for (int i = 0; i < currentItems.size(); i++)
        {
            cout << currentItems[i] << " ";
        }
        cout << endl;
    }
};

class FIFOCache : public Cache
{
public:
    FIFOCache(int capacity) : Cache(capacity) {}

    void addItem(int item)
    {
        if (currentItems.size() < capacity)
        {
            currentItems.push_back(item);
        }
        else
        {
            currentItems.erase(currentItems.begin());
            currentItems.push_back(item);
        }
    }
};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity) : Cache(capacity) {}

    void addItem(int item)
    {
        if (currentItems.size() < capacity)
        {
            currentItems.push_back(item);
        }
        else
        {
            currentItems.erase(currentItems.begin());
            currentItems.push_back(item);
        }
    }
};

int main()
{
    FIFOCache fifo(3);
    fifo.addItem(1);
    fifo.addItem(2);
    fifo.addItem(3);
    fifo.printCache();
    fifo.addItem(4);
    fifo.printCache();

    LRUCache lru(3);
    lru.addItem(1);
    lru.addItem(2);
    lru.addItem(3);
    lru.printCache();
    lru.addItem(4);
    lru.printCache();

    return 0;
}