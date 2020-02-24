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



int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;

	int a[100005];

	FOR (i, 1, n) {
		cin >> a[i];
	}

	ll res = 0;
	FOR (i, 1, n) {
		FOR (j, i + 1, n) {
			int u = abs(a[i] + a[j]);
			int v = abs(a[i] - a[j]);

			if (u > v) swap(u, v);

			if (u <= min(abs(a[i]), abs(a[j])) && max(abs(a[i]), abs(a[j])) <= v) {
				res++;
				cout << i << " " << j << endl;
			}
		}
	}

	cout << res << endl;

	return 0;
}