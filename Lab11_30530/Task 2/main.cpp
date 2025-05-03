// A school is trying to take an annual photo of all the students. For the photo, students are required to stand in a
// straight line in non‐decreasing order by height. You are given an integer array heights representing the current order
// in which the students are standing. Each heights[i] represents the height (in inches) of the i‐th student in line.
// Your task is to determine how many students are not standing in the correct position according to the required
// height order.
// To solve this problem:
// 1. Use Counting Sort on the heights array to create a new array expected, representing how the students
// should be ordered (i.e., in non‐decreasing order).
// 2. Compare the original heights array with the sorted expected array.
// 3. Return the number of indices where heights[i] != expected[i].
// Example:
// Input: heights = [1, 1, 4, 2, 1, 3]
// Output: 3
// Note: You must solve this problem using counting sort for efficiency, as the range of possible heights is small and bounded.

#include <iostream>
#include <vector>

using namespace std;

void countingSort(const vector<int> &heights, vector<int> &expected)
{
    int maxHeight = 0;
    for (int height : heights)
    {
        if (height > maxHeight)
        {
            maxHeight = height;
        }
    }

    vector<int> count(maxHeight + 1, 0);
    for (int height : heights)
    {
        count[height]++;
    }

    int index = 0;
    for (int i = 0; i <= maxHeight; i++)
    {
        while (count[i] > 0)
        {
            expected[index++] = i;
            count[i]--;
        }
    }
}

int countStudentsNotInCorrectPosition(const vector<int> &heights)
{
    vector<int> expected(heights.size());
    countingSort(heights, expected);

    int count = 0;
    for (size_t i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            count++;
        }
    }

    return count;
}
int main()
{
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = countStudentsNotInCorrectPosition(heights);
    cout << "Number of students not in correct position: " << result << endl;
    return 0;
}