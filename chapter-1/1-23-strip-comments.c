#include <stdio.h>

#define BEGIN 1 /* consumed '/' */
#define IN 2    /* in comment */
#define END 3   /* consumed '*' */
#define OUT 4   /* out of comment */

/* strips all the comments from a c program */
int main() {
  int c, i, state;

  state = OUT;

  while((c = getchar()) != EOF) {
    if (state == OUT) {
      if (c == '/') {
        /* get next character and verify it's a '*' */
        state = BEGIN;
      } else {
        putchar(c);
      }
    } else if (state == END) {
      if (c == '/') {
        state = OUT;
      } else if (c != '*') {
        state = IN;
      }
    } else if (state == IN) {
      if (c == '*') {
        /* get next character and verify it's a '/' */
        state = END;
      }
    } else if (state == BEGIN) {
       if (c == '*') {
        state = IN;
      } else if (c != '/') {
        /* false positive, place consumed slash */
        putchar('/');
        state = OUT;
        putchar(c);
      }
    }
  }
}
