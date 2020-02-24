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

int n;
int S;
vector<int> v[300005];
int h[300005];
vector<int> EulerTour;
int par[300005];

void dfs(int a, int p){
	h[a] = h[p] + 1;
	EulerTour.pb(a);
	par[a] = p;
	for (auto i: v[a]){
		if (i != p){
			dfs(i, a);
		}
	}
	EulerTour.pb(a);
}

ll res[300005];
int dd[300005];

struct query
{
	int d;
	ll c;
	query(int __d = 0, ll __c = 0){
		d = __d;
		c = __c;
	}
};

vector<query> Q[300005];
ll D[300005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
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
    	Q[x].pb(query(d, c));
    }

    for (auto i: EulerTour){
    	if (!dd[i]){
    		res[i] = res[par[i]];
    		for (auto j: Q[i]){
    			ll u = h[i] + j.d;
    			if (u > n) u = n;
    			D[u] += j.c;
    			res[i] += j.c;
    		}
    		dd[i] = 1;
    		res[i] -= D[h[i] - 1];
    	}
    	else{
    		for (auto j: Q[i]){
    			ll u = h[i] + j.d;
    			if (u > n) u = n;
    			D[u] -= j.c;
    		}
    	}
    }

    FOR (i, 1, n) cout << res[i] << " ";

         return 0;
}