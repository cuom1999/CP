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

ll d[105][100005];

struct Stone {
	int s, e, l;
	bool operator < (const Stone &a) {
		return l * a.s > a.l * s;
	}
}a[105];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		int n;
		cin >> n;

		FOR (i, 1, n) {
			cin >> a[i].s >> a[i].e >> a[i].l;
		}

		sort(a + 1, a + n + 1);

		ll res = 0;
		FOR (i, 1, n) {
			FOR (s, 0, 100000) {
				d[i][s] = d[i - 1][s];
				if (s >= a[i].s) {
					d[i][s] = max(d[i][s], d[i - 1][s - a[i].s] + max(0LL, a[i].e - (s - a[i].s) * 1ll * a[i].l));
				}

				if (i == n) res = max(res, d[i][s]);
			}
		}

		cout << res << endl;
	} 
    
	
    return 0;
}