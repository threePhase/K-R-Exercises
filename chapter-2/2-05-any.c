#include <stdio.h>

#define MAXLENGTH 1000

int any(char s1[], char s2[]);
int getline2(char s[], int l);

int main() {
  char input[MAXLENGTH], match[MAXLENGTH];
  printf("Input string: ");
  getline2(input, MAXLENGTH);
  printf("Match string: ");
  getline2(match, MAXLENGTH);
  printf("Input match found at index: %d\n", any(input, match));
  return 0;
}

/* getline2: capture a line from stdin no longer than length to input */
int getline2(char input[], int length) {
  int c, i;
  for(i = 0; i < length-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    input[i] = c;
  }
  return i;
}

/* any: return the index of input where any character from match occurs, or -1
 * if input does not contain any characters in match. */
int any(char input[], char match[]) {
  int i, j;
  for(i = 0; input[i] != '\0'; ++i) {
    for(j = 0; match[j] != '\0'; ++j) {
      if (input[i] == match[j]) {
        return i;
      }
    }
  }
  return -1;
}
