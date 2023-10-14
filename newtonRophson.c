#include <stdio.h>
#include <math.h>

float fxn(float x) {
    return 3 * x - cosf(x) - 1;
}
float dxn(float x){
    return 3 + sinf(x);
}

int main() {
    float x;
    printf("Enter x: ");
    scanf("%f",&x);

    float err;
    int cnt = 1;
    
    printf("Enter Allowed Error: ");
    scanf("%f", &err);

    do {
        if(dxn(x) == 0.0){
            printf("Newton-Raphson method failed: derivative is zero.\n");
            return 1;
        }
        x = x - (fxn(x)/dxn(x));
        printf("Iteration %d x = %f fx(%f) = %f\n", cnt++, x, x, fxn(x));
    } while (fabsf(fxn(x)) >= err);

    printf("Approximated Root: %f\n", x);
}
