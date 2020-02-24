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

    a[0] = -INF;

    FOR (i, 1, n) {
    	FORD (j, i, 0) {
    		if (a[j] + 5 < a[i]) {
    			pre[i] = j;
    			break;
    		}
    	}
    }
    int res = 0;

    FOR (j, 1, k) {
    	FOR (i, 1, n) {
    		if (j == 1) {
    			d[i][j] = max(d[i - 1][j], i - pre[i]);
    		}
    		else {
    			d[i][j] = max(d[i - 1][j], d[pre[i]][j - 1] + i - pre[i]);
    		}
    		res = max(res, d[i][j]);
    	}
    }

    cout << res << endl;
    
	
    return 0;
}