void selectionSwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void selection_V1(int arr[], int n)
{
    for (int last = n - 1; last >= 1; --last)
    {
        int largestIndex = 0;

        for (int p = 1; p <= last; ++p)
        {
            if (arr[p] > arr[largestIndex])
            {
                largestIndex = p;
            }
        }

        selectionSwap(arr[largestIndex], arr[last]);
    }
}
void selection_V2(int arr[], int n)
{
    for (int first = 0; first < n - 1; ++first)
    {
        int smallestIndex = first;

        for (int p = first + 1; p < n; ++p)
        {
            if (arr[p] < arr[smallestIndex])
            {
                smallestIndex = p;
            }
        }

        if (smallestIndex != first)
        {
            selectionSwap(arr[first], arr[smallestIndex]);
        }
    }
}
