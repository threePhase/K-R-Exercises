#include <stdio.h>

/* Verify getchar() != EOF == 0 || 1 */

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    printf("getchar() != EOF == %d\n", c != EOF);
  }
  printf("getchar() != EOF == %d\n", c != EOF);
}
