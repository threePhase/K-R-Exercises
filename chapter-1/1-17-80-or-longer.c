#include <stdio.h>

#define MINLINE 80 /* minimum output line length */
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline); /* BSD has a getline in libc */

/* print lines 80 characters or longer from input*/
int main() {
  int len;               /* current line length */
  char line[MAXLINE];    /* current input line */

  while((len = getline2(line, MAXLINE)) > 0) {
    if (len > MINLINE) {
      printf("%s", line);
    }
  }
  return 0;
}

/* getline2: read a line into line, return length */
int getline2(char line[], int maxline) {
  int c, i;

  for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
