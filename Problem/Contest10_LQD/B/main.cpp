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

ll a[100005];

vector<ll> m[4];

int main()
{//IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	ll s = 0;

	FOR (i, 1, n) {
		cin >> a[i];
		s += a[i];
		m[a[i] % 3].pb(a[i]);
	}

	if (s % 3 == 0) {
		cout << s / 3 << endl;
	}

	else {
		int r = s % 3;
		sort(all(m[1]));
		sort(all(m[2]));

		ll res = 1e18;


		if (m[r].size() >= 1) {
			res = min(res, m[r][0]);
		}
		if (m[3 - r].size() >= 2) {
			res = min(res, m[3 - r][0] + m[3 - r][1]);
		}

		cout << (s - res) / 3 << endl;
	}



	return 0;
}