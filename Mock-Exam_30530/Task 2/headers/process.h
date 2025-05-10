#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Process Class
class Process
{
private:
    int pid;
    string name;
    int priority;
    string state;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    list<int> resources;

public:
    // Constructor
    Process(int id, string n, int p, string s, int bt, int at)
        : pid(id), name(n), priority(p), state(s), burstTime(bt), arrivalTime(at), remainingTime(bt) {}

    // Getters
    int getPid() const { return pid; }
    string getName() const { return name; }
    int getPriority() const { return priority; }
    string getState() const { return state; }
    int getBurstTime() const { return burstTime; }
    int getArrivalTime() const { return arrivalTime; }
    int getRemainingTime() const { return remainingTime; }
    list<int> getResources() const { return resources; }

    // Setters
    void setPid(int id) { pid = id; }
    void setName(string n) { name = n; }
    void setPriority(int p) { priority = p; }
    void setState(string s) { state = s; }
    void setBurstTime(int bt) { burstTime = bt; }
    void setArrivalTime(int at) { arrivalTime = at; }
    void setRemainingTime(int rt) { remainingTime = rt; }
    void addResource(int resourceId) { resources.push_back(resourceId); }
    void removeResource(int resourceId)
    {
        resources.remove(resourceId);
    }
};

#endif