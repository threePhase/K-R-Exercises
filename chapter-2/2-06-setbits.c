#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  int i;
  unsigned x = 1024;
  unsigned y = 255;

  for(i = 0; i < 4; ++i) {
    printf("Setting %d's bits beginning at position %d to %d's rightmost %d "
           "bits yields %d\n", x, i, y, i, setbits(x, i, i, y));
  }
  printf("Setting %d's bits beginning at position %d to %d's rightmost %d "
         "bits yields %d\n", 51, 3, 3, 2, setbits(51, 3, 2, 3));
  printf("Setting %d's bits beginning at position %d to %d's rightmost %d "
         "bits yields %d\n", 48, 3, 3, 2, setbits(48, 3, 2, 3));
  return 0;
}

unsigned getbits(unsigned input, int position, int bits) {
  return (input >> (position+1-bits)) & ~(~0 << bits);
}

/* setbits: returns output with the n bits that begin at position set to the
 * rightmost n bits of input, leaving other bits unchanged. */
unsigned setbits(unsigned output, int position, int n, unsigned input) {
  /*
  f(110000, 3, 2, 011) = 111100
  f(48, 3, 2, 3) = 60

  f(110011, 3, 2, 011) = 111111
  f(51, 3, 2, 3) = 63
                 = 110000 | 001111
                 = 110000 | 001100 | 000011
                 = (110011 & 111100) | 001100 | (000011 & 000011)
  */
  unsigned x, y, z;
  x = (output & (~0 << (position+1)));
  y = (input & ~(~0 << n)) << n;
  z = (output & ~(~0 << (position+1-n)));
  printf("%d | %d | %d\n", x, y, z);

  return x | y | z;
}
