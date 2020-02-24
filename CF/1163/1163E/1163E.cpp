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

vector<int> v;
int dd[200005];

bool solve(int bit, int sz, vector<int> &s, vector<int> &res) {
	if (bit == -1) return 1;
	vector<int> S[2];
	
	for (auto i: s) {
		if (i & (1 << bit)) {
			S[1].pb(i);
		}
		else {
			S[0].pb(i);
		}
	}

	if (S[1].size() == 0) return 0;
	if (bit == 0) {
		FOR (i, 0, sz - 1) res.pb((i >= (sz / 2)));
		return 1;
	}
	// cout << S[0].size() << " " << S[1].size() << " " << s.size() << endl;
	if (S[0].size()) {
		vector<int> res1;
		bool u = solve(bit - 1, sz / 2, S[0], res1);
		if (u) {
			int m = S[1][0] ^ res1.back();
			for (auto i: res1) res.pb(i);
			for (auto i: res1) {
				res.pb(i ^ m);
			}
			return 1;
		}
		return 0;
	}
	else {
		vector<int> tmp;
		for (auto i: S[1]) {
			int u = i ^ (1 << bit);
			if (!dd[u]) tmp.pb(u);
			dd[u] = 1;
		}
		vector<int> res1; 
		bool u = solve(bit - 1, sz, tmp, res1);
		if (u) {
			res = res1;	
			FOR (i, 0, sz - 1) {
				if (i % 2 == 0) res[i] ^= (1 << bit);
			}
		}
		return u;
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;

	FOR (i, 1, n) {
		int x;
		cin >> x;
		v.pb(x);
	}
	// vector<int> empty;

	// cout << solve(2, empty) << endl;	

	FORD (i, 17, 0) {
		memset(dd, 0, sizeof(dd));
		for (auto j : v) dd[j] = 1;
		vector<int> res;
		int sz = (1 << (i + 1));

		if (solve(i, sz, v, res)) {
			cout << i + 1 << endl;
			for (auto j: res) cout << j << " "; cout << endl;
			FOR (j, 1, res.size() - 1) {
				int m = res[j - 1] ^ res[j];
				cout << m << " ";
			}
			return 0; 
		}
	}

	cout << 0 << endl << 0 << endl;

	return 0;
}