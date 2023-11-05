#include <stdio.h>

// Function to perform Newton's forward interpolation
double newtonForwardInterpolation(double x[], double y[], int n, double x0) {
    double result = 0.0;
    double h = x[1] - x[0];
    double u = (x0 - x[0]) / h;
    double p[n][n];

    // Fill in the first column of the divided difference table
    for (int i = 0; i < n; i++) {
        p[i][0] = y[i];
    }

    // Compute and print the divided difference table
    printf("Divided Difference Table:\n");
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            p[i][j] = (p[i + 1][j - 1] - p[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lf", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("\t%lf", p[i - j][j]);
        }
        printf("\n");
    }

    // Calculate the interpolated value
    for (int j = 0; j < n; j++) {
        double term = p[0][j];
        for (int i = 0; i < j; i++) {
            term *= (u - i);
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double x0;
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x0);

    double interpolatedValue = newtonForwardInterpolation(x, y, n, x0);
    printf("\nInterpolated value at x = %lf is %lf\n", x0, interpolatedValue);

    return 0;
}
