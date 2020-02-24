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

	vector<int> pos;

	FOR (i, l, r) {
		if (a[i] == minVal) {
			pos.pb(i);
		}
	}

	int firstIndex = pos[0];
	int lastIndex = pos.back();

	ll firstSum = 0;
	FOR (u, l, firstIndex) {
		firstSum = (firstSum + dp(u, firstIndex - 1) * dp(l, u - 1) % K) % K;
	}
	ll secondSum = 0;
	FOR (v, lastIndex, r) {
		secondSum = (secondSum + dp(lastIndex + 1, v) * dp(v + 1, r) % K) % K;
	}

	ll thirdProd = 1;
	for (int i = 0; i + 1 < pos.size(); i++) {
		thirdProd = thirdProd * dp(pos[i] + 1, pos[i + 1] - 1) % K;
	}

	ll res = firstSum * secondSum % K * thirdProd % K;

	// cout << l << " " << r << " " << firstSum << " " << secondSum << " " << thirdProd << endl;
	return d[l][r] = res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	FOR (i, 1, m) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));

	ll res = dp(1, m);
	cout << res << endl;

	return 0;
}