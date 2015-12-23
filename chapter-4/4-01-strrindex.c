#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getline2(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching patterns */
int main() {
  char line[MAXLINE];
  int index;
  int found = 0;

  while (getline2(line, MAXLINE) > 0) {
    if ((index = strrindex(line, pattern)) >= 0) {
      printf("index: %d match: %s", index, line);
      found++;
    }
  }
  return found;
}

/* getline2: get line into line of maximum lenght max, return length */
int getline2(char input[], int max) {
  int c, i;

  i = 0;
  while (--max > 0 && (c=getchar()) != EOF && c != '\n') {
    input[i++] = c;
  }
  if (c == '\n') {
    input[i++] = c;
  }
  input[i] = '\0';
  return i;
}

/* strrindex: find right most occurance of searchfor in source or -1 if it is
 * not found */
int strrindex(char source[], char searchfor[]) {
  int i, j, k, index;

  /* initalize to -1 to avoid checking at return */
  index = -1;
  for (i = 0; source[i] != '\0'; i++) {
    for (j = i, k = 0; searchfor[k] != '\0' &&
                       source[j] == searchfor[k]; j++, k++) {
      ;
    }
    if (k > 0 && searchfor[k] == '\0') {
      index = i;
    }
  }
  return index;
}
