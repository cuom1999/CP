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

const int MAXN = 30005;

vector<ll> v[MAXN * 4];
ll a[MAXN];

void merge(vector<ll> &a, vector<ll> &b, vector<ll> &vec) {
	vec.clear();
	vector<ll> tmp = a;
	for (auto i: b) {
		tmp.pb(i);
	}  
	sort(all(tmp));
	for (int i = 0; i < 50 && i < tmp.size(); i++) {
		vec.pb(tmp[i]);
	}
}

void build (int id, int l, int r) {
	if (l == r) {
		v[id].pb(a[l]);
		return;
	}

	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	merge(v[id * 2], v[id * 2 + 1], v[id]);
}

void update(int id, int l, int r, int u) {
	if (l == r) {
		v[id].clear();
		v[id].pb(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	if (u <= mid) {
		update(id * 2, l, mid, u);
	}
	else {
		update(id * 2 + 1, mid + 1, r, u);
	}

	merge(v[id * 2], v[id * 2 + 1], v[id]);
}	
vector<ll> empty;

vector<ll> query(int id, int l, int r, int u1, int u2) {
	if (u2 < l || r < u1) {
		return empty;
	}
	if (u1 <= l && r <= u2) {
		return v[id];
	}

	vector<ll> res;
	int mid = (l + r) / 2;
	vector<ll> v1 = query(id * 2, l, mid, u1, u2);
	vector<ll> v2 = query(id * 2 + 1, mid + 1, r, u1, u2);  
	merge(v1, v2, res);
	return res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	build(1, 1, n);

	FOR (z, 1, q) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			ll u;
			cin >> x >> u;
			a[x] += u;
			update(1, 1, n, x);
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;

			vector<ll> vec = query(1, 1, n, l, r);
			ll res = 0;
			FOR (i, 0, k - 1) res += vec[i];
			cout << res << endl;
		}
	}

	return 0;
}