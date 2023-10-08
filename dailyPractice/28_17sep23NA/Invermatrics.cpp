#include <iostream>
#include <cmath>

using namespace std;

double determinant3x3(double matrix[3][3]) {
    double det = 0.0;
    for (int i = 0; i < 3; i++) {
        det += matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]);
    }
    return det;
}

bool inverse3x3Matrix(double matrix[3][3], double result[3][3]) {
    double det = determinant3x3(matrix);

    if (std::abs(det) < 1e-10) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = (matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3] - matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3]) / det;
        }
    }

    return true;
}

int main() {
    double matrix[3][3] = {{2, 1, 1}, {1, 3, 2}, {1, 0, 0}};
    double result[3][3];

    if (inverse3x3Matrix(matrix, result)) {
        cout << "Original Matrix:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Inverse Matrix:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "The matrix is not invertible (determinant is zero or nearly zero)." << endl;
    }

    return 0;
}
