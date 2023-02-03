#include <math.h>
#include <stdio.h>
int main() {

  float x, y;
  char c1, c2;
  if (scanf("%f%c%f%c", &x, &c1, &y, &c2) != 4 || c2 != '\n' || c1 != ' ') {
    printf("Error n/a\n");
  } else {
    if (pow(x, 2) + pow(y, 2) <= 25) {
      printf("GOTCHA\n");
    } else {
      printf("MISS\n");
    }
  }
}