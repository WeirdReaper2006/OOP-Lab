// Implement a generic functor selection_sort that takes in an std::vector<T>& and sorts it (in place) using selection sort.

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class selection_sort
{
public:
    void operator()(std::vector<T> &vec)
    {
        int n = vec.size();
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j] < vec[minIndex])
                {
                    minIndex = j;
                }
            }
            T temp = vec[i];
            vec[i] = vec[minIndex];
            vec[minIndex] = temp;
        }
    }
};

#endif