#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

/* rudimentary calculator */
int main() {
  double sum, atof(char input[]);
  char line[MAXLINE];
  int getline2(char line[], int max);

  sum = 0;
  while (getline2(line, MAXLINE) > 0) {
    printf("\t%g\n", sum += atof(line));
  }
  return 0;
}

/* atof: convert string input to double */
double atof(char input[]) {
  double val, power;
  int i, sign, exponent, exponent_sign;

  for (i = 0; isspace(input[i]); i++) {
    ;
  }

  sign = (input[i] == '-') ? -1 : 1;
  if (input[i] == '+' || input[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(input[i]); i++) {
    val = 10.0 * val + (input[i] - '0');
  }

  if (input[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(input[i]); i++) {
    val = 10.0 * val + (input[i] - '0');
    power *= 10.0;
  }

  if (input[i] == 'e' || input[i] == 'E') {
    i++;
  }

  exponent_sign = (input[i] == '-') ? -1 : 1;
  if (input[i] == '+' || input[i] == '-') {
    i++;
  }

  for (exponent = 0; isdigit(input[i]); i++) {
    exponent = 10 * exponent + (input[i] - '0');
  }
  printf("exponent: %d\n", exponent);

  while (exponent > 0) {
    if (exponent_sign > 0) {
      val *= 10.0;
    } else {
      power *= 10.0;
    }
    exponent--;
  }

  return sign * val / power;
}

/* getline2: get line into line, return length */
int getline2(char line[], int max) {
  int c, i;
  i = 0;
  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }
  if (c == '\n') {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}
