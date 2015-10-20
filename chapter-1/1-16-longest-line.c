#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline); /* BSD has a getline in libc */
void copy(char to[], char from[]);

/* print the longest line in input as well as its length */
int main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while((len = getline2(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {/* there was a line */
    printf("longest string: %s", longest);
    printf("length: %d\n",  max);
  }
  return 0;
}

/* getline2: read a line into line, return length */
int getline2(char line[], int maxline) {
  int c, i;

  for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to' (assumes 'to' is large enough) */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}
