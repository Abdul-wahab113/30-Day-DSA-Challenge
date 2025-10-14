#include <iostream>
using namespace std;

int binarySearch(int arr[], int arrSize, int element)
{

    int first = 0;
    int last = arrSize - 1;

   

    while (first < last)
    {
        int mid = (first + last) / 2;

        if (element == arr[mid])
        {
            return mid;
        }

        else if (element > arr[mid])
        {
            first = mid + 1;
        }

        else if (element < arr[mid])
        {
            last = mid - 1;
        }

        else
        
            return -1;
        
    }
}

int main()
{

    int arr[5];
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter the Sorted " << arrSize << " of the Array :" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "Array Elements :" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    int element;
    cout << "Enter the Element you want to search in the array :" << endl;
    cin >> element;

    int result = binarySearch(arr, arrSize, element);

    if (result == -1)
    {
        cout << "The Element :" << element << " you entered to search from the array is not found !" << endl;
    }

    else
    {
        cout << "The Element :" << element << " you entered to search from the array is found at index : " << result << endl;
    }

    return 0;
}