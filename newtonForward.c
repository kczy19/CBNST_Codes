#include <stdio.h>
void newtonFor(int n, float x[], float y[n][n])
{
    float x0;
    scanf("%f", &x0);
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n - j; ++i)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%f ", x[i]);
        for (int j = 0; j <= i; ++j)
        {
            printf("%f\t", y[i - j][j]);
        }
        printf("\n");
    }
    float p = 1.0;
    float sum = y[0][0];
    float h = x[1] - x[0];
    float u = (x0 - x[0]) / h;

    for (int j = 1; j < n; ++j)
    {
        p = p * (u - j + 1) / j;
        sum += (p * y[0][j]);
    }
    printf("%f", sum);
}
int main()
{
    // dimag mat lagana bilkul
    int n;
    scanf("%d", &n);
    float x[n];
    float y[n][n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%f", &x[i]);
        scanf("%f", &y[i][0]);
    }
    newtonFor(n, x, y);
}