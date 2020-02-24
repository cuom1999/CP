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

ll M;

ll vp(int p, int n) {
	int prod = 1;
	ll res = 0;

	while (prod <= n / p) {
		prod *= p;
		res += n / prod;
	}

	return res;
}

int comp[1000005];

int main()
{//IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n >> M;

	FOR (i, 2, n) {
		FOR (j, 2, n / i) {
			comp[i * j] = 1;
		}
	}

	ll res = 1;
	FOR (i, 3, n) {
		if (!comp[i]) {
			res = res * 1ll * (vp(i, n) + 1) % M;
		}
	}

	cout << (res + M - 1) % M << endl;

	return 0;
}