#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int size, int target);

int main() {
    int size;

    cout << "Input size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element of array [" << i << "]: ";
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    delete[] arr;
    return 0;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
