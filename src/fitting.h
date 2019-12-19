#ifndef _FITTING_H_
#define _FITTING_H_

void   least_squares(double *x, double *y, int n, double *a, double *b);
double mean(double *x, int n);
double sqmean(double *x, int n);
double product_mean(double *x, double *y, int n);
void   means(double *x, double *y, int n, double *xmean, double *ymean, double *xsqmean, double *ysqmean, double *pmean);

#endif // _FITTING_H_