#include <stdio.h>


#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxlength); /* BSD has a getline in libc */
void reverse(char s[]);

/* print input reversed, line by line */
int main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while((len = getline2(line, MAXLINE)) > 0) {
    /* only reverse lines 2 characters or longer */
    if (len > 1) {
      reverse(line);
      printf("%s", line);
    }
  }
  return 0;
}

/* getline2: read a line of input into line, return length */
int getline2(char line[], int maxlength) {
  int c, i;

  for (i = 0; i < maxlength-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* reverse: reverse an input line s */
void reverse(char s[]) {
  int i, j;
  char temp;

  i = 0;
  while(s[i] != '\0') {
     ++i;
  }
  /* shift back to avoid flipping the null terminator */
  --i;
  for(j = 0; j < i; ++j, --i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
  }
}
