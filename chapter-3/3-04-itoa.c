#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define TESTS 5

void itoa(int input, char output[]);
void itoa2(int input, char output[]);
void reverse(char input[]);

int main() {
  /* max value, which fails initially */
  int i, value;
  int test_values[TESTS] = { 0, -1, ~0u >> 1, -(~0u >> 1), ~(~0u >> 1) };
  char output[MAXLENGTH];
  char output2[MAXLENGTH];
  printf("%11s%12s%12s\n", "input", "itoa", "itoa2");
  for (i = 0; i < TESTS; i++) {
    value = test_values[i];
    itoa(value, output);
    itoa2(value, output2);
    printf("% 10d%12s%12s\n", value, output, output2);
  }
  return 0;
}

/* itoa: convert input to characters in output. Inital version does not handle
 * the largest negative number in a 2's complement system -(2^wordsize-1)
 * because the largest positive number is (2^wordsize-1)-1. Thus our
 * implementation would only give us -(2^wordsize-1) for output. */
void itoa(int input, char output[]) {
  int i, sign;
  if ((sign = input) < 0) {
    /* flip sign */
    input = -input;
  }

  i = 0;
  do {
    output[i++] = input % 10 + '0';
  } while ((input /= 10) > 0);

  if (sign < 0) {
    output[i++] = '-';
  }

  output[i] = '\0';
  reverse(output);
}

/* itoa2: convert input to characters in output. */
void itoa2(int input, char output[]) {
  int i;
  unsigned u_input;
  if (input < 0) {
    /* flip sign */
    u_input = -input;
  } else {
    u_input = input;
  }

  i = 0;
  do {
    output[i++] = u_input % 10 + '0';
  } while ((u_input /= 10) > 0);

  if (input < 0) {
    output[i++] = '-';
  }

  output[i] = '\0';
  reverse(output);
}


/* reverse: reverse a string input in place */
void reverse(char input[]) {
  int c, i, j;
  for(i = 0, j = strlen(input)-1; i < j; i++, j--) {
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}
