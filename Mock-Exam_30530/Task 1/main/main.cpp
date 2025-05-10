#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <chrono>
#include <random>
#include <ranges>
#include <algorithm>
#include "../headers/benchmarkResult.h"
#include "../headers/algorithm.h"
#include "../headers/algorithmAnalyzer.h"

using namespace std;

// Basic sorting algorithm implementations
void bubbleSort(vector<int> &data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < data.size() - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &data)
{
    for (size_t i = 1; i < data.size(); ++i)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

void quickSortHelper(vector<int> &data, int low, int high)
{
    if (low < high)
    {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (data[j] < pivot)
            {
                ++i;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[high]);
        int pi = i + 1;
        quickSortHelper(data, low, pi - 1);
        quickSortHelper(data, pi + 1, high);
    }
}

void quickSort(vector<int> &data)
{
    quickSortHelper(data, 0, data.size() - 1);
}

void merge(vector<int> &data, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = data[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = data[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            data[k++] = L[i++];
        else
            data[k++] = R[j++];
    }
    while (i < n1)
        data[k++] = L[i++];
    while (j < n2)
        data[k++] = R[j++];
}

void mergeSortHelper(vector<int> &data, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(data, left, mid);
        mergeSortHelper(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

void mergeSort(vector<int> &data)
{
    mergeSortHelper(data, 0, data.size() - 1);
}

int main()
{
    AlgorithmAnalyzer analyzer;

    analyzer.registerAlgorithm({"bubble", "Bubble Sort", "Sorting", "O(n^2)", "O(1)", bubbleSort});
    analyzer.registerAlgorithm({"insertion", "Insertion Sort", "Sorting", "O(n^2)", "O(1)", insertionSort});
    analyzer.registerAlgorithm({"quick", "Quick Sort", "Sorting", "O(n log n)", "O(log n)", quickSort});
    analyzer.registerAlgorithm({"merge", "Merge Sort", "Sorting", "O(n log n)", "O(n)", mergeSort});

    vector<int> data(1000);
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 10000);
    generate(data.begin(), data.end(), [&]()
             { return dist(rng); });

    cout << "Comparing all Sorting Algorithms:\n";
    analyzer.compareAlgorithms({{"bubble", "Bubble Sort", "Sorting", "O(n^2)", "O(1)", bubbleSort},
                                {"insertion", "Insertion Sort", "Sorting", "O(n^2)", "O(1)", insertionSort},
                                {"quick", "Quick Sort", "Sorting", "O(n log n)", "O(log n)", quickSort},
                                {"merge", "Merge Sort", "Sorting", "O(n log n)", "O(n)", mergeSort}},
                               data);

    cout << "\nAlgorithms with O(n log n) Time Complexity:\n";
    for (const auto &a : analyzer.getAlgorithmsByComplexity("O(n log n)"))
    {
        cout << a.getName() << "\n";
    }

    return 0;
}
