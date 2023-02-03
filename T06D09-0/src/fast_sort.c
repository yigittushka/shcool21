#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int partition(int *a, int low, int high);
void quickSort(int *a, int low, int high);
void heapify(int *a, int n, int i);
void heapSort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 10;
    int data[NMAX];
    int result = 0;
    if (input(data, &n) == 0) {
        quickSort(data, 0, n - 1);
        output(data, n);
        heapSort(data, n);
        output(data, n);
        result = 0;
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int e = a[i];
            a[i] = a[j];
            a[j] = e;
        }
    }
    int e = a[i + 1];
    a[i + 1] = a[high];
    a[high] = e;

    return (i + 1);
}

void quickSort(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        int e = a[i];
        a[i] = a[largest];
        a[largest] = e;
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int e = a[0];
        a[0] = a[i];
        a[i] = e;
        heapify(a, i, 0);
    }
}
