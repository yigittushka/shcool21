#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void bubl(int *a, int n);

int main() {
    int n = 10;
    int data[NMAX];
    int result = 0;
    if (input(data, &n) == 0) {
        bubl(data, n);
        output(data, n);

    } else {
        printf("n/a\n");
        result = 1;
    }

    return result;
}

int input(int *a, int *n) {
    char c;
    int result = 0;
    for (int *i = a; i - a < *n; i++) {
        if (scanf("%d%c", i, &c) != 2 || (c != ' ' && c != '\n') || *n < NMAX || *n > NMAX) {
            result = 1;
            break;
        }
    }

    return result;
}

void bubl(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int e = a[j];
                a[j] = a[j + 1];
                a[j + 1] = e;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);

        if (p - a < n - 1) {
            printf(" ");
        }
    }
}
