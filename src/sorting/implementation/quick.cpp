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