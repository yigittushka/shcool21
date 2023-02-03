#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int *pn = &n;
    if (input(data, pn) == 1) {
        return 1;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n <= 0) {
        printf("n/a\n");
        return 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a\n");
                return 1;
                break;
            }
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double min_v = 0;

    for (int *p = a; p - a < n; p++) {
        min_v += *p / (double)n;
    }
    return (min_v);
}

double variance(int *a, int n) {
    double variance_v = 0;
    double mat_1 = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        variance_v += ((*p - mat_1) * (*p - mat_1)) / (double)n;
    }
    return (variance_v);
}

int min(int *a, int n) {
    int min_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min_v) {
            min_v = *p;
        }
    }
    return (min_v);
}

int max(int *a, int n) {
    int max_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max_v) {
            max_v = *p;
        }
    }
    return (max_v);
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);

        if (p - a < n - 1) {
            printf(" ");
        }
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
