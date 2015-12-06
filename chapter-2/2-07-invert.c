#include <stdio.h>

unsigned invert(unsigned input, int position, int num);

int main() {

  printf("Inverting %d bits of %u beginning at position %d yields %u\n", 7, 128, 6, invert(128, 6, 7));
  printf("Inverting %d bits of %u beginning at position %d yields %u\n", 7, 129, 6, invert(129, 6, 7));
  printf("Inverting %d bits of %u beginning at position %d yields %u\n", 1, 255, 3, invert(255, 3, 1));
  return 0;
}

/* invert: invert num bits of input starting at position and moving right */
unsigned invert(unsigned input, int position, int num) {
  unsigned x, y, z;

  x = (input & (~0 << (position+1)));
  y = (((~input >> (position+1-num)) << (position+1-num)) &
        ~(~0 << (position+1)));
  z = (input & ~(~0 << (position+1-num)));

  return x | y | z;
}
