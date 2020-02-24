#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;

const int MAXN = 300005;

int x[MAXN], y[MAXN], z[MAXN], out[MAXN];
ll c[MAXN];
II a[MAXN];

II st[MAXN * 4];

const ll K = 1e9 + 7;

II merge(II a, II b) {
	II res;
	if (a.first == b.first) {
		res = {a.first, (a.second + b.second) % K};
	}
	else if (a.first > b.first) {
		res = b;
	}
	else {
		res = a;
	}
	return res;
}

void update(int id, int l, int r, int u, II v) {
	if (l == r) {
		st[id] = v;
		return;
	}
	int mid = (l + r) / 2;

	if (u <= mid) {
		update(id * 2, l, mid, u, v);
	}
	else {
		update(id * 2 + 1, mid + 1, r, u, v);
	}
	// st[id] = min(st[id * 2], st[id * 2 + 1]);
	st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

II getMin(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return II(1e18, 1e18);
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;

	II res = merge(getMin(id * 2, l, mid, u, v), getMin(id * 2 + 1, mid + 1, r, u, v));
	return res;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a + 1, a + n + 1);

	// FOR (i, 1, n) {
	// 	cout << a[i].second << " " << a[i].first << endl;
	// }

	FOR (i, 1, n) {
		x[i] = lower_bound(a + 1, a + n + 1, II(a[i].second + 1, -1)) - a - 1;
	}

	FOR (i, 1, n) {
		// FOR (j, x[x[i]] + 1, min(i - 1, x[i])) {
		// 	cout << j << " " << i << endl;
		// }
		y[i] = x[x[i]] + 1;
		z[i] = min(i - 1, x[i]);
		// cout << y[i] << " " << z[i] << endl;
	}

	ll maxIn = -1;
	FOR (i, 1, n) maxIn = max(maxIn, a[i].second);
	FOR (i, 1, n) {
		if (a[i].first > maxIn) {
			out[i] = 1;
		}
	}

	FOR (i, 1, n * 4) st[i] = {1e18, 1e18};

	FOR (i, 1, n) {
		if (!z[i]) {
			if (!out[i]) update(1, 1, n, i, {a[i].second - a[i].first, 1});
			else {
				update(1, 1, n, i, {a[i].second, 1});
			}
		}
		else {
			II res = getMin(1, 1, n, y[i], z[i]);
			if (!out[i]) update(1, 1, n, i, {res.first + a[i].second - a[i].first, res.second});
			else {
				update(1, 1, n, i, {res.first + a[i].second, res.second});
			}
		}
	}

	II res = {1e18, 1e18};

	FOR (i, 1, n) {
		II tmp = getMin(1, 1, n, i, i);
		// cout << tmp.first << " " << tmp.second << endl;
		if (out[i]) {
			res = merge(res, tmp);
		}
	}

	cout << res.second << endl;


	return 0;
}