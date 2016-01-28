#include <stdio.h>

int lower(int c);

int main() {
  int c;
  for (c = 'A'; c <='Z'; ++c) {
    printf("Converting %c to lower case: %c\n", c, lower(c));
  }
  return 0;
}

/* lower: convert c to lower case; ASCII only (using conditional expressions) */
int lower(int c) {
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
