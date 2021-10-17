#include <cstdio>
// #define PINT(x) printf(#x " = %d\n", x)
#define PINT(x)
int max(int a, int b) { return ((a) > (b) ? (a) : (b)); }
const size_t N_MAX = 1001, V_MAX = 1001;
int N = 3, V = 70;
int v[N_MAX + 1], w[N_MAX + 1];
int f[N_MAX + 1][V_MAX] = {0};
int f2[V_MAX] = {0};

int main() {
  scanf("%d%d", &N, &V);
  PINT(N);
  PINT(V);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &v[i], &w[i]);
    PINT(v[i]);
    PINT(w[i]);
  }
  // // 朴素方法
  // for (int i = 1; i <= N; i++) {
  //   // WHY: 必须先保证f[][小]先更新√
  //   // for (int j = 0; j <= V; j++) {
  //   for (int j = V; j >= 0; j--) {
  //     // 左半边子集：不选择 i 的方案
  //     f[i][j] = f[i - 1][j];
  //     if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
  //   }
  // }
  // PINT(f[N][V]);
  // printf("%d\n", f[N][V]);
  // // 优化方法
  // for (int i = 1; i <= N; i++) {
  // 	// 这里 j 从高到低循环，保证 f2[小] 先被计算出来，
  // 	// 被 f2[大] 利用。
  //   for (int j = V; j >= v[i]; j--) {
  // 		// 这里的 `if(j >= v[i])` 被整合进 `for`。
  //     f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
  //   }
  // }
  // PINT(f2[V]);
  // printf("%d\n", f2[V]);

  // 完全背包
  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= V; j++) {
  //     f[i][j] = f[i - 1][j];
  //     // 能装下一件
  //     if (j >= v[i]) {
  //       f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
  //     }
  //   }
  // }
  // printf("%d\n", f[N][V]);

  // 完全背包
  // for (int i = 1; i <= N; i++) {
  // 	for (int j = v[i]; j <= V; j++) {
  // 		f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
  //   }
  // }

  for (int i = 1; i <= N; i++) {
    for (int j = v[i]; j <= V; j++) {
      f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
    }
  }
  printf("%d\n", f2[V]);

  return 0;
}