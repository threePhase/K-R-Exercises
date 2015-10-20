#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; function version */
float fahr_to_celsius(float fahr);

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperature scale */
  upper = 300; /* upper limit of temperature scale */
  step = 20;   /* step size */

  fahr = lower;
  printf("Fahrenheit -> Celsius\n");
  printf("=====================\n");
  while(fahr <= upper) {
    celsius = fahr_to_celsius(fahr);
    printf("%5.0f %13.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

float fahr_to_celsius(float fahr) {
  return (5.0/9.0) * (fahr-32.0);
}
