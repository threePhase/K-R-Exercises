#include <stdio.h>

#define LENGTH 80 /* character to fold each line input on */
#define MAXLINE 1000 /* maximum input line length */

int getline_fold(char line[], int maxline, int fold_index);

/* */
int main() {
  int len;              /* current line length */
  char line[MAXLINE];   /* current input line */

  while((len = getline_fold(line, MAXLINE, LENGTH)) > 0) {
    if (line[0] != '\n') {
      printf("%s", line);
    }
  }
  return 0;
}

/* getline_fold: fold line s into two shorter lines after the last non-blank
 * character that occurs before the n-th column. when n is mid-word, the fold is
 * backtracked to the previous whitespace. */
int getline_fold(char s[], int max, int fold) {
  int c, i, j, word_start;

  word_start = 0; /* marks the beginning of a word */

  for(i = j = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; ++i, ++j) {
    if (j == fold-1) {
      if (c == ' ' || c == '\t') {
        /* reset word_start index */
        word_start = -1;
        /* wrap line */
        c = '\n';
        j = 0;
      } else {
        /* backup */
        /* wrap line */
        s[word_start-1] = '\n';
        j = i-word_start;
      }
    } else {
      if (c == ' ' || c == '\t') {
        word_start = -1;
      } else if (word_start == -1) {
        /* set word_start index */
        word_start = i;
      }
    }
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
