#include <stdio.h>

#define TABSTOP 4 /* # of spaces in each tab */

/* Replaces strings of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing. Assumes fixed set of tabstops. Prefers tabs when
 * TABSTOP == 1. */
int main() {
  int c;

  while((c = getchar()) != EOF) {
    if (c == ' ') {
      int i;

      i = 1;
      /* collect all the spaces */
      while((c = getchar()) == ' ') {
        ++i;
      }

      /* replace with tabs */
      while(i >= TABSTOP) {
        putchar('\t');
        i = i - TABSTOP;
      }

      /* put back remaining spaces */
      while(i > 0) {
        putchar(' ');
        i = i - 1;
      }
    }
    if (c != EOF) {
      putchar(c);
    }
  }
  return 0;
}
