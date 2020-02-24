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

int a[2005][2005], s[2005][2005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m, n;
    cin >> n >> m;
    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		char c;
    		cin >> c;
    		if (c == '#') a[i][j] = 1;
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    	}
    }

    ll res = 0;

    FOR (x2, 1, n) {
    	FOR (y2, 1, m) {
    		FOR (x1, 0, x2 - 1) {
    			FOR (y1, 0, y2 - 1) {
    				int val = s[x1][y1] + s[x2][y2] - s[x1][y2] - s[x2][y1];
    				if (!val) {
    					res++;
    				}
    			}
    		}
    	}
    }

    cout << res << endl;
	
    return 0;
}