#include <math.h>
#include <stdio.h>
double from(double x);

int main() {
  double x;
  char c2;
  if (scanf("%lf%c", &x, &c2) != 2 || c2 != '\n') {
    printf("Error n/a\n");
  } else {
    printf("%.1lf\n", from(x));
  }
}

double from(double x) {
  x = 7e-3 * pow(x, 4) +
      ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) -
      x * pow((10 + x), (2 / x)) - 1.01;
  return (x);
}