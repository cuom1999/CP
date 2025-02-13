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

int d[5005][5005];
int a[5005], pre[5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    sort(a + 1, a + n + 1);
 
    FOR (j, 1, k) {
    	FOR (i, 1, n) {
    		d[i][j] = d[i - 1][j];
    		FORD (u, i, 1) {
    			if (a[u] + 5 < a[i]) break;
    			d[i][j] = max(d[i][j], d[u - 1][j - 1] + i - u + 1);
    		}
    	}
    }

    cout << d[n][k] << endl;
    
	
    return 0;
}