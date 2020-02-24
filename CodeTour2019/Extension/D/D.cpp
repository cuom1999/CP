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

vector<int> v[5];
ll a[100005], b[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, c;

	cin >> n >> c;

	FOR (i, 1, n) {
		int d, e;
		cin >> d >> e;
		v[d].pb(e);
	}

	sort(all(v[1]));
	sort(all(v[2]));
	reverse(all(v[1]));
	reverse(all(v[2]));

	int m1 = v[1].size();
	int m2 = v[2].size();

	for (int i = 0; i < m1; i++) {
		a[i + 1] = a[i] + (ll) v[1][i];
	}

	for (int i = 0; i < m2; i++) {
		b[i + 1] = b[i] + (ll) v[2][i];
	}

	ll res = 0;

	FOR (i, 0, m2) {
		if (i * 2 > c) break;
		int j = c - i * 2;

		res = max(res, a[min(j, m1)] + b[i]);
	}

	cout << res << endl;
	return 0;
}