#include <stdio.h>

#define MAXLENGTH 1000

int getline2(char string[], int max_length);
void squeeze(char string[], char remove[]);

int main() {
  char input[MAXLENGTH];
  char removal[MAXLENGTH];

  printf("Input string: ");
  getline2(input, MAXLENGTH);
  printf("Removal string: ");
  getline2(removal, MAXLENGTH);
  squeeze(input, removal);
  printf("Squeezed string: %s\n", input);
}

/* squeeze: remove any characters occuring in s1 and s2 */
void squeeze(char s1[], char s2[]) {
  int i, j, k;
  for (i = j = 0; s1[i] != '\0'; ++i) {
    for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; ++k) {
    }
    if (s1[i] != s2[k]) {
      s1[j] = s1[i];
      ++j;
    }
  }
  s1[j] = '\0';
}

/* getline2: get a line from stdin */
int getline2(char s[], int l) {
  int c, i;
  for(i = 0; i < l-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  return i;
}
