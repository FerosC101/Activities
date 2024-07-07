#include <iostream>
using namespace std;

void addMatrices(int a[][10], int b[][10], int result[][10], int rows, int cols);

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    int a[10][10], b[10][10], result[10][10];

    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> b[i][j];
        }
    }

    addMatrices(a, b, result, rows, cols);

    cout << "Resultant matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void addMatrices(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}