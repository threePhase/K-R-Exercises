#include <stdio.h>

#define TABSTOP 2 /* # of spaces in each tab */

/* Replaces tabs in the input with proper number of blanks to space to the next
 * tab stop. Assumes fixed set of tabstops. */
int main() {
  int c;

  while((c = getchar()) != EOF) {
    if (c == '\t') {
      int i;

      for(i = 0; i < TABSTOP; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
  return 0;
}
