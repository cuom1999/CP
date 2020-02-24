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

int comp[1000005], trace[1000005];
vector<int> prime;
void sieve(int n) {
	FOR (i, 2, n) {
		if (!comp[i]) {
			prime.pb(i);
			trace[i] = i;
		}
		for (int j = 0; j < prime.size() && prime[j] <= n / i; j++) {
			comp[prime[j] * i] = 1;
			if (i % prime[j] == 0) {
				trace[i * prime[j]] = trace[i];
				break;
			}
			else trace[i * prime[j]] = prime[j];
		}
	}
}

ll calc(int n) {
	return n * 1ll * (n + 1) / 2;
}

vector<int> pos[1000005];
int a[1000005], A[1000005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    sieve(1000000);
	int n;
	cin >> n;
	FOR (i, 1, n) {
		cin >> a[i];
		A[i] = a[i];
		while (a[i] > 1) {
			int u = trace[a[i]];
			while (a[i] % u == 0) a[i] /= u;
			pos[u].pb(i);
		}
	}
	ll ans = 0;
	for (int z = 0; z < prime.size(); z++) {
		int j = prime[z];
		if (pos[j].size() == 0) continue;
		pos[j].pb(n + 1);
		ll res = 0;
		res = res + calc(pos[j][0] - 1);
		for (int i = 1; i < pos[j].size(); i++) {
			res += calc(pos[j][i] - pos[j][i - 1] - 1);
		}
		ans += calc(n) - res;
		/*if (res < calc(n)) {
			cout << j << " " << calc(n) - res << endl;
			int cnt = 0;
			FOR (i, 1, n) { 
				FOR (k, i, n) {
					bool q = 0;
					FOR (t, i, k) {
						if (A[t] % j == 0) q = 1;
					}
					cnt += q;
				}
			}
			cout << cnt << endl;
		}*/
	}
	cout << ans << endl;

	
    return 0;
}