#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("output.txt","r",stdin)
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

bool check(int x, int y, int u, int v) {
	return ((x != u) && (y != v) && (x + y != u + v) && (x - y != u - v));
}

int vs[21][21];
vector<II> v;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    FOR (m, 2, 20) {
    	FOR (n, 2, 20) {
    		v.clear();
    		string s;
    		cin >> s;

    		if (s == "IMPOSSIBLE") continue;
    		memset(vs, 0, sizeof(vs));

    		FOR (i, 1, m * n) {
    			int x, y;
    			cin >> x >> y;
    			v.pb({x, y});
    			vs[x][y] = 1;
    		}

    		for (int i = 0; i + 1 < v.size(); i++) {
    			if (!check(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second)) {
    				cout << m << " " << n << " wrong" << endl;
    				cout << v[i].first << " " << v[i].second << endl;
    				cout << v[i + 1].first << " " << v[i + 1].second << endl;
    				return 0;
    			}
    		}

    		FOR (i, 1, m) {
    			FOR (j, 1, n) {
    				if (!vs[i][j]) {
    					cout << m << " " << n << " wrong 2" << endl;
    				}
    			}
    		}
    	}
    }
	
	cout << "AC" << endl;
    return 0;
}