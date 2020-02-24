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



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
    	int a;
    	cin >> a;
    	bool q = 1 ;
    		
    	FOR (n, 3, 360) {
    		FOR (k, 1, n - 2) {
	    		int u = 180 * k;
	    		if (u % a == 0 && u/a == n) {
	    			cout << u / a << endl;
	    			q = 0;
	    			break;
	    		}
	    		if (!q) break;
	    	}
	    	if (!q) break;
    	}
    }
	
    return 0;
}