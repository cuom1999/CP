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

int h[300006];
int par[300005];
vector<int> v[300005];
void dfs(int a, int p){
	h[a] = h[p] + 1;
	par[a] = p;
	for (auto i: v[a]){
		if (i == p) continue;
		dfs(i, a);
	}
}

ll res[300005];

void update(int a, int p, int d, ll c, int x){
	if (h[a] <= h[x] + d) res[a] += c;
	for (auto i: v[a]){
		if (i == p) continue;
		update(i, a, d, c, x);
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n - 1){
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    dfs(1, 0);
    int m;
    cin >> m;
    FOR (i, 1, m){
    	int x, d;
    	ll c;
    	cin >> x >> d >> c;
    	update(x, par[x], d, c, x);
    }

    FOR (i, 1, n) {
    	cout << res[i] << " ";
    }
    
	
         return 0;
}