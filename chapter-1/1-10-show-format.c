#include <stdio.h>

/* copy stdin to stdout replacing tab with \t, backspace with \b, and
 * backslashes with \\ */

int main() {
  int c;

  while((c = getchar()) != EOF) {
    if (c == '\b')
      /* os seems to intercept this */
      printf("\\b");
    else if (c == '\t')
      printf("\\t");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
}
