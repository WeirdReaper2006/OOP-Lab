// Implement Radix Sort to sort strings lexicographically.
// Instructions:
// 1. Create a RadixStringSorter class that implements Radix Sort for strings.
// 2. Your implementation should:
// ● Handle strings of different lengths
// ● Sort strings lexicographically (dictionary order)
// ● Account for uppercase and lowercase letters appropriately
// 3. Implement methods to:
// ● Sort in ascending order
// ● Sort in descending order
// ● Allow sorting by specific character positions (e.g., sort by the 3rd character)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RadixStringSorter
{
public:
    static char getCharAt(const string &str, int index)
    {
        if (index < str.size())
            return str[index];
        return '\0'; // Return null character if index is out of bounds
    }

    static void countingSort(vector<string> &arr, int index, bool ascending)
    {
        const int ALPHABET_SIZE = 256; // Extended ASCII size
        vector<int> count(ALPHABET_SIZE, 0);
        vector<string> output(arr.size());

        for (const auto &str : arr)
        {
            char ch = getCharAt(str, index);
            count[ch]++;
        }

        if (ascending)
        {
            for (int i = 1; i < ALPHABET_SIZE; i++)
                count[i] += count[i - 1];
        }
        else
        {
            for (int i = ALPHABET_SIZE - 2; i >= 0; i--)
                count[i] += count[i + 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            char ch = getCharAt(arr[i], index);
            output[count[ch] - 1] = arr[i];
            count[ch]--;
        }

        arr = output;
    }
};

int main()
{
    vector<string> arr = {"apple", "banana", "grape", "kiwi", "orange", "pear"};

    cout << "Original array:\n";
    for (const auto &str : arr)
        cout << str << " ";
    cout << endl;

    RadixStringSorter::countingSort(arr, 0, true); // Sort by the first character in ascending order
    cout << "Sorted array (ascending):\n";
    for (const auto &str : arr)
        cout << str << " ";
    cout << endl;

    RadixStringSorter::countingSort(arr, 0, false); // Sort by the first character in descending order
    cout << "Sorted array (descending):\n";
    for (const auto &str : arr)
        cout << str << " ";
    cout << endl;

    return 0;
}