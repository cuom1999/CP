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

ll d[1 << 15][3][230];
const ll K = 1e9 + 7;
int n, T;
int t[20], g[20]; 

ll calc(int bit, int lastGen, int timeLeft) {
	// cout << bit << " " << lastGen << " " << timeLeft << endl;

	if (timeLeft == 0) {
		return 1;
	}
	if (timeLeft < 0) return 0;
	if (lastGen != -1 && d[bit][lastGen][timeLeft] != -1) return d[bit][lastGen][timeLeft];
	
	ll res = 0;
	FOR (i, 0, n - 1) {
		if (lastGen != g[i] && !(bit & (1 << i)) && t[i] <= timeLeft) {
			// cout << i << "." << endl;
			res += calc(bit | (1 << i), g[i], timeLeft - t[i]);
			res %= K;
		}
	}
	// cout << bit << " " << lastGen << " " << timeLeft << endl;

	// cout << res << endl;

	if (lastGen != -1) d[bit][lastGen][timeLeft] = res;
	return res;	
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	memset(d, -1, sizeof(d));
	cin >> n >> T;

	FOR (i, 0, n - 1) {
		cin >> t[i] >> g[i];
		g[i]--;
	}

	cout << calc(0, -1, T) << endl;

	return 0;
}