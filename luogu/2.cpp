#include <cstdio>

const int N = 8;

int E[N][N];
double W[N][N];
double p[] = {0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14};
double q[] = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05} double p_s[N];
double p_s[N];
double q_s[N];

int main() {
  for (int i = 0; i < N; i++) {
    p_s[i] = i == 0 ? (p[0]) : (p[i] + p_s[i - 1]);
    q_s[i] = i == 0 ? (q[0]) : (q[i] + q_s[i - 1]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      W[i][j] = (p_s[i] - p_s[j]) + ((i == 0 ? 0 : q_s[i - 1]) - q_s[j]);
    }
  }
  
  return 0;
}