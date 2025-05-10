// Implement a result logging system
// • Define a BenchmarkResult struct with:
// o algorithmId (string): Tells the ID of the Algo.
// o inputSize (int): The amount of data tested with.
// o executionTime (chrono::microseconds)
// o success (bool): Whether the algorithm executed correctly

#ifndef BENCHMARKRESULT_H
#define BENCHMARKRESULT_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

// BenchmarkResult Struct
struct BenchmarkResult
{
    string algorithmId;
    int inputSize;
    chrono::microseconds executionTime;
    bool success;
};

#endif