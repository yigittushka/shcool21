#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    int *pn = &n;

    if (input(data, pn) == 0) {
        output(data, n);
        mean(data, n);
        variance(data, n);

        return 1;
    } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n <= 0) {
        return 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                return 1;
                break;
            }
        }
    }
    return 0;
}

void output(int *a, int n) {
    double sum = mean(a, n);
    double avr = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if ((*p % 2 == 0) && (*p >= sum) && (*p <= sum + 3 * sqrt(avr) && (*p != 0))) {
            printf("%d", *p);
        } else {
            if (*p == 0) {
                printf("%d", 0);
                break;
            }
        }
    }
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
