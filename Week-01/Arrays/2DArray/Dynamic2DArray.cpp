#include <iostream>
#include <random>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    void fillRandom(int limit = 10) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand() % limit;
            }
        }
    }

    void fillSequential() {
        int value = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = value++;
            }
        }
    }

    void print(const string &label) {
        cout << "\n" << label << ":\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix multiply(Matrix &B) {
        if (cols != B.rows) {
            cout << "Matrix multiplication not possible!" << endl;
            exit(0);
        }

        Matrix result(rows, B.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * B.data[k][j];
                }
            }
        }

        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    srand(time(0));

    // ----- 1️ Fixed-size Multiplication -----
    cout << "\n=== Fixed-Size Matrix Multiplication (3x3 * 3x4) ===\n";
    Matrix A(3, 3);
    Matrix B(3, 4);

    A.fillRandom();
    B.fillRandom();

    Matrix C = A.multiply(B);

    A.print("Matrix A");
    B.print("Matrix B");
    C.print("Matrix C (Result of A * B)");

    // ----- 2️ User-Input Sequential Matrices -----
    cout << "\n=== Sequential Matrices from User Input ===\n";
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and cols for Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and cols for Matrix B: ";
    cin >> rowsB >> colsB;

    Matrix A2(rowsA, colsA);
    Matrix B2(rowsB, colsB);

    A2.fillSequential();
    B2.fillSequential();

    A2.print("Matrix A2");
    B2.print("Matrix B2");

    // ----- 3️ Jagged Matrix -----
    cout << "\n=== Jagged Matrix (Variable Columns) ===\n";
    int jaggedRows;
    cout << "Enter number of rows for jagged matrix: ";
    cin >> jaggedRows;

    int *jaggedCols = new int[jaggedRows];
    int **jaggedMatrix = new int *[jaggedRows];

    for (int i = 0; i < jaggedRows; i++) {
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> jaggedCols[i];

        jaggedMatrix[i] = new int[jaggedCols[i]];

        for (int j = 0; j < jaggedCols[i]; j++) {
            jaggedMatrix[i][j] = rand() % 50;
        }
    }

    cout << "\nJagged Matrix:\n";
    for (int i = 0; i < jaggedRows; i++) {
        for (int j = 0; j < jaggedCols[i]; j++) {
            cout << jaggedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < jaggedRows; i++)
        delete[] jaggedMatrix[i];

    delete[] jaggedMatrix;
    delete[] jaggedCols;

    return 0;
}
