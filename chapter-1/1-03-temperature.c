#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  printf("Fahrenheit-Celsius table\n");
  printf("(F\tC)\n");
  printf("==========\n");

  lower = 0; /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
