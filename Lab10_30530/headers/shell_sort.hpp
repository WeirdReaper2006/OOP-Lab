// Implement a generic function shell_sort that takes in an std::vector<T>& and sorts it (in place) using shell sort.

#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void shell_sort(std::vector<T> &vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < vec.size(); i++)
        {
            T temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

#endif