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

ll d[22][(1 << 21) + 1];
int a[22][22];
int n;
    
const ll K = 1e9 + 7;

ll calc(int i, int bit) {
	if (i == n + 1) {
		return 1;
	}
	if (d[i][bit] != -1) return d[i][bit];

	ll res = 0;

	FOR (j, 0, n - 1) {
		if ((((1 << j) & bit) == 0) && a[i][j + 1]) {
			res = (res + calc(i + 1, bit | (1 << j))) % K;
		}
	}

	//cout << i << " " << bit << " " << res << endl;

	return d[i][bit] = res;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    FOR (i, 1, n) {
    	FOR (j, 1, n) cin >> a[i][j];
    }

    FOR (i, 0, 21) {
    	FOR (j, 0, (1 << 21)) d[i][j] = -1;
    }

    cout << calc(1, 0) << endl;


    return 0;
}