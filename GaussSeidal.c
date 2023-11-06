#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the size of the system: ");
    scanf("%d", &n);

    double A[n][n];
    double b[n];
    double x[n]; // Initial guess
    double desired_error;

    // Input matrix A
    printf("Enter the matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Input vector b
    printf("Enter the vector b (%d elements):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Input the desired error
    printf("Enter the desired error: ");
    scanf("%lf", &desired_error);

    int iter = 0;
    double error = desired_error + 1;

    while (error > desired_error) {
        error = 0.0;
        for (int i = 0; i < n; i++) {
            double old_xi = x[i];
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
            error += fabs(x[i] - old_xi);
        }

        iter++;
    }

    printf("Gauss-Seidel converged after %d iterations with an error of %lf:\n", iter, error);
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
