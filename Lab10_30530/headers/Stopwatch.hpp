// C++ provides <chrono> for working with time durations, clocks, and time points.
// It allows precise measurement and  manipulation of time intervals.
// The steady_clock is one of the clocks offered by <chrono> and is ideal for measuring time
// intervals because it is not affected by system clock changes.
// The following example demonstrates the usage of steady_clock to measure the time between two points in your program:

// #include <iostream>
// #include <chrono>
// int main() {
// auto start = std::chrono::steady_clock::now();
// /* Code you want to time */
// auto end = std::chrono::steady_clock::now();
// std::chrono::duration<double> elapsed_seconds = end - start;
// std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";
// }

// In this task, you are required to implement a class Stopwatch that will utilize the std::chrono::steady_clock to accurately measure time.
// The class should support the following functions:
// ● A start() method that initiates the timing by recording the current time.
// ● A stop() method that stops the timer and calculates the elapsed time since it was started.
// ● A reset() method that resets the stopwatch to its initial state, allowing for a new timing session.

// Additionally, the class should provide methods to retrieve the elapsed time in different formats:
// ● A method get_elapsed_time_seconds() that returns the time in seconds as a double.
// ● A method get_elapsed_time_milliseconds() that returns the time in milliseconds as a double.

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <iostream>
#include <chrono>

using namespace std;

class Stopwatch
{
private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point end_time;
    bool running = false;

public:
    void start()
    {
        if (!running)
        {
            start_time = std::chrono::steady_clock::now();
            running = true;
        }
    }

    void stop()
    {
        if (running)
        {
            end_time = std::chrono::steady_clock::now();
            running = false;
        }
    }

    void reset()
    {
        running = false;
    }

    double get_elapsed_time_seconds()
    {
        if (running)
        {
            end_time = std::chrono::steady_clock::now();
        }
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        return elapsed_seconds.count();
    }

    double get_elapsed_time_milliseconds()
    {
        if (running)
        {
            end_time = std::chrono::steady_clock::now();
        }
        std::chrono::duration<double, std::milli> elapsed_milliseconds = end_time - start_time;
        return elapsed_milliseconds.count();
    }
};

#endif