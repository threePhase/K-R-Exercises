#include <stdio.h>

/* print a histogram of the character frequences of the input */

int main() {
  int c, f, i, j, max_f, total_characters;
  total_characters = '~' - '!';
  int cfreq[total_characters+1];

  /* initialize character frequency data */

  for (i = 0; i < total_characters+1; ++i) {
    cfreq[i] = 0;
  }

  f = max_f = 0;

  /* count word lengths as we collect input */
  while((c = getchar()) != EOF) {
    if (c >= '!' && c <= '~') {
      f = ++cfreq[c-'!'];
      if (f > max_f) {
        max_f = f;
      }
    }
  }

  /* print header area */
  printf("\t\t\t\t\tcharacter frequencies\n   ");
  for (j = 0; j < total_characters+1; ++j) {
    putchar('-');
  }
  putchar('\n');

  /* print histogram data */
  for (i = 0; i < max_f; ++i) {
    printf("%2d|", max_f - i);
    for (j = 0; j < total_characters+1; ++j) {
      if (cfreq[j] == (max_f - i)) {
        putchar('x');
      } else if (cfreq[j] > max_f - i) {
        putchar('|');
      } else {
        putchar(' ');
      }
    }
    printf("|\n");
  }

  /* print footer area */
  printf("   ");
  for (j = 0; j < total_characters+1; ++j) {
    putchar('-');
  }
  printf("\n   ");
  for (j = 0; j <= total_characters; ++j) {
    printf("%c", '!' + j);
  }
  putchar('\n');
}
