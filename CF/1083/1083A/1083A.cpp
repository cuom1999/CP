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

typedef pair < int, ll > II;
typedef pair < ll, ll > pll;

ll w[300005];
ll c[300005];
ll m[300006];

vector<II> v[300005];
ll res = 0;
void dfs(int a, int p) {
	m[a] = w[a];
	vector<ll> V;
	V.pb(w[a]);
	for (auto i: v[a]) {
		if (i.first == p) continue;
		dfs(i.first, a);
		c[i.first] = i.second;
		m[a] = max(m[i.first] + w[a] - i.second, m[a]);
		V.pb(m[i.first] + w[a] - i.second);
	}
	sort(all(V));
	reverse(all(V));
	res = max(res, m[a]);
	if (V.size() >= 2) res = max(res, V[0] + V[1] - w[a]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> w[i];
    FOR (i, 1, n - 1) {
    	int x, y, C;
    	cin >> x >> y >> C;
    	v[x].pb(II(y, C));
    	v[y].pb(II(x, C));
    }

    dfs(1, 0);
    
    cout << res << endl;
	
    return 0;
}