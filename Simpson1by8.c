#include <stdio.h>
#include <math.h>

float simpone(float x[], float y[], int n)
{
    float ans = 0.0;
    float h = fabs(x[1] - x[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            ans += ((2 * h) * (y[i])) / 3;
        }
        else
        {
            ans += ((4 * h) * (y[i])) / 3;
        }
    }
    ans += (h * (y[0] + y[n - 1])) / 3;
    return ans;
}
int main()
{
    int n;
    float sum = 0.0, h;
    float datax[100];
    float datay[100];
    printf("enter the no of data points :");
    scanf("%d", &n);
    printf("enter the x data points :");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &datax[i]);
    }
    printf("enter the y data points :");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &datay[i]);
    }
    float res = simpone(datax, datay, n);
    printf("area under the curve for simpsons 1/3rd integration is %f", res);
}
