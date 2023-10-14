#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    return cosf(x) - 3 * x + 1;
}
float fifx(float x)
{
    return (cosf(x) + 1) / 3.0;
}
float fidx(float x)
{
    return -(sinf(x) / 3);
}

int main()
{
    float x;
    printf("Enter x: ");
    scanf("%f", &x);

    if (fidx(x) < 1)
    {
        float err;
        int cnt = 1;
        printf("Enter Allowed Error: ");
        scanf("%f", &err);
        do
        {
            printf("Iteration %d x = %f fx(%f) = %f\n", cnt++, x, x, fxn(x));
            x = fifx(x);
        } while (fabsf(fxn(x)) >= err);
    }
    else
    {
        printf("Iteration Method Failed\n");
    }
}