// Find the two repeating elements in a given array (using Array Elements as an Index)

#include <iostream>
using namespace std;
#define INT_MAX 2147483647

void printRepeating(int arr[], int size)
{
    cout << "Repeating elements are ";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == INT_MAX)
            continue;
        if (arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
        {
            cout << abs(arr[i]) << " ";
            arr[i] = INT_MAX; // To avoid printing duplicates
        }
    }
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1, 4, 4, 5, 6, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printRepeating(arr, arr_size);
    return 0;
}