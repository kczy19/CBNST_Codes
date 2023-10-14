#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    return x*x*x - 5*x + 1;
}

int main()
{
    float a, b;
    printf("Enter Interval [a,b]: ");
    scanf("%f%f", &a, &b);
    float err, x;
    int cnt = 1;
    printf("Enter Allowed Error: ");
    scanf("%f", &err);
    do
    {
        x = b - ((a - b) / (fxn(a) - fxn(b))) * fxn(b);
        printf("Iteration %d x = %f fx(%f) = %f\n", cnt++, x, x, fxn(x));
        a = b;
        b = x;
    } while (fabsf(fxn(x)) >= err);
    printf("Approximated Root: %f\n", x);
}