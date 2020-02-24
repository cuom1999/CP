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

ll d[105][100005];

ll s[105][100005];

int a[105];

const int K = 1e9 + 7;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    d[0][0] = 1;
    s[0][0] = 1;
     
    FOR (i, 1, n) {
    	d[i][0] = d[i - 1][0];
    	FOR (j, 1, k) {
    		d[i][j] = (d[i - 1][j] + d[i][j - 1]) % K;
    	}

    	FORD (j, k, a[i] + 1) {
    		d[i][j] = (d[i][j] - d[i][j - a[i] - 1] + K) % K;
    	}

    }

    cout << d[n][k] << endl;

    return 0;
}