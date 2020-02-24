#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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


const int MAXN = 300005;

string s;
vector<int> l[2];

int m[MAXN];

void handle(vector<int> &v) {
	bitset<MAXN> pre, suf;
	for (auto i: v) suf[i] = 1;

	for (int i = 1; i < v.size(); i++) {
		pre <<= (2 * (v[i] - v[i - 1]));
		pre[2 * v[i] - v[i - 1]] = 1;
		suf[v[i]] = 0;
		bitset<MAXN> tmp = pre & suf;
		int u = tmp._Find_first();
		if (u != MAXN) {
			m[2 * v[i] - u] = min(m[2 * v[i] - u], u);
			// cout << v[i] << " " << u << endl;
		}
	}
}

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			l[0].pb(i);
		}
		else {
			l[1].pb(i);
		}
	}

	FOR (i, 0, s.size()) m[i] = INF;

	handle(l[0]);
	handle(l[1]);

	ll res = 0;
	int curM = INF;
	int n = s.size();
	FORD(i, s.size() - 1, 0) {
		curM = min(curM, m[i]);
		if (curM != INF) {
			res += (n - curM);
			// cout << i << " " << curM << endl;
		}
	}
	cout << res << endl;

	return 0;
}