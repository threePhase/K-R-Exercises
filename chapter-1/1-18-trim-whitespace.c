#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline_trim(char line[], int maxline);

/* print lines with trailing whitespace and blank lines removed */
int main() {
  int len;               /* current line length */
  char line[MAXLINE];    /* current input line */

  while((len = getline_trim(line, MAXLINE)) > 0) {
    if (len != 1 || line[0] != '\n') {
      printf("%s", line);
    }
  }
  return 0;
}

/* getline_trim: read a input into line (removing trailing whitespace) */
int getline_trim(char line[], int maxline) {
  int c, i, ws_index;

  ws_index = -1; /* repeated whitespace index */

  for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (ws_index == -1 && (c == ' ' || c == '\t')) {
      ws_index = i;
    } else if (c != ' ' && c != '\t') {
      /* reset index since we entered a word again */
      ws_index = -1;
    }
    line[i] = c;
  }
  /* collapse trailing whitespace */
  if (ws_index != -1) {
    i = ws_index;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}
