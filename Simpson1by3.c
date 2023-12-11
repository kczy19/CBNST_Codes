#include <stdio.h>
#include <math.h>

float trapozidel(float datax[], float datay[], int n)
{
    float h = fabs(datax[1] - datax[0]);
    float result = 0.0;
    for (int i = 1; i < n - 1; i++)
    {
        result += h * datay[i];
    }
    result += (h * (datay[0] + datay[n - 1])) / 2;

    return result;
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

    float res = trapozidel(datax, datay, n);
    printf("area under the curve for trapozidel integration is %f:", res);
}
