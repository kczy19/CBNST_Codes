#include <stdio.h>
#include <math.h>

float simpthree(float x[], float y[], int n)
{
    float ans = 0.0;
    float h = fabs(x[1] - x[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 3 == 0)
        {
            ans += ((6 * h) * (y[i])) / 8;
        }
        else
        {
            ans += ((9 * h) * (y[i])) / 8;
        }
    }
    ans += ((3 * h) * (y[0] + y[n - 1])) / 8;
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
    float res = simpthree(datax, datay, n);
    printf("area under the curve for simpsons 3/8 integration is %f", res);
}
