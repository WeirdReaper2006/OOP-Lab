#include <iostream>
#include <list>
#include <string>
#include "../headers/process.h" // Include the header file for the Process class

using namespace std;

// Custom Scheduling Algorithms
class ProcessComparator
{
public:
    bool operator()(const Process &a, const Process &b)
    {
        if (a.getPriority() != b.getPriority())
            return a.getPriority() < b.getPriority();

        // If priorities are the same, sort by remaining time
        if (a.getRemainingTime() != b.getRemainingTime())
            return a.getRemainingTime() < b.getRemainingTime();

        // If remaining times are the same, sort by arrival time
        return a.getArrivalTime() < b.getArrivalTime();
    }
};