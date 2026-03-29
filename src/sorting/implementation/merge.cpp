#include "../header/merge.hpp"

void merge(int arr[], int first, int mid, int last)
{

    int tempArray[100000];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first;

    while (first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] < arr[first2])
        {
            tempArray[index] = arr[first1];
            first1++;
        }
        else
        {
            tempArray[index] = arr[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1)
    {
        tempArray[index] = arr[first1];
        first1++;
        index++;
    }

    while (first2 <= last2)
    {
        tempArray[index] = arr[first2];
        first2++;
        index++;
    }

    for (int i = first; i <= last; i++)
        arr[i] = tempArray[i];
}

void mergeSortV1(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSortV1(arr, first, mid);
        mergeSortV1(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void merge_V1(int arr[], int n)
{
    mergeSortV1(arr, 0, n - 1);
}