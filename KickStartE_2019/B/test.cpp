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

struct II {
	ll c, e;
} a[100005];
ll sumC[100005], sumE[100005], g[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n, m; 
		cin >> m >> n;

		ll X = 0;
		FOR (i, 1, n) {
			cin >> a[i].c >> a[i].e;
			X += a[i].e;
		}

		sort(a + 1, a + n + 1, [](II x, II y) {
			return x.c * y.e > x.e * y.c;
		});

		FOR (i, 1, n) {
			sumC[i] = sumC[i - 1] + a[i].c;
			sumE[i] = sumE[i - 1] + a[i].e;
			g[i] = a[i].e * sumC[i] - a[i].c * sumE[i] + X * a[i].c;
		}

		FOR (i, 1, m) {
			ll A, B;
			cin >> A >> B;
			bool q = 0;
			FOR (j, 1, n) {
				cout << g[j] - A * a[j].e - B * a[j].c << " "; 

				ld y = a[j].c * 1.0 / a[j].e;

				// cout << y << ": ";
				// ld res = (X - B) * y;
				// FOR (k, 1, n) {
				// 	res += max((ld) 0, a[k].c - y * a[k].e);
				// }
				// cout << (res - A) * a[j].e << endl;
				if (g[j] - A * a[j].e - B * a[j].c < 0) q = 1;
			}		
			if (!q) cout << "Y";
			else cout << "N";	
		}
		cout << "\n";
	}


	return 0;
}