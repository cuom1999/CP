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
const ll K = 1e9 + 7;
int d[1000005], ma[1000005];
ll pw[1000005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	pw[0] = 1;
	FOR (i, 1, 1000000) pw[i] = pw[i - 1] * 2 % K;

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;
	s = '0' + s;

	d[0] = 0;
	ll res = 0;

	vector<int> v;

	FOR (i, 1, n) {
		if (s[i] == 'A') d[i] = d[i - 1] + 1;
		else d[i] = d[i - 1] - 1;

		if (s[i] == 'B') {
			v.pb(i - 1);
		}
	}
	ma[n] = d[n] + k;
	FORD (i, n - 1, 0) ma[i] = min(ma[i + 1], d[i] + k);

	for (auto i: v) {
		// cout << i << " " << d[i] << " " << ma[i + 1] << endl;
		if (d[i] > ma[i + 1]) {
			res = (res + pw[i + 1]) % K;
		}
	}

	cout << res << endl;

	return 0;
}