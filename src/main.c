#include "fitting.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    double x[] = {1.21, 3, 5.16, 8.31, 10.21};
    double y[] = {1.69, 5.89, 4.11, 5.49, 8.65};

    printf("\nDatos:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("[%g, %g] ", x[i], y[i]);
    }

    least_squares(x, y, 5);
    return 0;
}