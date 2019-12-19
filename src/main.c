#include "fitting.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    double a = 0.0;
    double b = 0.0;

    double x[] = {1.21, 3, 5.16, 8.31, 10.21};
    double y[] = {1.69, 5.89, 4.11, 5.49, 8.65};

    printf("\nData:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("[%g, %g] ", x[i], y[i]);
    }

    least_squares(x, y, 5, &a, &b);
    printf("\ny = %gx + %g\n", a, b);

    double val = 12.32;
    printf("\nValue at %g: y = %g * %g + %g = %g\n\n", val, a, val, b, (a * val + b));
    return 0;
}