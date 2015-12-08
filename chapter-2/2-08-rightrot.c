#include <stdio.h>

unsigned rightrot(unsigned input, unsigned n);
unsigned getbits();

int main() {

  printf("Rotating %u by %u bits yields: %x\n", 1, 1, rightrot(1, 1));
  printf("Rotating %u by %u bits yields: %x\n", 8, 1, rightrot(8, 1));
  printf("Rotating %u by %u bits yields: %x\n", 33, 1, rightrot(33, 1));
  printf("Rotating %u by %u bits yields: %x\n", 3, 2, rightrot(3, 2));
  printf("Rotating %u by %u bits yields: %x\n", 8, 2, rightrot(8, 2));
  printf("Rotating %u by %u bits yields: %x\n", 5, 3, rightrot(5, 3));

  return 0;
}

/* rightrot: rotate input to the right by n positions */
unsigned rightrot(unsigned input, unsigned n) {
  unsigned totalbits = getbits();
  unsigned x = input >> n;
  unsigned y = input << (totalbits - n);
  return x | y;
}

/* getbits: returns total number of bits of unsigned int */
unsigned getbits() {
  unsigned maxvalue = ~0;
  unsigned bits = 0;
  while (maxvalue > 0) {
    ++bits;
    maxvalue = maxvalue >> 1;
  }
  return bits;
}
