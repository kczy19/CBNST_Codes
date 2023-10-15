#include <stdio.h>

void printMatrix(int n, int m, float matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(int n, float A[n][n + 1]) {
    for (int k = 0; k < n; k++) {
        // Pivot equation
        float pivot = A[k][k];

        // Normalize pivot row
        for (int j = k; j < n + 1; j++) {
            A[k][j] /= pivot;
        }

        // Eliminate other rows
        for (int i = 0; i < n; i++) {
            if (i != k) {
                float factor = A[i][k];
                for (int j = k; j < n + 1; j++) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float A[n][n + 1];

    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    gaussJordan(n, A);

    printf("Reduced Row-Echelon Form (RREF) Matrix:\n");
    printMatrix(n, n + 1, A);

    printf("Solutions:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, A[i][n]);
    }

    return 0;
}
