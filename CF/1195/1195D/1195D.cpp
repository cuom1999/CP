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

const ll K = 998244353;
string a[100005];

vector<string> v[15];
ll c[15][15];
ll pw[25];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	pw[0] = 1;

	FOR (i, 1, 20) {
		pw[i] = pw[i - 1] * 10 % K;
	}

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> a[i];
		v[a[i].size()].pb(a[i]);
	}

	FOR (i, 1, 10) {
		for (auto &s: v[i]) {
			FOR (j, 0, i - 1) {
				c[i][j] += s[j] - '0';
			}
		}
	}

	ll res = 0;
	FOR (p, 1, 10) {
		FOR (q, 1, 10) {
			if (!v[p].size() || !v[q].size()) continue;
			ll x = v[p].size();
			ll y = v[q].size();

			ll tmp = res;
			if (p >= q) {
				ll cur = p + q - 1;
				FOR (k, 0, p - q - 1) {
					res = (res + pw[cur] * c[p][k] % K * y % K) % K;
					cur--;
				}
				FOR (k, 0, q - 1) {
					res = (res + pw[cur] * c[p][k + p - q] % K * y % K) % K;
					cur--;
					res = (res + pw[cur] * c[q][k] % K * x % K) % K;
					cur--;
				}
			}
			else {
				ll cur = p + q - 1;
				FOR (k, 0, q - p - 1) {
					res = (res + pw[cur] * c[q][k] % K * x % K) % K;
					cur--;
				}
				FOR (k, 0, p - 1) {
					res = (res + pw[cur] * c[p][k] % K * y % K) % K;
					cur--;
					res = (res + pw[cur] * c[q][k + q - p] % K * x % K) % K;
					cur--;
				}
			}
			// if (res - tmp) cout << p << " " << q << " " << res - tmp << endl;
		}
	}

	cout << res << endl;

	return 0;
}