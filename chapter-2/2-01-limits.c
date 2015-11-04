#include <stdio.h>
#include <limits.h>
#include <float.h>

signed int get_sint_limit();
unsigned int get_uint_limit();
signed short get_sshort_limit();
unsigned short get_ushort_limit();
signed char get_schar_limit();
unsigned char get_uchar_limit();
signed long get_slong_limit();
unsigned long get_ulong_limit();

int main() {
  signed int sint;
  unsigned int uint;
  signed short sshort;
  unsigned short ushort;
  signed char schar;
  unsigned char uchar;
  signed long slong;
  unsigned long ulong;

  sint = get_sint_limit();
  uint = get_uint_limit();
  sshort = get_sshort_limit();
  ushort = get_ushort_limit();
  schar = get_schar_limit();
  uchar = get_uchar_limit();
  slong = get_slong_limit();
  ulong = get_ulong_limit();


  printf("Limits of types (header defined values in \"()\")\n");

  printf("Largest signed int: %d (%d)\n\
Smallest signed int: %d (%d)\n", sint, INT_MAX, sint+1, INT_MIN);
  printf("Largest unsigned int: %u (%u)\n\
Smallest unsigned int: %u (%u)\n", uint, UINT_MAX, 0, 0);
  printf("Largest signed short: %hd (%hd)\n\
Smallest signed short: %hd (%hd)\n", sshort, SHRT_MAX, sshort+1, SHRT_MIN);
  printf("Largest unsigned short: %hu (%hu)\n\
Smallest unsigned short: %hu (%hu)\n", ushort, USHRT_MAX, 0, 0);
  printf("Largest signed char: %hd (%hd)\n\
Smallest signed char: %hd (%hd)\n", schar, SCHAR_MAX, schar+1, SCHAR_MIN);
  printf("Largest unsigned char: %hd (%hd)\n\
Smallest unsigned char: %hd (%hd)\n", uchar, UCHAR_MAX, 0, 0);
  printf("Largest signed long: %ld (%ld)\n\
Smallest signed long: %ld (%ld)\n", slong, LONG_MAX, slong+1, LONG_MIN);
  printf("Largest unsigned long: %lu (%lu)\n\
Smallest unsigned long: %ul (%ul)\n", ulong, ULONG_MAX, 0, 0);
  return 0;
}

/* get_sint_limit: determines the maximum value of a signed int */
signed int get_sint_limit() {
  signed int i;
  i = 0; /* initial value */
  while (i < i + 1) {
    ++i;
  }
  return i;
}

/* get_sint_limit: determines the maximum value of a unsigned int */
unsigned int get_uint_limit() {
  unsigned int i;
  i = 0; /* initial value */
  while (i < i + 1) {
    ++i;
  }
  return i;
}

/* get_sshort_limit: determines the maximum and minium values of a signed short */
signed short get_sshort_limit() {
  signed short s;
  s = 1; /* initial value */
  while (s > 0) {
    ++s;
  }
  return s-1;
}

/* get_ushort_limit: determines the maximum and minium values of a unsigned short */
unsigned short get_ushort_limit() {
  unsigned short s;
  s = 1; /* initial value */
  while (s > 0) {
    ++s;
  }
  return s-1;
}

/* get_schar_limit: determines the maximum and minium values of a signed char */
signed char get_schar_limit() {
  signed char c;
  c = 1; /* initial value */
  while (c > 0) {
    ++c;
  }
  return c-1;
}

/* get_uchar_limit: determines the maximum and minium values of a unsigned char */
unsigned char get_uchar_limit() {
  unsigned char c;
  c = 1; /* initial value */
  while (c > 0) {
    ++c;
  }
  return c-1;
}

/* get_slong_limit: determines the maximum and minium values of a signed long */
signed long get_slong_limit() {
  signed long adder, l;
  adder, l = 1; /* initial value */
  while (l + adder > l) {
    l = l + adder;
    adder = l;
    while (l + adder < 0) {
      adder = adder / 2;
    }
  }
  return l;
}

/* get_ulong_limit: determines the maximum and minium values of a unsigned long */
unsigned long get_ulong_limit() {
  unsigned long adder, l;
  adder, l = 1; /* initial value */
  while (l + adder > l) {
    l = l + adder;
    adder = l;
    while (l + adder < l) {
      adder = adder / 2;
    }
  }
  return l;
}
