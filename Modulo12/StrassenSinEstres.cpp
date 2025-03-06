#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix splitMatrix(const Matrix &matrix, int row, int col, int size) {
    Matrix subMatrix(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            subMatrix[i][j] = matrix[row + i][col + j];
    return subMatrix;
}

int sumMatrixElements(const Matrix &matrix) {
    int sum = 0;
    for (const auto &row : matrix)
        for (int val : row)
            sum += val;
    return sum;
}

Matrix addMatrices(const Matrix &A, const Matrix &B, int size) {
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix multiplyMatricesRecursive(const Matrix &X, const Matrix &Y, int n, vector<int> &q_values) {
    if (n == 2) {
        Matrix Z(2, vector<int>(2, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    Z[i][j] += X[i][k] * Y[k][j];

        q_values.push_back(sumMatrixElements(Z));
        return Z;
    }

    int mid = n / 2;
    Matrix A = splitMatrix(X, 0, 0, mid);
    Matrix B = splitMatrix(X, 0, mid, mid);
    Matrix C = splitMatrix(X, mid, 0, mid);
    Matrix D = splitMatrix(X, mid, mid, mid);

    Matrix E = splitMatrix(Y, 0, 0, mid);
    Matrix F = splitMatrix(Y, 0, mid, mid);
    Matrix G = splitMatrix(Y, mid, 0, mid);
    Matrix H = splitMatrix(Y, mid, mid, mid);

    Matrix P1 = multiplyMatricesRecursive(A, E, mid, q_values);
    Matrix P2 = multiplyMatricesRecursive(B, G, mid, q_values);
    Matrix P3 = multiplyMatricesRecursive(A, F, mid, q_values);
    Matrix P4 = multiplyMatricesRecursive(B, H, mid, q_values);
    Matrix P5 = multiplyMatricesRecursive(C, E, mid, q_values);
    Matrix P6 = multiplyMatricesRecursive(D, G, mid, q_values);
    Matrix P7 = multiplyMatricesRecursive(C, F, mid, q_values);
    Matrix P8 = multiplyMatricesRecursive(D, H, mid, q_values);

    Matrix Z(n, vector<int>(n));

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            Z[i][j] = P1[i][j] + P2[i][j];
            Z[i][j + mid] = P3[i][j] + P4[i][j];
            Z[i + mid][j] = P5[i][j] + P6[i][j];
            Z[i + mid][j + mid] = P7[i][j] + P8[i][j];
        }

    q_values.push_back(sumMatrixElements(Z));
    return Z;
}

void solveCase(int caseNum) {
    int n;
    cin >> n;

    Matrix X(n, vector<int>(n));
    Matrix Y(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Y[i][j];

    vector<int> q_values;
    multiplyMatricesRecursive(X, Y, n, q_values);

    cout << "caso " << caseNum << ":\n";
    for (int q : q_values)
        cout << q << "\n";
}

int main() {
    int c;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        solveCase(i);
        if (i < c) cout << "\n";  
    }

    return 0;
}
