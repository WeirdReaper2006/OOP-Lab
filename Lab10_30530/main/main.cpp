// Implement a class to evaluate the performance of different sorting algorithms using the Stopwatch utility developed in Task 1.
// This task focuses on applying the previously implemented components in a practical benchmarking scenario.
// Create a class responsible for performance testing.
// The class should include a function that accepts a sorting algorithm and
// evaluates its average execution time over multiple runs. Specifically, the function will:
// ● Accept a callable sorting algorithm (such as the functor or function implemented in Tasks 2–5) and an integer N
// denoting the number of test runs.
// ● For each run, generate a new std::vector<int> containing 100,000 randomly generated integers.
// ● Measure the time taken to sort the array using the Stopwatch class.
// ● Accumulate the timings across all runs and return the average execution time.

// The use of std::function or templates is encouraged to support different sorting algorithm types.
// Inside main, invoke this class to benchmark the performance of all three algorithms—insertion_sort, selection_sort, and
// shell_sort—and print their average execution times. Additionally, invoke it with a BinaryTree object, and measure the time.
// Comment on your findings and the time complexity of the various algorithms.

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
#include "../headers/Stopwatch.hpp"
#include "../headers/insertion_sort.hpp"
#include "../headers/selection_sort.hpp"
#include "../headers/shell_sort.hpp"
#include "../headers/binary_tree.hpp"

using namespace std;

template <typename T>
class Performance_Tester
{
public:
    double test_sorting_algorithm(std::function<void(std::vector<T> &)> sorting_algorithm, int N)
    {
        Stopwatch stopwatch;
        double total_time = 0.0;

        for (int i = 0; i < N; ++i)
        {
            std::vector<T> vec(100000);
            std::generate(vec.begin(), vec.end(), []()
                          { return rand() % 100000; });

            stopwatch.start();
            sorting_algorithm(vec);
            stopwatch.stop();

            total_time += stopwatch.get_elapsed_time_seconds();
            stopwatch.reset();
        }

        return total_time / N;
    }

    void print_results(const std::string &algorithm_name, double average_time)
    {
        std::cout << "Average execution time for " << algorithm_name << ": " << average_time << " seconds" << std::endl;
    }

    void run_tests(int N)
    {
        double insertion_sort_time = test_sorting_algorithm(insertion_sort<int>(), N);
        print_results("Insertion Sort", insertion_sort_time);

        double selection_sort_time = test_sorting_algorithm(selection_sort<int>(), N);
        print_results("Selection Sort", selection_sort_time);

        double shell_sort_time = test_sorting_algorithm(shell_sort<int>, N);
        print_results("Shell Sort", shell_sort_time);
    }

    void test_binary_tree(int N)
    {
        Stopwatch stopwatch;
        double total_time = 0.0;
        BinaryTree<int> tree;

        for (int i = 0; i < N; ++i)
        {
            std::vector<int> vec(100000);
            std::generate(vec.begin(), vec.end(), []()
                          { return rand() % 100000; });

            stopwatch.start();
            for (const auto &value : vec)
            {
                tree.insert(value);
            }
            stopwatch.stop();

            total_time += stopwatch.get_elapsed_time_seconds();
            stopwatch.reset();
        }

        std::cout << "Average execution time for Binary Tree: " << (total_time / N) << " seconds" << std::endl;
    }
    void run_tests_with_binary_tree(int N)
    {
        run_tests(N);
        test_binary_tree(N);
    }
};

int main()
{
    Performance_Tester<int> tester;
    tester.run_tests(5);
    tester.test_binary_tree(5);

    return 0;
}

// The average execution times for the sorting algorithms and the binary tree insertion will be printed to the console.
// The time complexity of the algorithms is as follows:
// Insertion Sort: O(n^2)
// Selection Sort: O(n^2)
// Shell_sort: O(n log n)
// Binary Tree Insertion: O(log n) on average, O(n) in the worst case (unbalanced tree)
// The results will show that the shell_sort is significantly faster than the other two algorithms, especially for larger datasets. The binary tree insertion is also efficient, but it depends on the balance of the tree.