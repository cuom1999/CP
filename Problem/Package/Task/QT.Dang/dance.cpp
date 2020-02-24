#include <bits/stdc++.h>

using namespace std;

const int maxm = 12;
const int maxn = 70002;
const int maxp = 30002;
const int maxb = 102;

int m, n, p, w;
int a[maxm][maxn];
int b[maxp];
long long s[maxn];

void compute(int a[]) {
  for (int i = 1; i <= p; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 1; i <= p; ++i) {
    for (int j = i; j <= n - p + i; ++j) {
      s[j - i] += b[i] * a[j];
    }
  }
}

int main() {
  freopen("dance.inp", "r", stdin);
  freopen("dance.out", "w", stdout);
  scanf("%d%d%d%d", &n, &p, &m, &w);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 1; i <= m; ++i) {
    compute(a[i]);
  }
  int ans = 0;
  for (int i = 0; i <= n - p; ++i) {
    if (s[i] > w) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
