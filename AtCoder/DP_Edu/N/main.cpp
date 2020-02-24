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

ll cost[405][405];
ll prefixSum[405];

ll d[405][405]; 

ll a[405];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	FOR (i, 1, n) {
		prefixSum[i] = prefixSum[i - 1] + a[i];
	}

	FOR (i, 1, n) {
		FOR (j, i, n) {
			cost[i][j] = prefixSum[j] - prefixSum[i - 1];
		}
	}

	FOR (len, 0, n - 1) {
		FOR (i, 1, n) {
			int j = i + len;
			if (len == 0) {
				d[i][j] = 0;
				continue;
			}
			d[i][j] = 1e18;

			FOR (k, i, j - 1) {
				d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + cost[i][j]);
			}
		}
	}    

	cout << d[1][n] << endl;
	
    return 0;
}