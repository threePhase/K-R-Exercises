#include <stdio.h>

/* print input, with each word on a newline */

int main() {
  int c;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t')
      putchar('\n');
    else
      putchar(c);
  }
}
