// Implement an AlgorithmAnalyzer class that:
// • Stores a collection of Algorithm objects in a vector.

// • Includes the following methods:
// o registerAlgorithm: Adds a new algorithm to the system
// o removeAlgorithm: Removes an algorithm by ID
// o getAlgorithmsByCategory: Returns algorithms filtered by category using ranges
// o benchmarkAlgorithm: Runs an algorithm with various input sizes and records performance
// o compareAlgorithms: Compares multiple algorithms on the same input data
// o getAlgorithmsByComplexity: Uses ranges to filter algorithms by time complexity

#ifndef ALGORITHM_ANALYZER_H
#define ALGORITHM_ANALYZER_H

#include <iostream>
#include <vector>
#include <string>
#include "algorithm.h"

using namespace std;

// AlgorithmAnalyzer Class
class AlgorithmAnalyzer
{
private:
    vector<Algorithm<int>> algorithms;
    vector<BenchmarkResult> results;

public:
    void registerAlgorithm(const Algorithm<int> &algo)
    {
        algorithms.push_back(algo);
    }

    void removeAlgorithm(const string &id)
    {
        algorithms.erase(remove_if(algorithms.begin(), algorithms.end(),
                                   [&](const Algorithm<int> &a)
                                   { return a.getId() == id; }),
                         algorithms.end());
    }

    auto getAlgorithmsByCategory(const string &category)
    {
        return algorithms | views::filter([&](const Algorithm<int> &a)
                                          { return a.getCategory() == category; });
    }

    auto getAlgorithmsByComplexity(const string &complexity)
    {
        return algorithms | views::filter([&](const Algorithm<int> &a)
                                          { return a.getTimeComplexity() == complexity; });
    }

    BenchmarkResult benchmarkAlgorithm(const Algorithm<int> &algo, vector<int> data)
    {
        auto start = chrono::high_resolution_clock::now();
        try
        {
            algo.run(data);
        }
        catch (...)
        {
            return {algo.getId(), static_cast<int>(data.size()), chrono::microseconds(0), false};
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        BenchmarkResult result = {algo.getId(), static_cast<int>(data.size()), duration, true};
        results.push_back(result);
        return result;
    }

    void compareAlgorithms(const vector<Algorithm<int>> &algos, vector<int> data)
    {
        for (const auto &algo : algos)
        {
            BenchmarkResult result = benchmarkAlgorithm(algo, data);
            cout << algo.getName() << " took " << result.executionTime.count() << " microseconds\n";
        }
    }
};

#endif