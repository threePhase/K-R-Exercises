#include <stdio.h>

int main() {
  int c, pc;

  while((c = getchar()) != EOF) {
    if (c != pc || c != ' ')
      putchar(c);
    pc = c;
  }
}
