#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> row1;
    cin >> col1;

    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> row2;
    cin >> col2;

    if (col1 != row2) 
    {
        cout << "Error: Number of columns in the first matrix must match the number of rows in the second matrix." << endl;
        return 0;
    }

    // Dynamically allocate memory for the matrices
    int** matrix1 = new int* [row1];
    int** matrix2 = new int* [row2];
    int** resultMatrix = new int* [row1];

    for (int i = 0; i < row1; i++) {
        matrix1[i] = new int[col1];
        resultMatrix[i] = new int[col2];
    }

    for (int i = 0; i < row2; i++) {
        matrix2[i] = new int[col2];
    }

    // Input values for the matrices
    cout << "Enter the values for the first matrix: " << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter the values for the second matrix: " << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Output the result matrix
    cout << "The result matrix is: " << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < row1; i++) {
        delete[] matrix1[i];
        delete[] resultMatrix[i];
    }
    for (int i = 0; i < row2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix;

    return 0;
}
