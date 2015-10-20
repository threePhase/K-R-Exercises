#include <stdio.h>

#define IN 1          /* inside a word */
#define OUT 0         /* outside a word */
#define MAX_LENGTH 10 /* max word length */

/* print a histogram of the lenghts of words input */

int main() {
  int c, f, i, j, l, max_f, state;
  int wlen[MAX_LENGTH];

  /* initialize word length data */

  for (i = 0; i < MAX_LENGTH; ++i) {
    wlen[i] = 0;
  }

  state = OUT;

  f = l = max_f = 0;

  /* count word lengths as we collect input */
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c =='\t') {
      /* stop word lenght count, update word length data */
      state = OUT;
      f = ++wlen[l%MAX_LENGTH];
      if (f > max_f) {
        max_f = f;
      }
    } else if (state == OUT) {
      /* start word length count */
      state = IN;
      l = 0;
    } else if (state == IN) {
      ++l;
    }
  }

  /* print header area */
  printf("word length frequencies\n  ");
  for (j = 0; j < MAX_LENGTH + 1; ++j) {
    putchar('-');
  }
  putchar('\n');

  /* print histogram data */
  for (i = 0; i < max_f; ++i) {
    printf("%d|", max_f - i);
    for (j = 0; j < MAX_LENGTH; ++j) {
      if (wlen[j] == (max_f - i)) {
        putchar('x');
      } else if (wlen[j] > max_f - i) {
        putchar('|');
      } else {
        putchar(' ');
      }
    }
    printf(" |\n");
  }

  /* print footer area */
  printf("  ");
  for (j = 0; j < MAX_LENGTH + 1; ++j) {
    putchar('-');
  }
  printf("\n  ");
  for (j = 1; j <= MAX_LENGTH; ++j) {
    printf("%d", j);
  }
  printf("+\n     length\n");
}
