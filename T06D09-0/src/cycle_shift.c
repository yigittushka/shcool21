#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *shift);
void output(int *a, int n);
int sdvig(int *a, int n, int shift);

int main() {
    int n, shift, data[NMAX];
    int result = 0;
    if (input(data, &n, &shift) == 0) {
        sdvig(data, n, shift);
        output(data, n);

        result = 0;
    } else {
        printf("n/a\n");
        result = 1;
    }
    return result;
}

int input(int *a, int *n, int *shift) {
    char c;
    int result = 0;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n <= 0) {
        result = 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                result = 1;
                break;
            }
        }
    }
    if (scanf("%d%c", shift, &c) != 2 || c != '\n') {
        result = 1;
    }

    return result;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);

        if (p - a < n - 1) {
            printf(" ");
        }
    }
}

int sdvig(int *a, int n, int shift) {
    if (shift != 0) {
        int vv = shift > 0 ? 0 : 1;
        if (vv == 0) {
            for (int i = 0; i < shift; i++) {
                int r = a[0];
                for (int j = 0; j < n - 1; j++) {
                    a[j] = a[j + 1];
                }
                a[n - 1] = r;
            }
        } else {
            shift *= -1;
            for (int i = 0; i < shift; i++) {
                int vv = a[n - 1];
                for (int j = n - 1; j > 0; j--) {
                    a[j] = a[j - 1];
                }
                a[0] = vv;
            }
        }
    }

    return 0;
}
