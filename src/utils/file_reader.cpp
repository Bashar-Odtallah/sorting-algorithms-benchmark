#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void readArray(const string &filename, int arr[], int n)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Couldn't open the file with the name '" << filename << "'" << endl;
    }

    for (int i{0}; i < n; i++)
    {
        file >> arr[i];
    }

    file.close();
};