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

int p1[100006];
int p[100005];
ll a[100005], s[100005];
vector<int> v[100005];

void dfs(int x) {
	if (s[x] == -1) {
		s[x] = 1e18;
		for (auto i: v[x]) {
			s[x] = min(s[x], s[i]);
		}
		if (s[x] == 1e18) {
			s[x] = s[p[x]];
		}
	}
	for (auto i: v[x]) dfs(i);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin >> n;
	FOR (i, 2, n) {
		cin >> p[i];
		v[p[i]].pb(i);
	}
	FOR (i, 1, n) cin >> s[i];
	dfs(1);
	ll res = 0;

	//FOR (i, 1, n) cout << s[i] << " "; cout << endl;

	FOR (i, 1, n) {
		a[i] = s[i] - s[p[i]];
		if (a[i] < 0) {
			cout << -1 << endl;
			return 0;
		}
		res += a[i];
	}	

	cout << res << endl;






    return 0;
}