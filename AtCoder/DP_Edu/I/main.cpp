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

ld p[3005];
ld d[3005][3005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    d[0][0] = 1;

    FOR (i, 1, n) {
    	cin >> p[i]; 
    }

    FOR (i, 1, n) {
    	FOR (j, 0, i) {
    		d[i][j] = d[i - 1][j] * (1 - p[i]) + d[i - 1][j - 1] * p[i];
    	}
    }



    ld res = 0;

    FOR (i, n / 2 + 1, n) {
    	res += d[n][i];
    }

    cout << fixed << setprecision(11) << res << endl;
    
	
    return 0;
}