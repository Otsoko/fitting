#include "fitting.h"
#include <stdio.h>
#include <string.h>

void least_squares(double *x, double *y, int n) {
    double a = 0.0;
    double b = 0.0;

    double xmean   = mean(x, n);
    double ymean   = mean(y, n);
    double xsqmean = sqmean(x, n);
    double ysqmean = sqmean(y, n);
    double pmean   = product_mean(x, y, n);

    printf("\nSeparated means:\n");
    printf("\n\nxm: %g ym: %g\n", xmean, ymean);
    printf("xsqm: %g ysqm: %g\n", xsqmean, ysqmean);
    printf("pm: %g\n", pmean);

    means(x, y, n, &xmean, &ymean, &xsqmean, &ysqmean, &pmean);

    printf("\nAll means:\n");
    printf("\n\nxm: %g ym: %g\n", xmean, ymean);
    printf("xsqm: %g ysqm: %g\n", xsqmean, ysqmean);
    printf("pm: %g\n", pmean);

    a = (pmean - xmean * ymean) / (xsqmean - xmean * xmean);
    b = ymean - a * xmean;

    printf("\ny = %gx + %g\n", a, b);

    double val = 12.32;
    printf("\nValue at %g: y = %g * %g + %g = %g\n\n", val, a, val, b, (a * val + b));
}

double mean(double *x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i];
    }
    return result / n;
}

double sqmean(double *x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * x[i];
    }
    return result / n;
}

double product_mean(double *x, double *y, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }
    return result / n;
}

void means(double *x, double *y, int n, double *xmean, double *ymean, double *xsqmean, double *ysqmean, double *pmean) {
    *xmean   = 0.0;
    *ymean   = 0.0;
    *xsqmean = 0.0;
    *ysqmean = 0.0;
    *pmean   = 0.0;

    for (int i = 0; i < n; i++) {
        *xmean += x[i];
        *ymean += y[i];
        *xsqmean += x[i] * x[i];
        *ysqmean += y[i] * y[i];
        *pmean += x[i] * y[i];
    }

    *xmean /= n;
    *ymean /= n;
    *xsqmean /= n;
    *ysqmean /= n;
    *pmean /= n;
}