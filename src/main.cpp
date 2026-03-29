#include <iostream>
#include <iomanip>
#include <chrono>

#include "sorting/header/bubble.hpp"
#include "sorting/header/insertion.hpp"
#include "sorting/header/merge.hpp"
#include "sorting/header/selection.hpp"
#include "utils/header/file_reader.hpp"

using namespace std;
using namespace std::chrono;

const int SIZE = 100000;

double measureTime(void (*sortFunc)(int[], int), int src[], int n)
{
    int temp[SIZE];
    copyArray(src, temp, n);

    auto start = high_resolution_clock::now();
    sortFunc(temp, n);
    auto end = high_resolution_clock::now();

    return duration<double, milli>(end - start).count();
}

void runAndPrint(const string &label, int arr[], int n)
{
    cout << "\n"
         << label << "\n";

    pair<string, void (*)(int[], int)> algorithms[] = {
        {"bubble_V1", bubble_V1},
        {"bubble_V2", bubble_V2},
        {"insertion_V1", insertion_V1},
        {"insertion_V2", insertion_V2},
        {"merge_V1", merge_V1},
        {"merge_V2", merge_V2},
        {"selection_V1", selection_V1},
        {"selection_V2", selection_V2},
    };

    for (auto &[name, func] : algorithms)
    {
        double time = measureTime(func, arr, n);
        cout << left << setw(15) << name << " : "
             << fixed << setprecision(3) << time << " ms\n";
    }
}

int main()
{
    int randomArr[SIZE];
    int ascArr[SIZE];
    int descArr[SIZE];

    readArray("../data/random_array.txt", randomArr, SIZE);
    readArray("../data/sorted_ascending.txt", ascArr, SIZE);
    readArray("../data/sorted_descending.txt", descArr, SIZE);

    runAndPrint("Random Array", randomArr, SIZE);
    runAndPrint("Sorted Ascending Array", ascArr, SIZE);
    runAndPrint("Sorted Descending Array", descArr, SIZE);

    return 0;
}