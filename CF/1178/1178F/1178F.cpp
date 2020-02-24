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

ll d[505][505];
int a[505];

ll dp(int l, int r) {
	if (l == r || l == r + 1) return 1;
	if (d[l][r] != -1) return d[l][r];
	int minVal = INF;
	int index = 0;
	FOR (i, l, r) {
		if (a[i] < minVal) {
			minVal = a[i];
			index = i;
		}
	}

	ll firstSum = 0;
	FOR (u, l, index) {
		firstSum = (firstSum + dp(u, index - 1) * dp(l, u - 1) % K) % K;
	}
	ll secondSum = 0;
	FOR (v, index, r) {
		secondSum = (secondSum + dp(index + 1, v) * dp(v + 1, r) % K) % K;
	}

	ll res = firstSum * secondSum % K;
	return d[l][r] = res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	FOR (i, 1, n) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));

	ll res = dp(1, n);
	cout << res << endl;

	return 0;
}