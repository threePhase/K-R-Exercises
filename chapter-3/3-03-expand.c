#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

void expand(char input[], char output[]);
int getline2(char input[], int maxlength);

int main() {
  int len;
  char input[MAXLENGTH], output[MAXLENGTH];
  while ((len = getline2(input, MAXLENGTH)) > 0) {
    expand(input, output);
    printf("%s\n", output);
  }
  return 0;
}

/* expand: expand shorthand notations such as a-z from input into the
 * complete list (abc...xyz) in ouput. Handles letters of either case and
 * digits. Leading or trailing '-' are inserted literally into output. */
void expand(char input[], char output[]) {
  int c, i, j, between;
  int can_expand = FALSE;
  int expanding = FALSE;
  for (i = j = 0; i < strlen(input)-1; i++) {
    c = input[i];
    if (c == '-') {
      if (can_expand) {
        expanding = TRUE;
      } else {
        output[j] = c;
        j++;
      }
      can_expand = FALSE;
    } else {
      if (expanding) {
        /* i-2 is where last character was, before - */
        between = input[i-2] + 1;
        while (between < c) {
          output[j] = between++;
          j++;
        }
        expanding = !expanding;
      }
      can_expand = TRUE;
      output[j] = c;
      j++;
    }
  }
  if (expanding) {
    output[j] = '-';
    j++;
  }
  output[j] = '\0';
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
