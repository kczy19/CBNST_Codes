#include <stdio.h>
#include <math.h>

float fxn(float x) {
    return x * x - 5;
}

int main() {
    float a, b;
    
    do {
        printf("Enter Interval [a, b]: ");
        scanf("%f%f", &a, &b);
        if (fxn(a) * fxn(b) >= 0) {
            printf("Error in Interval. Please enter a valid interval.\n");
        }
    } while (fxn(a) * fxn(b) >= 0);

    float err, x;
    int cnt = 1;
    
    printf("Enter Allowed Error: ");
    scanf("%f", &err);

    do {
        x = (a*fxn(b)-b*fxn(a))/(fxn(b) - fxn(a));
        printf("Iteration %d x = %f fx(%f) = %f\n", cnt++, x, x, fxn(x));
        if (fxn(x) < 0) {
            a = x;
        } else {
            b = x;
        }
    } while (fabsf(fxn(x)) >= err);

    printf("Approximated Root: %f\n", x);
}
