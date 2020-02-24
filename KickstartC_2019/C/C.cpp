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
typedef pair < ll, ll > pll;

vector<int> mul(vector<int> &a, vector<int> &b) {
	int m = a.size();
	int n = b.size();

	vector<int> res(m + n - 1);
	FOR (i, 0, m + n - 2) res[i] = INF;

	FOR (i, 0, m - 1) {
		FOR (j, 0, n - 1) {
			res[i + j] = min(res[i + j], a[i] + b[j]);
		}
	}
	return res;
}

int dd[1005];
int a[1005], p[1005];
vector<int> v[1005];

vector<int> st[4005];

void build(int id, int l, int r) {
	if (l == r) {
		for (auto i: v[l]) st[id].pb(i);
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = mul(st[id * 2], st[id * 2 + 1]);
}

vector<int> getPoly(int id, int l, int r, int u, int v) {
	if (v < l || r < u || u > v) {
		vector<int> res;
		res.pb(0);
		return res;
	}
	if (u <= l && r <= v) {
		return st[id];
	}

	int mid = (l + r) / 2;

	vector<int> A = getPoly(id * 2, l, mid, u, v);
	vector<int> B = getPoly(id * 2 + 1, mid + 1, r, u, v);
	A = mul(A, B);
	return A;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		FOR (i, 1, 1000) {
			v[i].clear();
			a[i] = p[i] = dd[i] = 0;
		}

		FOR (i, 1, 4000) st[i].clear();

		int n, k;
		cin >> n >> k;
		FOR (i, 1, n) {
			cin >> p[i];
		}

		int C = 0;

		FOR (i, 1, n) {
			cin >> a[i];
			if (!dd[a[i]]) {
				dd[a[i]] = ++C;
				v[C].pb(0);
			}
			v[dd[a[i]]].pb(p[i]);
		}
		
		FOR (i, 1, C) {
			sort(all(v[i]));
		}

		build(1, 1, C);
		
		int res = INF;

		FOR (i, 1, C) {
			vector<int> l = getPoly(1, 1, C, 1, i - 1);
			vector<int> r = getPoly(1, 1, C, i + 1, C);
			l = mul(l, r);
			for (auto &j: l) {
				j *= 2;
			}
			l = mul(l, v[i]);

			res = min(res, l[k]);
		}

		cout << res << endl;
	}
	return 0;
}