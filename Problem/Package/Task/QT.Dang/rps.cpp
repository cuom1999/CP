#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000;

int n;
char s[maxn + 1];
bitset<maxn> a[maxn];
int f[maxn];

int main() {
  freopen("rps.inp", "r", stdin);
  freopen("rps.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    reverse(s, s + strlen(s));
    a[i] = (bitset<maxn>)s;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] && !(f[i] && f[j])) {
        if ((~a[i] & a[j]).any()) {
          f[i] = f[j] = 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f[i];
  }
  printf("%d\n", ans);
  return 0;
}
