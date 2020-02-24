#include <bits/stdc++.h>

using namespace std;

const int maxs = 1500;

int f[maxs];

int sum(int x) {
  int res = 0;
  while (x > 0) {
    int d = x % 10;
    res += d * d;
    x /= 10;
  }
  return res;
}

int rec(int x) {
  int &res = f[x];
  if (~res) {
    return res;
  }
  res = 0;
  return res = rec(sum(x));
}

void init() {
  memset(f, -1, sizeof(f));
  f[1] = 1;
  for (int i = 2; i < maxs; ++i) {
    rec(i);
  }
}

int t;
int s;
int d[20];
long long g[20][maxs][2];

long long calc(int pos, int sum, int eql) {
  if (pos < 0) {
    return !f[sum];
  }
  long long &res = g[pos][sum][eql];
  if (~res) {
    return res;
  }
  res = 0;
  for (int x = 0; x <= (eql ? d[pos] : 9); ++x) {
    res += calc(pos - 1, sum + x * x, eql && x == d[pos]);
  }
  return res;
}

long long calc(long long x) {
  memset(d, 0, sizeof(d));
  for (int i = 0; x > 0; ++i, x /= 10) {
    d[i] = x % 10;
  }
  memset(g, -1, sizeof(g));
  return calc(19, 0, 1);
}

void solve() {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", calc(r) - calc(l - 1));
}

int main() {
  freopen("pearl.inp", "r", stdin);
  freopen("pearl.out", "w", stdout);
  init();
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
