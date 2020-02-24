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

int d[1000005][23];
int s[1000005];
int n;

int solve(vector<int> &a) {
	int k = a.size();
	k--;
	s[k] = a[k];

	FORD (i, k - 1, 0) s[i] = s[i + 1] + a[i];

	memset(d, 0, sizeof(d));
	d[1][k] = 1;
	
	FOR (i, 1, n) {
		int u = max(k + 1 - i, 0);
		FOR (j, u, k) {
			if (j) {
				d[i + 1][j - 1] = (d[i + 1][j - 1] + (a[j - 1]) * 1ll * d[i][j] % K) % K;
			}
			if (s[j] - i > 0) {
				d[i + 1][j] = (d[i + 1][j] + (s[j] - i) * 1ll * (d[i][j]) % K) % K;
			}
			else break;
		}	
	}

	return d[n][0];
}
vector<int> a;

void handle(vector<int> &b) {
	a.clear();
	int sum = 0;
	for (auto i: b) {
		int s = n / i;
		s -= sum;
		sum += s;
		a.pb(s);
	}
	reverse(all(a));
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	int k = flog2(n);
	
	vector<int> b;
	FOR (i, 0, k) b.pb(1 << i);
	reverse(all(b));

	handle(b);


	int res = solve(a);

	if (3 * (1 << (k - 1)) <= n) {
		int m = 3 * (1 << (k - 1));

		FOR (i, 1, k) {
			b.clear();
			int M = m;
			FOR (j, 1, i) {
				b.pb(M);
				if (j < i) M /= 2;
			}
			M /= 3;
			FOR (j, i + 1, k) {
				b.pb(M);
				M /= 2;
			}
			b.pb(M);

			handle(b);
			res = (res + solve(a)) % K;
		}
	}

	cout << res << endl;

	return 0;
}