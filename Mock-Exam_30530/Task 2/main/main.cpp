// You are tasked in making a process scheduler simulation using the list container from the standard library.

// Process Class
// Create a Process class with the following attributes:
// • pid (int): Process identifier.
// • name (string): Process name.
// • priority (int): Process priority (lower number means higher priority).
// • state (string: Ready, Running, Blocked, Terminated).
// • burstTime (int): CPU time required to complete the process.*
// • arrivalTime (int): Time when process arrives in the system.*
// • remainingTime (int): Remaining execution time.*
// • resources (std::list<int>): List of resource IDs being used by the process.*

// Scheduler Class
// Implement a Scheduler class that:
// Uses std::list<Process> to store processes.
// • Provides the following methods:
// o addProcess: Adds a new process to the scheduler
// o removeProcess: Removes a process by PID
// o updateProcessState: Updates a process's state
// o allocateResource: Assigns a resource to a process
// o releaseResource: Releases a resource from a process
// o displayProcessDetails: Shows details for a specific process
// o displayAllProcesses: Shows a summary of all processes
// o getProcessByPid: Returns a reference to a process with a specific PID
// o getProcessesByState: Returns a list of processes in a specific state

// Custom Scheduling Algorithms
// Implement the following scheduling algorithms:
// Create a functor ProcessComparator that can sort processes by multiple criteria:
// • Primary: priority
// • Secondary: remaining time (shortest first)
// • Tertiary: arrival time (earliest first)

// Add the following scheduling methods to the Scheduler class:
// • scheduleByPriority: Uses your custom merge sort with the ProcessComparator
// • scheduleByShortestJobFirst: Sorts processes by burst time
// • scheduleByRoundRobin: Rotates through processes with a given time quantum

// Main Program Requirements
// Write a main function that:
// • Creates at least 10 processes with varying priorities, burst times, and arrival times.
// • Demonstrates all scheduling algorithms
// • Handles process creation, execution, and termination in a simulation loop
// • Shows the scheduling algorithms in action with before/after displays
// • Ensures proper memory management throughout
// • Implements error handling for edge cases
// *Assume input data to be anything.

#include <iostream>
#include <list>
#include <string>
#include "../headers/process.h"   // Include the header file for the Process class
#include "../headers/scheduler.h" // Include the header file for the Scheduler class

using namespace std;

// Main function
int main()
{
    Scheduler scheduler;

    // Create processes
    for (int i = 1; i <= 10; ++i)
    {
        Process p(i, "Process" + to_string(i), rand() % 10 + 1, "Ready", rand() % 20 + 1, rand() % 5);
        scheduler.addProcess(p);
    }

    // Display all processes
    cout << "All Processes:" << endl;
    scheduler.displayAllProcesses();

    // Schedule by priority
    cout << "\nScheduling by Priority:" << endl;
    scheduler.scheduleByPriority();
    scheduler.displayAllProcesses();

    // Schedule by shortest job first
    cout << "\nScheduling by Shortest Job First:" << endl;
    scheduler.scheduleByShortestJobFirst();
    scheduler.displayAllProcesses();

    // Schedule by round robin with a time quantum of 3
    cout << "\nScheduling by Round Robin (Time Quantum = 3):" << endl;
    scheduler.scheduleByRoundRobin(3);

    return 0;
}