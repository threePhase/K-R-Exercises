#include <stdio.h>

int binsearch(int input, int values[], int total_values);
int binsearch2(int input, int values[], int total_values);

int main() {
  int i;
  int total_values = 100000;
  int v[total_values];

  for(i = 0; i < total_values; i+=2) {
    v[i] = i+1;
  }

  printf("%d is located at index %d\n", -4, binsearch(-4, v, total_values));
  printf("%d is located at index %d\n", -4, binsearch2(-4, v, total_values));
  printf("%d is located at index %d\n", 7, binsearch(7, v, total_values));
  printf("%d is located at index %d\n", 7, binsearch2(7, v, total_values));

  return 0;
}

/* binsearch: search for input value in values, where total_values is the
 * total number of items to in values. */
int binsearch(int input, int values[], int total_values) {
  int low, high, mid;

  low = 0;
  high = total_values-1;
  while (low <= high) {
    mid = (low+high)/2;
    if (input < values[mid]) {
      high = mid-1;
    } else if (input > values[mid]) {
      low = mid+1;
    } else {
      return mid;
    }
  }
  return -1;
}

/* binsearch2: search for input value in values, where total_values is the
 * total number of items to in values. */
int binsearch2(int input, int values[], int total_values) {
  int low, high, mid;

  low = 0;
  high = total_values-1;

  for(mid = (low+high)/2; input != values[mid] && low <= high; mid = (low+high)/2) {
    if (input > values[mid]) {
      low = mid+1;
    } else {
      high = mid-1;
    }
  }
  return input == values[mid] ? mid : -1;
}
