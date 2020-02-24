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
const int MAXN = 105;

int match[MAXN], vs[MAXN];
vector<int> v[MAXN];

// find an augmenting path
bool findPath(int u, int t) { // u: a right vertex, t: time
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

	int cnt=0;

	FOR (i, 1, m) {
		cnt += findPath(i,i);
	}

	return cnt;
}

int a[65], b[65], c[65], d[65];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int m;
	cin >> m;

	FOR (i, 1, m) {
		cin >> a[i] >> b[i];
	}

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> c[i] >> d[i];
	}

	FOR (i, 1, m) {
		FOR (j, 1, n) {
			if (a[i] >= d[j] && b[i] > c[j]) {
				v[i].pb(j);
			}
		}
	}

	cout << biMatching(m, n) << endl;


	return 0;
}