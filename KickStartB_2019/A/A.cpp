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

int d[100005][27];
string s;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
	    int n, q;
	    cin >> n >> q;
	    cin >> s;

	    s = '0' + s;

	    FOR (i, 1, n) {
	    	FOR (j, 0, 25) d[i][j] = d[i - 1][j];
	    	d[i][s[i] - 'A']++;
	    }

	    int res = 0;

	    FOR (i, 1, q) {
	    	int l, r;
	    	cin >> l >> r;

	    	int oddCnt = 0;
	    	FOR (j, 0, 25) {
	    		if ((d[r][j] - d[l - 1][j]) % 2) oddCnt++;
	    	}

	    	if (oddCnt <= 1) res++;
	    }

	    cout << "Case #" << z << ": " << res << endl;
	}
	
    return 0;
}