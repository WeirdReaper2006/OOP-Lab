// Implement a generic functor insertion_sort that takes in an std::vector<T>& and sorts it (in place) using insertion sort.

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class insertion_sort
{
public:
    void operator()(std::vector<T> &vec)
    {
        for (size_t i = 1; i < vec.size(); ++i)
        {
            T key = vec[i];
            size_t j = i;
            while (j > 0 && vec[j - 1] > key)
            {
                vec[j] = vec[j - 1];
                --j;
            }
            vec[j] = key;
        }
    };
};

#endif