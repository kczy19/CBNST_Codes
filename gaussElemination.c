#include <stdio.h>

void forwardElimination(int n, float A[n][n + 1]) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            float factor = A[i][k] / A[k][k];
            for (int j = k; j <= n; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }
}

void backSubstitution(int n, float A[n][n + 1], float x[n]) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
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

    forwardElimination(n, A);

    float x[n];
    backSubstitution(n, A, x);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
