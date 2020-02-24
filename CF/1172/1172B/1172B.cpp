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

vector<int> v[200005];
int sub[200005], dd[200006];

void dfs(int a, int par) {
	for (auto i: v[a]) {
		if (i == par) continue;
		dfs(i, a);
		sub[a]++;
	} 
}

const ll K = 998244353;
ll gt[200005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	gt[0] = 1;
	FOR (i, 1, 200000) {
		gt[i] = gt[i - 1] * 1ll * i % K;
	}


	int n;
	cin >> n;
	FOR (i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int root = 1;
	dfs(root, 0);

	ll res = gt[sub[root]]; 
	FOR (i, 1, n) {
		if (i != root) {
			res = res * gt[sub[i] + 1] % K;
		}
	}
	cout << res * n % K << endl;

	return 0;
}