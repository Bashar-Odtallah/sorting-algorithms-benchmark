#include "../header/quick.hpp"

int partition(int T[], int first, int last)
{
    int pivot = T[first];
    int bottom = first;
    int top = last;
    int loop = 1;
    int cutPoint;

    while (loop)
    {

        while (T[top] > pivot)
            top--;

        while (T[bottom] < pivot)
            bottom++;

        if (bottom < top)
        {

            int temp = T[bottom];
            T[bottom] = T[top];
            T[top] = temp;
        }
        else
        {
            loop = 0;
            cutPoint = top;
        }
    }

    return cutPoint;
}

void quickSortV1(int T[], int first, int last)
{
    if (first < last)
    {
        int cut = partition(T, first, last);
        quickSortV1(T, first, cut);
        quickSortV1(T, cut + 1, last);
    }
}

void quick_V1(int arr[], int n)
{
    quickSortV1(arr, 0, n - 1);
}

void insertionForQuick(int arr[], int first, int last)
{
    for (int i = first + 1; i <= last; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= first && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSortV2(int T[], int first, int last)
{
    if (first < last)
    {
        if (last - first <= 10)
        {
            insertionForQuick(T, first, last);
            return;
        }
        int cut = partition(T, first, last);
        quickSortV2(T, first, cut);
        quickSortV2(T, cut + 1, last);
    }
}

void quick_V2(int arr[], int n)
{
    quickSortV2(arr, 0, n - 1);
}