#include <stdio.h>


float lagrange(float x, float dataX[], float dataY[], int n) {
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = dataY[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (x - dataX[j]) / (dataX[i] - dataX[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    float x;
    printf("enter the no of elements in the table : ");
    scanf("%d",&n);
    float dataX[100],dataY[100];
    printf("\nEnter the values for the X :");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&dataX[i]);
    }
    printf("\n");
    printf("Enter the values for the Y :");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&dataY[i]);
    }

    printf("enter the value of x for which you need to find Y :");
    scanf("%f",&x);
    float result = lagrange(x, dataX, dataY, n);

    printf("Lagrange interpolation at x = %0.3f is %f\n", x, result);

    return 0;
}
