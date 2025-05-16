#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <list>
#include <string>
#include "../headers/process.h"           // Include the header file for the Process class
#include "../headers/processComparator.h" // Include the header file for the ProcessComparator class

using namespace std;

// Scheduler Class
class Scheduler
{
public:
    list<Process> processes;

    // Add a new process to the scheduler
    void addProcess(const Process &p)
    {
        processes.push_back(p);
    }

    // Remove a process by PID
    void removeProcess(int pid)
    {
        processes.remove_if([pid](const Process &p)
                            { return p.getPid() == pid; });
    }

    // Update a process's state
    void updateProcessState(int pid, const string &state)
    {
        for (auto &p : processes)
        {
            if (p.getPid() == pid)
            {
                p.setState(state);
                break;
            }
        }
    }

    // Allocate a resource to a process
    void allocateResource(int pid, int resourceId)
    {
        for (auto &p : processes)
        {
            if (p.getPid() == pid)
            {
                p.addResource(resourceId);
                break;
            }
        }
    }

    // Release a resource from a process
    void releaseResource(int pid, int resourceId)
    {
        for (auto &p : processes)
        {
            if (p.getPid() == pid)
            {
                p.removeResource(resourceId);
                break;
            }
        }
    }

    // Display details for a specific process
    void displayProcessDetails(int pid)
    {
        for (const auto &p : processes)
        {
            if (p.getPid() == pid)
            {
                cout << "Process ID: " << p.getPid() << endl;
                cout << "Name: " << p.getName() << endl;
                cout << "Priority: " << p.getPriority() << endl;
                cout << "State: " << p.getState() << endl;
                cout << "Burst Time: " << p.getBurstTime() << endl;
                cout << "Arrival Time: " << p.getArrivalTime() << endl;
                cout << "Remaining Time: " << p.getRemainingTime() << endl;
                cout << "Resources: ";
                for (const auto &res : p.getResources())
                {
                    cout << res << " ";
                }
                cout << endl;
                break;
            }
        }
    }

    // Display a summary of all processes
    void displayAllProcesses()
    {
        for (const auto &p : processes)
        {
            cout << "Process ID: " << p.getPid() << ", Name: " << p.getName() << ", State: " << p.getState() << endl;
        }
    }

    // Get a reference to a process with a specific PID
    Process &getProcessByPid(int pid)
    {
        for (auto &p : processes)
        {
            if (p.getPid() == pid)
            {
                return p;
            }
        }
        throw runtime_error("Process not found");
    }

    // Get a list of processes in a specific state
    list<Process> getProcessesByState(const string &state)
    {
        list<Process> result;
        for (const auto &p : processes)
        {
            if (p.getState() == state)
            {
                result.push_back(p);
            }
        }
        return result;
    }

    // Schedule by priority using custom merge sort
    void scheduleByPriority()
    {
        processes.sort(ProcessComparator());
    }

    // Schedule by shortest job first
    void scheduleByShortestJobFirst()
    {
        processes.sort([](const Process &a, const Process &b)
                       { return a.getBurstTime() < b.getBurstTime(); });
    }

    // Schedule by round robin
    void scheduleByRoundRobin(int timeQuantum)
    {
        list<Process> temp = processes;
        while (!temp.empty())
        {
            Process &p = temp.front();
            if (p.getRemainingTime() > timeQuantum)
            {
                p.setRemainingTime(p.getRemainingTime() - timeQuantum);
                cout << "Process " << p.getPid() << " executed for " << timeQuantum << " units." << endl;
            }
            else
            {
                cout << "Process " << p.getPid() << " completed." << endl;
                temp.pop_front();
            }
            temp.push_back(temp.front());
            temp.pop_front();
        }
    }
};

#endif