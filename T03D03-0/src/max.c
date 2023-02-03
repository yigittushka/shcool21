#include <stdio.h>

int max(int a, int b);

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  printf("Введите 2 числа \n");
  int a, b;
  char c1, c2;
  if (scanf("%f%c%f%c", &a, &c1, &b, &c2) != 4 || c2 != '\n' || c1 != ' ') {
    printf("Error n/a\n");
  } else if (a == b) {
    printf("Числа равны\n");
  } else {
    printf("%d\n", max(a, b));
    return 0;
  }
}
