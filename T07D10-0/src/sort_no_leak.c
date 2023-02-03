#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n, int *flag);
void output(int *a, int n);
void bubl(int *a, int n);

int main() {
    int n;
    int *data = NULL;
    int flag = 0;
    if (input(&data, &n, &flag) == 0) {
        bubl(data, n);
        output(data, n);
        flag = 0;
    } else {
        flag = 1;
        printf("n/a\n");
    }

    free(data);
    return flag;
}

int input(int **a, int *n, int *flag) {
    char c;
    if (scanf("%d", n) != 1 || *n <= 0) {
        *flag = 1;
    }
    *a = (int *)malloc(*n * sizeof(int));

    for (int *i = *a; i - *a < *n; i++) {
        if (scanf("%d%c", i, &c) != 2 || (c != ' ' && c != '\n')) {
            *flag = 1;
            break;
        }
    }

    return *flag;
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