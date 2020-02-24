// https://csacademy.com/contest/archive/task/popcorn/
#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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


ll st[200005 * 4], lz[200005 * 4];
int smallest[200005 * 4];

void down(int id, int l, int r) {
	if (l == r || !lz[id]) return;

	st[id * 2] += lz[id];
	lz[id * 2] += lz[id];

	st[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void build(int id, int l, int r) {
	if (l == r) {
		smallest[id] = l;
		st[id] = lz[id] = 0;
		return;
	} 
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);

	st[id] = lz[id] = 0;
	smallest[id] = l;
}

void update(int id, int l, int r, int u, int v, ll k) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		return;
	}

	int mid = (l + r) / 2;
	down(id, l, r);

	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
	if (st[id * 2] >= st[id * 2 + 1]) {
		smallest[id] = smallest[id * 2];
	}
	else {
		smallest[id] = smallest[id * 2 + 1];
	}
}

II getMax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return {-1, -1e18};
	if (u <= l && r <= v) return {smallest[id], st[id]};

	int mid = (l + r) / 2;
	down(id, l, r);

	II u1 = getMax(id * 2, l, mid, u, v);
	II u2 = getMax(id * 2 + 1, mid + 1, r, u, v);

	if (u1.second >= u2.second) {
		return u1;
	}
	else {
		return u2;
	}
}

vector<II> leftInt[200005];
vector<II> rightInt[200005];
int n, m;
int N;

II solve(ll x) {
	build(1, 0, N);
	ll d[200005], cnt[200005];

	d[0] = 0;
	ll res = 0;
	int numSub = 0;

	FOR (i, 1, N) {
		for (auto j: leftInt[i]) {
			update(1, 0, N, 0, i - 1, j.second);
		}
		// II u = getMax(1, 0, N, 0, i - 1);

		d[i] = st[1] - x;
		cnt[i] = cnt[smallest[1]] + 1;

		update(1, 0, N, i, i, d[i]);

		if (res <= d[i] || !numSub) {
			res = d[i];
			numSub = cnt[i];
		}

		for (auto j: rightInt[i]) {
			update(1, 0, N, 0, j.first - 1, -j.second);
		}
	}
	return {numSub, res};
}

int main() 
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	FOR (i, 1, n) {
		int l, r;
		ll c;
		cin >> l >> r >> c;
		
		if (l == r) continue;
		leftInt[l].pb({r, c});
		rightInt[r - 1].pb({l, c});
		N = max(N, r - 1);
	}

	ll L = 0, R = 1e12;
	while (L < R) {
		ll mid = (L + R) / 2;
		if (solve(mid).first <= m) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}

	II res = solve(L);
	cout << res.second + L * m << endl;

	return 0;
}