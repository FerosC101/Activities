#include <iostream>

using namespace std;

void dynamicIntArray() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Elements of the array are: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}

int main() {
    dynamicIntArray();
    return 0;
}
