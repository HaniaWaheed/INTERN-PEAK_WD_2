#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int rows;
    int columns;
    int** matrix;

public:
    Matrix(int rowSize, int colSize) : rows(rowSize), columns(colSize)
    {
        matrix = new int* [rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new int[columns]();
        }
    }

    Matrix(const Matrix& m) : rows(m.rows), columns(m.columns)
    {
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix operator*(int scalar) const
    {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result.matrix[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix inverse() const
    {
        if (rows != columns)
        {
            cout << "Error: Only square matrices can be inverted." << endl;
            exit(1);
        }

        Matrix augmented(rows, 2 * columns);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                augmented.matrix[i][j] = matrix[i][j];
                augmented.matrix[i][j + columns] = (i == j) ? 1 : 0;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (augmented.matrix[i][i] == 0)
            {
                for (int j = i + 1; j < rows; j++)
                {
                    if (augmented.matrix[j][i] != 0)
                    {
                        swap(augmented.matrix[i], augmented.matrix[j]);
                        break;
                    }
                }
            }

            int pivot = augmented.matrix[i][i];
            if (pivot == 0)
            {
                cout << "Error: Matrix is singular and cannot be inverted." << endl;
                exit(1);
            }

            for (int j = 0; j < 2 * columns; j++)
            {
                augmented.matrix[i][j] /= pivot;
            }

            for (int j = 0; j < rows; j++)
            {
                if (i != j)
                {
                    int factor = augmented.matrix[j][i];
                    for (int k = 0; k < 2 * columns; k++)
                    {
                        augmented.matrix[j][k] -= factor * augmented.matrix[i][k];
                    }
                }
            }
        }

        Matrix inverse(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                inverse.matrix[i][j] = augmented.matrix[i][j + columns];
            }
        }

        return inverse;
    }

    int determinant() const
    {
        if (rows != columns)
        {
            cout << "Error: Only square matrices have a determinant." << endl;
            exit(1);
        }

        Matrix L(rows, columns);
        Matrix U(*this);

        for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < rows; j++)
            {
                if (U.matrix[i][i] == 0)
                {
                    cout << "Error: Matrix is singular and determinant cannot be computed." << endl;
                    exit(1);
                }

                int factor = U.matrix[j][i] / U.matrix[i][i];
                for (int k = 0; k < columns; k++)
                {
                    U.matrix[j][k] -= factor * U.matrix[i][k];
                    L.matrix[j][i] = factor;
                }
            }
        }

        int det = 1;
        for (int i = 0; i < rows; i++)
        {
            det *= U.matrix[i][i];
        }

        return det;
    }

    friend istream& operator>>(istream& in, Matrix& m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.columns; j++)
            {
                in >> m.matrix[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.columns; j++)
            {
                out << m.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    bool operator==(const Matrix& m) const
    {
        if (rows != m.rows || columns != m.columns)
        {
            return false;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] != m.matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& m) const
    {
        return !(*this == m);
    }

    int& operator()(int row, int col)
    {
        if (row < 0 || row >= rows || col < 0 || col >= columns)
        {
            cout << "Error: Index out of bounds." << endl;
            exit(1);
        }
        return matrix[row][col];
    }

    Matrix operator-() const
    {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result.matrix[i][j] = -matrix[i][j];
            }
        }
        return result;
    }
};

int main()
{
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    cout << "Enter matrix 1 elements:\n";
    cin >> matrix1;

    cout << "Enter matrix 2 elements:\n";
    cin >> matrix2;

    cout << "Matrix 1:\n" << matrix1;
    cout << "Matrix 2:\n" << matrix2;

    cout << "Matrix 1 * 3:\n" << matrix1 * 3;

    if (matrix1.rows == matrix1.columns)
    {
        Matrix inv = matrix1.inverse();
        cout << "Inverse of Matrix 1:\n" << inv;
    }
    else
    {
        cout << "Matrix 1 is not square, cannot compute inverse." << endl;
    }

    if (matrix1.rows == matrix1.columns)
    {
        cout << "Determinant of Matrix 1: " << matrix1.determinant() << endl;
    }
    else
    {
        cout << "Matrix 1 is not square, cannot compute determinant." << endl;
    }

    cout << "Matrix 1 == Matrix 2: " << (matrix1 == matrix2 ? "True" : "False") << endl;
    cout << "Matrix 1 != Matrix 2: " << (matrix1 != matrix2 ? "True" : "False") << endl;

    cout << "Accessing element (0, 0) of Matrix 1: " << matrix1(0, 0) << endl;
    matrix1(0, 0) = 99;
    cout << "Modified Matrix 1:\n" << matrix1;

    cout << "Negating Matrix 1:\n" << -matrix1;

    return 0;
}
