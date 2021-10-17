#include <cstdio>
#include <cstring>

int max(int a, int b) { return a > b ? a : b; }

const int N_MAX = 1002;
int N, M;
char A[N_MAX], B[N_MAX];
int f[N_MAX][N_MAX];

int main() {
  strcpy(A, "abcde");
  strcpy(B, "ace");
  N = strlen(A);
  M = strlen(B);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // 先取 [01, 10] 两种情况的 MAX
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      // 如果 A[i] != B[i]，11 这种情况不会存在。
      if (A[i] == B[j])
        // 再考虑 11 这种情况的 MAX
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
      // （集合有重合）
    }
  }
  printf("%d\n", f[N - 1][M - 1]);
  return 0;
}