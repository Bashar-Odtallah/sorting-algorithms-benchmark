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