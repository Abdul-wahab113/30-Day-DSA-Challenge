#include <iostream>
#include <chrono>
#include <cstdlib>  // for rand()
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimization: break if already sorted
        if (!swapped)
            break;
    }
}

int main()
{
    const int arrSize = 100;
    int arr[arrSize];

    // Fill array with random numbers
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 1000;  // numbers between 0–999
    }

    // Displaying unsorted array
    cout << "Given random unsorted array :" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto startTime = high_resolution_clock::now();

    bubbleSort(arr, arrSize);

    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);

    // Displaying sorted array
    cout << "Bubble Sorted array :" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken to sort the given array: " 
         << duration.count() << " µs" << endl;

    return 0;
}
