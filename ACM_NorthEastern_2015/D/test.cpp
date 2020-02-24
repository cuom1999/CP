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

int d[1005][1005];
queue<int> Q;
vector<int> v[1005];
int dd[1005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n - 3) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	v[x].pb(y);
    	v[y].pb(x);
    }

    FOR (i, 0, n - 1) {
    	v[i].pb((i + 1) % n);
    	v[i].pb((i + n - 1) % n);
    }

    FOR (i, 0, n - 1) {
    	d[i][i] = 0;
    	FOR (j, 0, n - 1) dd[j] = 0;
    	dd[i] = 1;
    	Q.push(i);
    	while (Q.size()) {
    		int u = Q.front();
    		Q.pop();
    		for (auto j: v[u]) {
    			if (!dd[j]) {
    				d[i][j] = d[i][u] + 1;
    				dd[j] = 1;
    				Q.push(j);
    			}
    		}
    	}
    }

    int q;
    cin >> q;
    FOR (z, 1, q) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	cout << d[x][y] << endl;
    }

	
    return 0;
}