#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int minimumIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minimumIndex = i; // Assume the first element is the minimum
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minimumIndex])
            {
                minimumIndex = j; // Update minimumIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minimumIndex != i) // Only swap if a smaller element was found
        {
            int temp = arr[i];
            arr[i] = arr[minimumIndex];
            arr[minimumIndex] = temp;
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}