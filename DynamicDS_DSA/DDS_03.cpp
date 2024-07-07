#include <iostream>

using namespace std;

void dynamic2DArray() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int **arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    cout << "Enter elements for the " << rows << "x" << cols << " array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << "The " << rows << "x" << cols << " array is:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    dynamic2DArray();
    return 0;
}
