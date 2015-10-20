#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  printf(" C  ->  F\n");
  printf("==========\n");

  lower = -20; /* lower limit of temperature scale */
  upper = 150; /* upper limit */
  step = 10; /* step size */

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
