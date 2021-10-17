#include <stdio.h>

int f(int *A, int first, int last) {
  printf("f(A, %d, %d)\n", first, last);
  if (first == last) return first;
  // if (first == last - 1) return A[first] < A[last] ? first : last;
  int mid = (first + last) / 2;
  int left = f(A, first, mid);
  int right = f(A, mid + 1, last);
  return A[left] < A[right] ? left : right;
}

#define PINT(x) printf(#x " = %d\n", x)

int main() {
  // int A[] = {-1, 3, 3, 3, 3, 3, 2, 3, 3, 3};
  int A[] = {-1, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3};
  PINT(f(A, 1, 10));
  return 0;
}