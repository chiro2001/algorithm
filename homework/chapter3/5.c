#include <stdio.h>

int find_index(int *A, int first, int last) {
  printf("find_index(A, %d, %d)\n", first, last);
  if (A[first] == first) return first;
  if (A[last] == last) return last;
  int k = (first + last) / 2;
  if (A[k] < k)
    return find_index(A, k, last);
  else
    return find_index(A, first, k);
}

#define PINT(x) printf(#x " = %d\n", x)

int main() {
  int A[] = {-1, 0, 1, 3, 5, 6, 7, 8, 9};
  PINT(find_index(A, 0, 8));
  return 0;
}