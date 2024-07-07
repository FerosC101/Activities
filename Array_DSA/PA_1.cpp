#include <iostream>

using namespace std;

void reverse(int arr[], int size);

int main() {
    int size;

    cout << "Input Size of array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element of Array [" <<  i << "]: ";
        cin >> arr[i];
    }

    reverse(arr, size);

    cout << "\nReversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int array_storage = arr[start];
        arr[start] = arr[end];
        arr[end] = array_storage;
        start++;
        end--;
    }
}
