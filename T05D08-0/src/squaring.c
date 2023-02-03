#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int *pn = &n;
    if (input(data, pn) == 1) {
        return 0;
    }

    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n <= 0) {
        printf("n/a");
        *n = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("\rn/a");
                *n = 0;
            }
            if (scanf("%c", &c) == 1 && c != '\n') {
                printf("\rn/a");
                *n = 0;
            }
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);

        if (p - a < n - 1) {
            printf(" ");
        }
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
