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

ll a[100005];

int b[100005], c[100005];
ll d[100005], pre[100005];

const ll K = 1e9 + 7;

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	ll l, r;
	cin >> n >> l >> r;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	vector<ll> s;

	s.pb(0);

	FOR (i, 1, n) {
		s.pb(s.back() + a[i]);
	}

	FOR (i, 1, n) {
		if (s[i] < l) b[i] = -1; 
		else {
			b[i] = upper_bound(all(s), s[i] - l) - s.begin() - 1;
 		}
		if (s[i] < r) c[i] = 0;
		else {
			c[i] = lower_bound(all(s), s[i] - r) - s.begin();
		}

		// cout << b[i] << " " << c[i] << endl;
	}

	d[0] = 1;
	pre[0] = 1;

	FOR (i, 1, n) {
		if (b[i] == -1) {
			d[i] = 0;
		}
		else {
			if (c[i] <= 0) {
				d[i] = pre[b[i]];
			}
			else {
				d[i] = (pre[b[i]] - pre[c[i] - 1] + K) % K;
			}
		}
		pre[i] = (pre[i - 1] + d[i] ) % K;
		// cout << d[i] << endl;
	}

	cout << d[n] << endl;
	return 0;
}