#include "fitting.h"

/**
 * @brief Computes the best-fit linear regression coefficients a and b of the model y = ax + b for the dataset (x,y) by least squares.
 * 
 * @param x x-axis dataset
 * @param y y-axis dataset
 * @param n x and y arrays length
 * @param a regression coefficient
 * @param b regression coefficient
 */
void least_squares(double *x, double *y, int n, double *a, double *b) {

    double xmean   = 0.0;
    double ymean   = 0.0;
    double xsqmean = 0.0;
    double ysqmean = 0.0;
    double pmean   = 0.0;

    *a = 0.0;
    *b = 0.0;

    means(x, y, n, &xmean, &ymean, &xsqmean, &ysqmean, &pmean);

    *a = (pmean - xmean * ymean) / (xsqmean - xmean * xmean);
    *b = ymean - *a * xmean;

    return;
}

/**
 * @brief Computed the mean of an array x with length n.
 * 
 * @param x dataset
 * @param n length
 * @return double mean
 */
double mean(double *x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i];
    }
    return result / n;
}

/**
 * @brief Computed the squared mean of an array x with length n.
 * 
 * @param x dataset
 * @param n length
 * @return double mean
 */
double sqmean(double *x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * x[i];
    }
    return result / n;
}

/**
 * @brief Computed the product mean of arrays x and y with length n.
 * 
 * @param x dataset x
 * @param y dataset y
 * @param n length
 * @return double mean
 */
double product_mean(double *x, double *y, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }
    return result / n;
}

/**
 * @brief Computes the different means needed for the least squares coefficients calculation.
 * 
 * @param x dataset x
 * @param y dataset y
 * @param n length
 * @param xmean dataset x mean
 * @param ymean dataset y mean
 * @param xsqmean dataset x squared mean
 * @param ysqmean dataset y squared mean
 * @param pmean datasets x and y product mean
 */
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