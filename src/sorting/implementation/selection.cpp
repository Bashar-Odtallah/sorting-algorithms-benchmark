void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
void selection_V1(int arr[], int n)
{
    for (int last = n - 1; last >= 1; --last)
    {
        // Assume first element is largest
        int largestIndex = 0;

        // Find index of largest element in arr[0..last]
        for (int p = 1; p <= last; ++p)
        {
            if (arr[p] > arr[largestIndex])
            {
                largestIndex = p;
            }
        }

        // Swap largest element with arr[last]
        swap(arr[largestIndex], arr[last]);
    }
}
void selection(int Data[], int n)
{
    for (int first = 0; first < n - 1; ++first)
    {
        int smallestIndex = first;

        // Find index of smallest element in Data[first..n-1]
        for (int p = first + 1; p < n; ++p)
        {
            if (Data[p] < Data[smallestIndex])
            {
                smallestIndex = p;
            }
        }

        // Only swap if needed
        if (smallestIndex != first)
        {
            swap(Data[first], Data[smallestIndex]);
        }
    }
}
