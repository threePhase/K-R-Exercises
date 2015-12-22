#include <stdio.h>
#include <strings.h>

#define MAXLINE 1000
#define BASES 3
#define TESTS 5

void itob(int input, char output[], int base);
void reverse(char input[]);

int main() {
  int i, j, len, spaces;
  int inputs[TESTS] = { 0, -1, (~0u >> 1), -(~0u >> 1), ~(~0u >> 1) };
  int bases[BASES] = { 2, 10, 16 };
  /* { 32, 10, 8 } */
  char output[MAXLINE];
  printf("%12s", "input");
  for (i = 0; i < BASES; i++) {
    spaces = 0;
    while (spaces++ <= 54/bases[i]) {
      printf(" ");
    }
    printf("%s %d", "base", bases[i]);
  }
  printf("\n");

  for (i = 0; i < TESTS; i++) {
    printf("% 12d", inputs[i]);
    for (j = 0; j < BASES; j++) {
      spaces = 0;
      itob(inputs[i], output, bases[j]);
      len = strlen(output);
      while (spaces++ <= (66/bases[j]) - len) {
        printf(" ");
      }
      printf("%s ", output);
    }
    printf("\n");
  }

  return 0;
}

/* itob: converts input into a character representation of base in the string
 * output. */
void itob(int input, char output[], int base) {
  int c, i;
  unsigned u_input;
  if (input < 0) {
    u_input = -input;
  } else {
    u_input = input;
  }

  i = 0;
  do {
    c = (u_input % base);
    if (c < 10) {
      output[i++] = c + '0';
    } else {
      output[i++] = (c-10) + 'a';
    }
  } while ((u_input /= base) > 0);

  if (input < 0) {
    output[i++] = '-';
  }
  output[i] = '\0';
  reverse(output);
}

/* reverse: reverse string input in place */
void reverse(char input[]) {
  int c, i, j;

  for (i = 0, j = strlen(input)-1; i < j; i++, j--) {
    c = input[i];
    input[i] = input[j];
    input[j] = c;
  }
}
