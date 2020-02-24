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
typedef pair < ll, ll > pll;

int match[5004],vs[5005];
vector<int> v[5005];

bool findPath(int u, int t){
	// cout << u << " " << t << endl;
	if (vs[u] != t){
		vs[u] = t;
	}
	else return 0;

	for (auto i: v[u]){
		if (!match[i] || findPath(match[i], t)) {
			match[i] = u;
			return 1;
		}
	}
	return 0;
}

int biMatching (int m, int n) {
	FOR (i, 1, max(m,n)) match[i] = vs[i] = 0;
	int cnt = 0;

	FOR (i, 1, m){
		if (!findPath(i, i)) return i - 1;
	}

	return m;
}

int p[5005], c[5005];
int dd[5005];

vector<int> query, ans;

inline void addEdge(int i) {
	v[p[i] + 1].pb(c[i]);
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	FOR (i, 1, n) cin >> p[i];
	FOR (i, 1, n) cin >> c[i];

	int t;
	cin >> t;
	FOR (z, 1, t) {
		int x;
		cin >> x;
		query.pb(x);
		dd[x] = 1;
	}

	FOR (i, 1, n) {
		if (!dd[i]) {
			addEdge(i);
		}
	}

	reverse(all(query));
	int res = 0;

	for (auto q: query) {
		FOR (i, 1, m) vs[i] = 0;

		FOR (i, res + 1, m + 1) {
			if (!findPath(i, i)) {
				res = i - 1;
				break;
			}
		}
		// cout << res << endl;
		ans.pb(res);
		addEdge(q);
	}


	reverse(all(ans));

	for (auto i: ans) cout << i << "\n";
		return 0;
}