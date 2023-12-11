#include <stdio.h>

// Function to calculate the regression line (simple linear regression)
void regressionLine( int n, float x[n], float y[n]) {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    // Calculate sums required for linear regression formulas
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    // Calculate slope and intercept
    float slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    float intercept = (sum_y - slope * sum_x) / n;

    // Display regression line equation
    printf("Regression Line Equation: y = %.4fx + %.4f\n", slope, intercept);
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    // Call the regressionLine function
    regressionLine(n,x, y);

    return 0;
}
