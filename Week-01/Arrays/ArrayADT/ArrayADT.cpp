#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

class ArrayADT
{
private:
    int arr[100];
    int size;

public:
    ArrayADT()
    {
        size = 0;
    }

    // Input elements manually
    void inputArray()
    {
        cout << "\nEnter size of array (max 100): ";
        cin >> size;

        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // Fill array with random numbers
    void fillRandom(int range = 100)
    {
        cout << "\nEnter size of array (max 100): ";
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % range;
        }

        cout << "\nRandom array generated.\n";
    }

    // Display array elements
    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Reverse array
    void reverse()
    {
        int first = 0, last = size - 1;
        while (first < last)
        {
            int temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
            first++;
            last--;
        }
        cout << "Array reversed successfully.\n";
    }

    // Find second largest element
    void findSecondLargest()
    {
        if (size < 2)
        {
            cout << "Need at least 2 elements!\n";
            return;
        }

        int largest = arr[0];
        int secondLargest = arr[0];
        bool hasSecond = false;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] > largest)
            {
                secondLargest = largest;
                largest = arr[i];
                hasSecond = true;
            }
            else if (arr[i] < largest && (!hasSecond || arr[i] > secondLargest))
            {
                secondLargest = arr[i];
                hasSecond = true;
            }
        }

        cout << "\nLargest: " << largest << endl;
        if (hasSecond)
            cout << "Second Largest: " << secondLargest << endl;
        else
            cout << "No second largest found.\n";
    }

    // Print unique elements
    void printUniqueElements()
    {
        cout << "\nUnique elements:\n";
        for (int i = 0; i < size; i++)
        {
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                    count++;
            }
            if (count == 1)
                cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Bubble sort
    void bubbleSort()
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
            if (!swapped)
                break;
        }
        cout << "\nArray sorted using Bubble Sort.\n";
    }

    // Selection sort
    void selectionSort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "\nArray sorted using Selection Sort.\n";
    }

    // Intersection with another array
    void intersection(int arr2[], int size2)
    {
        cout << "\nIntersection of arrays:\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (arr[i] == arr2[j])
                {
                    cout << arr[i] << " ";
                }
            }
        }
        cout << endl;
    }

    // Union with another array
    void unionWith(int arr2[], int size2)
    {
        cout << "\nUnion of arrays:\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        for (int j = 0; j < size2; j++)
        {
            bool found = false;
            for (int i = 0; i < size; i++)
            {
                if (arr2[j] == arr[i])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << arr2[j] << " ";
        }
        cout << endl;
    }

    // Get maximum element
    int getMax()
    {
        int maxVal = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    // Get minimum element
    int getMin()
    {
        int minVal = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < minVal)
                minVal = arr[i];
        }
        return minVal;
    }

    // Get average value
    double getAverage()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += arr[i];

        return static_cast<double>(sum) / size;
    }
};

// =================== MAIN FUNCTION ===================
int main()
{
    ArrayADT array;
    int choice;

    do
    {
        cout << "\n========== ARRAY ADT MENU ==========\n";
        cout << "1. Input Array\n";
        cout << "2. Fill Random Array\n";
        cout << "3. Display Array\n";
        cout << "4. Reverse Array\n";
        cout << "5. Find Second Largest\n";
        cout << "6. Print Unique Elements\n";
        cout << "7. Bubble Sort\n";
        cout << "8. Selection Sort\n";
        cout << "9. Intersection with Another Array\n";
        cout << "10. Union with Another Array\n";
        cout << "11. Find Maximum Element\n";
        cout << "12. Find Minimum Element\n";
        cout << "13. Find Average Value\n";
        cout << "0. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            array.inputArray();
            break;
        case 2:
            array.fillRandom();
            break;
        case 3:
            cout << "\nArray Elements:\n";
            array.display();
            break;
        case 4:
            array.reverse();
            break;
        case 5:
            array.findSecondLargest();
            break;
        case 6:
            array.printUniqueElements();
            break;
        case 7:
            array.bubbleSort();
            break;
        case 8:
            array.selectionSort();
            break;
        case 9:
        {
            int size2;
            cout << "\nEnter size of 2nd array: ";
            cin >> size2;
            int arr2[100];
            cout << "Enter elements of 2nd array:\n";
            for (int i = 0; i < size2; i++)
                cin >> arr2[i];
            array.intersection(arr2, size2);
            break;
        }
        case 10:
        {
            int size2;
            cout << "\nEnter size of 2nd array: ";
            cin >> size2;
            int arr2[100];
            cout << "Enter elements of 2nd array:\n";
            for (int i = 0; i < size2; i++)
                cin >> arr2[i];
            array.unionWith(arr2, size2);
            break;
        }
        case 11:
            cout << "Maximum element: " << array.getMax() << endl;
            break;
        case 12:
            cout << "Minimum element: " << array.getMin() << endl;
            break;
        case 13:
            cout << "Average value: " << array.getAverage() << endl;
            break;
        case 0:
            cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
