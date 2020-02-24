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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> v[200005];
int vs[200005];

vector<II> edges;

void dfs(int a) {
	for (auto i: v[a]) {
		if (!vs[i]) {
			edges.pb(II(i, a));
			vs[i] = 1;
			dfs(i);
		}
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;

    FOR (i, 1, m) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }

    int maxDeg = 0;
    int root = 0;

    FOR (i, 1, n) {
    	if (v[i].size() > maxDeg) {
    		maxDeg = v[i].size();
    		root = i;
    	}
    }

    vs[root] = 1;

    for (auto i: v[root]) {
    	edges.pb(II(root, i));
    	vs[i] = 1;
    }

    for (auto i: v[root]) dfs(i);
    
    for (auto i: edges) {
    	cout << i.first << " " << i.second << endl;	
    }
	
    return 0;
}