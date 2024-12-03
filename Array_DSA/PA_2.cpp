#include <iostream>

using namespace std;

int sum(int arr[], int size);

int main() {
    int size;

    cout << "Input Size of array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element of Array [" <<  i << "]: ";
        cin >> arr[i];
    }

    int ans = sum(arr, size);

    cout << "The sum of the integer is: " << ans;

    return 0;
}

int sum(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

