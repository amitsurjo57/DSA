#include <iostream>
using namespace std;

int binarySearch(int arr[], int last, int key)
{
    int si = 0;
    int ei = last;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << "Position: " << binarySearch(arr, 9, key);
}
