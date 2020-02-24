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

vector<int> prime;
int comp[100005], trace[100005], d[100005];

void sieve(int n) {
	FOR (i, 2, n) {
		if (!comp[i]) {
			prime.pb(i);
			trace[i] = i;
			d[i] = prime.size();
		}

		for (int j = 0; j < prime.size() && prime[j] <= n / i; j++) {
			comp[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				trace[i * prime[j]] = trace[i];
				d[i * prime[j]] = d[trace[i]];
				break;
			}
			else {
				trace[i * prime[j]] = prime[j];
				d[i * prime[j]] = d[prime[j]];
			}
		}
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	sieve(100000);

	// FOR (i, 2, 20) cout << trace[i] << " ";
	int n;
	cin >> n;

	FOR (i, 2, n) cout << d[i] << " ";

	return 0;
}