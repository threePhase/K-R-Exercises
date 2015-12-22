#include <stdio.h>
#include <strings.h>

#define MAXLINE 1000
#define TESTS 5

void itoa(int input, char output[], int width);
void reverse(char input[]);

int main() {
  int inputs[TESTS] = { 0, -1, (~0u >> 1), -(~0u >> 1), ~(~0u >> 1) };
  int i, value;
  char output[MAXLINE];

  printf("%11s %20s\n", "input", "output");
  for (i = 0; i < TESTS; i++) {
    value = inputs[i];
    itoa(value, output, 20);
    printf("% 10d %20s\n", value, output);
  }
  return 0;
}

/* itoa: convert integer input into string output with minimum field size of
 * width. If total characters in input is length is less than width, output is
 * padded with spaces on the left side. */
void itoa(int input, char output[], int width) {
  int i;
  unsigned u_input;
  /* flip sign but store in u_int to avoiding losing max negative value */
  if (input < 0) {
    u_input = -input;
  } else {
    u_input = input;
  }

  i = 0;
  do {       /* convert digits to characters in reverse */
    output[i++] = u_input % 10 + '0'; /* get next digit */
  } while ((u_input /= 10) > 0);      /* move to next digit */

  if (input < 0) {
    output[i++] = '-';
  }

  while (i < width) {
    output[i++] = ' ';
  }

  output[i] = '\0';
  reverse(output);
}

/* reverse: reverse a string input in place. */
void reverse(char input[]) {
  int c, i, j;
  for (i = 0, j = strlen(input)-1; i < j; i++, j--) {
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}
