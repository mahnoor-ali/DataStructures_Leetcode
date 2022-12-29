//LOGIC: If any element in unsorted array is less than element at the beginning, swap them
// O(n^2)

int* selectionSort(int arr[], int size)
{
    int min, temp;
   for (int i = 0; i < size - 1; i++) //last element's iteration not required as its swapped by 2nd last element (stop iteration before (size-1)th index)
    {
        for (int j = i + 1; j < size; j++) //to find minimum in rest of the unsorted array
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}