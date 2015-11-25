#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 1000

int htoi(char hex[], int length);
int gethex(char input[], int maxlength);

/* htoi: converts hex strings into their integer equivalent */
int main() {
  int length;
  char hex[MAXLENGTH];
  length = gethex(hex, MAXLENGTH);
  /*  However there are values between '9' and 'A' so those will need to be
   *  accounted for before the htoi conversion works.*/
  printf("Hex: %s\nDecimal: %d\n", hex, htoi(hex, length));

  return 0;
}

/* htoi: convert a string hex s, of length l to integer */
int htoi(char s[], int l) {
  int i, n;
  n = 0;

  /* strip out leading 0x if present */
  if (s[1] == 'X') {
    i = 2;
  } else {
    i = 0;
  }

  while((s[i] >= '0' && s[i] <= '9') ||
       (s[i] >= 'A' && s[i] <= 'F')) {
    n = 16 * n;
    if (s[i] >= 'A') {
      n = n + s[i] - '9' + 2;
    } else {
      n = n + s[i] - '0';
    }
    ++i;
  }

  return n;
}

/* gethex: get a line from stdin in hex format normalizing all letters to upper */
int gethex(char s[], int l) {
  int c, i;
  for(i = 0; i < l-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    s[i] = toupper(c);
  }
  return i;
}
