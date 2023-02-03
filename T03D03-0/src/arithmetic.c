#include <stdio.h>

int sum(int a, int b);
int raz(int a, int b);
int proiz(int a, int b);
int chast(int a, int b);

int main() {
  int a, b;
  char c1, c2;
  printf("Input a,b(using space); \n");
  if (scanf("%d%c%d%c", &a, &c1, &b, &c2) != 4 || c2 != '\n' || c1 != ' ') {
    printf("Error n/a\n");
  } else if (b == 0) {
    printf("%d %d %d n/a\n", sum(a, b), raz(a, b), proiz(a, b));
  } else {
    printf("%d %d %d %d\n", sum(a, b), raz(a, b), proiz(a, b), chast(a, b));
  }
  return 0;
}

int sum(int a, int b) { return (a + b); }

int raz(int a, int b) { return (a - b); }

int proiz(int a, int b) { return (a * b); }

int chast(int a, int b) {
  if (b != 0) {
    return (a / b);
  }
}
