#include "data_stat.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double mean(double *data, int n) {
    double min_v = 0;

    for (int i = 0; i < n; i++) {
        min_v += data[i] / (double)n;
    }
    return (min_v);
}

double variance(double *data, int n) {
    double variance_v = 0;
    double mat_1 = mean(data, n);
    for (int i = 0; i < n; i++) {
        variance_v += ((data[i] - mat_1) * (data[i] - mat_1)) / (double)n;
    }
    return (variance_v);
}

double min(double *data, int n) {
    double min_v = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min_v) {
            min_v = data[i];
        }
    }
    return (min_v);
}

double max(double *data, int n) {
    double max_v = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max_v) {
            max_v = data[i];
        }
    }
    return (max_v);
}
