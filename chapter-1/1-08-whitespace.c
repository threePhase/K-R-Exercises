#include <stdio.h>

/* count blanks, newlines, and tabs in input string */

int main() {
  int c, bc, nc, tc;
  bc = nc = tc = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++bc;
    if (c == '\n')
      ++nc;
    if (c == '\t')
      ++tc;
  }
  printf("blanks: %d, newlines: %d, tabs: %d\n", bc, nc, tc);
}
