#include <stdio.h>

#define MAXLINE 1000

int getchar2();

int main() {
  int c, i, lim;
  char s[MAXLINE];

  lim = MAXLINE;
  /* needed to add a function here to avoid unsequenced modification and access
   * to c, since == is not a sequence point. Maybe something fancy could be
   * done with the comma operator. */
  for (i = 0; 1 == (i < lim-1) == ((c=getchar2()) != '\n'); ++i) {
    s[i] = c;
  }

  printf("string: %s\n", s);

  return 0;
}

/* getchar2: getchar wrapper which converts EOF to newlines */
int getchar2() {
  int c;
  c=getchar();
  if (c != EOF) {
    return c;
  } else {
    return '\n';
  }
}
