#include <stdio.h>

#define MAX 15

int bitcount(int x);

int main() {
  int i;
  for (i = 0; i <= MAX; ++i) {
    printf("1 bits in %d: %d\n", i, bitcount(i));
  }
  return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(int x) {
  /* in a two's complement number system, x &= (x-1) deletes the rightmost
   * 1-bit in x because the negative values are equivalent to the positive ones
   * with the addition of a 1 in the left most bit to represent sign. With a
   * one's complement system, this would not work because there are multiple
   * representations of zero.
   */
  int b = x != 0;
  while(x != 0) {
    if (x &= (x-1)) {
      b++;
    }
  }
  return b;

}
