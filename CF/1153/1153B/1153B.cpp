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

int a[105], b[105], c[105][105];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, h;

    cin >> n >> m >> h;

    FOR (i, 1, m) {
    	cin >> a[i];
    }

    FOR (i, 1, n) {
    	cin >> b[i];
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		cin >> c[i][j];
    		if (c[i][j]) {
    			c[i][j] = min(a[j], b[i]);
    		}
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		cout << c[i][j] << " ";
    	}
    	cout << endl;
    }
	
    return 0;
}