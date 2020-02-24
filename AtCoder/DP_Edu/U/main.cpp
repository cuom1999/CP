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

ll cost[(1 << 16)];
ll d[1 << 16];

ll a[17][17];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	FOR (i, 0, n - 1) {
		FOR (j, 0, n - 1) {
			cin >> a[i][j];
		}
	}

	FOR (i, 1, (1 << n) - 1) {
		vector<int> bits;
		FOR (j, 0, n - 1) {
			if ((1 << j) & i) {
				bits.pb(j);
			}
		}
		cost[i] = cost[i - (1 << (bits[0]))];
		
		for (int j = 1; j < bits.size(); j++) {
			cost[i] += a[bits[0]][bits[j]];
		}
	}

	FOR (i, 0, (1 << n) - 1) {
		d[i] = cost[i];
		for (int j = i; j; j = (j - 1) & i) {
			if (j) d[i] = max(d[i], cost[j] + d[i ^ j]);
		}
	}

	cout << d[(1 << n) - 1] << endl;







	
    return 0;
}