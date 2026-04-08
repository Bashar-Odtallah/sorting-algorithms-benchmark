#include "../header/quick.hpp"
#include <cstdlib>  // for rand()
#include <ctime>    // for srand()
#include <algorithm>

// ------------------------- Partition (Hoare) -------------------------
int partition(int T[], int first, int last)
{
    int pivot = T[first];
    int bottom = first;
    int top = last;
    int cutPoint;

    while (true)
    {
        while (T[top] > pivot) top--;
        while (T[bottom] < pivot) bottom++;

        if (bottom < top)
        {
            int temp = T[bottom];
            T[bottom] = T[top];
            T[top] = temp;
        }
        else
        {
            cutPoint = top;
            break;
        }
    }

    return cutPoint;
}

// ------------------------- Randomized Partition -------------------------
int randomizedPartition(int T[], int first, int last)
{
    int pivotIndex = first + rand() % (last - first + 1);
    std::swap(T[first], T[pivotIndex]);
    return partition(T, first, last);
}

// ------------------------- QuickSort V1 (original) -------------------------
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

// ------------------------- Insertion Sort for Small Arrays -------------------------
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

// ------------------------- QuickSort V2 (Improved) -------------------------
void quickSortV2(int T[], int first, int last)
{
    if (first < last)
    {
        // Use insertion sort for small subarrays
        if (last - first <= 10)
        {
            insertionForQuick(T, first, last);
            return;
        }

        int cut = randomizedPartition(T, first, last); // Randomized pivot
        quickSortV2(T, first, cut);
        quickSortV2(T, cut + 1, last);
    }
}

void quick_V2(int arr[], int n)
{
    srand(static_cast<unsigned>(time(nullptr))); // Seed random once
    quickSortV2(arr, 0, n - 1);
}