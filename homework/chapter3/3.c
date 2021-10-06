#include <math.h>
#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int find_n_in_c(int *A, int *B, int la, int lb, int n) {
  if (la > lb) return find_n_in_c(B, A, lb, la, n);
  if (la == 0) return B[0];
  if (n == 1) return min(A[0], B[0]);
  int na = min(n / 2, la), nb = n - na;
  if (A[na - 1] < B[nb - 1])
    return find_n_in_c(A + na, B, la - na, lb, n - na);
  else
    return find_n_in_c(A, B + nb, la, lb - nb, n - nb);
}

double find_medium(int *A, int *B, int n) {
  return ((double)find_n_in_c(A, B, n, n, n) + find_n_in_c(A, B, n, n, n + 1)) /
         2;
}

#define PINT(x) printf(#x " = %d\n", x)
#define PDOUBLE(x) printf(#x " = %f\n", x)

int main() {
  int A[] = {0, 2, 4, 6, 8}, B[] = {1, 3, 5, 7, 9}, n = 5;
  PINT(find_n_in_c(A, B, n, n, n));
  PDOUBLE(find_medium(A, B, n));
  return 0;
}