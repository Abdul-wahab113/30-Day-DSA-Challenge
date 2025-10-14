#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int> data, int key)
{
    bool result = false;

    for (int element : data)
    {
        if (element == key)
        {
            result = true;
        }
   
    }
    return result;
}

int main()
{

    vector<int> data = {1, 2, 3, 4, 5, 6};

    int key;
    cout << "Enter a key to search from the data :" << endl;
    cin >> key;

    bool result = linearSearch(data, key);

    if (result)
    {
        cout << "The key :" << key << " is found" << endl;
    }
    else
    {
        cout << "The key not found !" << endl;
    }

    return 0;
}