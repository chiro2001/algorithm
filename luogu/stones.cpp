#include <cstdio>

int min(int a, int b) { return a < b ? a : b; }

int n;
const int N = 301;
// 前缀和
int s[N] = {0};
int f[N][N];

// 5 1 3 5 2 4

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    s[i] += s[i - 1];
  }
  // 迭代长度
  for (int len = 2; len <= n; len++) {
    // 迭代左端点
    for (int i = 1; i + len - 1 <= n; i++) {
      // 求出右端点
      int j = i + len - 1;
      f[i][j] = 1e9;
      // 迭代中间断点
      for (int k = i; k < j; k++) {
        printf(
            "f[%d][%d] = min(f[%d][%d], f[%d][%d] + f[%d + 1][%d] + s[%d] - "
            "s[%d - 1])"
            " \n\t = min(%d, %d) = %d\n",
            i, j, i, j, i, k, k, j, j, i, f[i][j],
            f[i][k] + f[k + 1][j] + s[j] - s[i - 1],
            min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]));
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
      }
    }
  }
  printf("dp:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%3d%s", f[i][j], (j == n ? ",\n" : ", "));
    }
  }
  printf("%d\n", f[1][n]);
  return 0;
}