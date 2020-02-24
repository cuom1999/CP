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

int cnt[1005][6];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string s[1005];

	FOR (i, 1, n) {
		cin >> s[i];
	}

	FOR (i, 1, n) {
		FOR (j, 0, m - 1) cnt[j][s[i][j] - 'A']++;
	}


	ll a[1005];

	FOR (i, 0, m - 1) cin >> a[i];

	ll res = 0;
	FOR (i, 0, m - 1) {
		int maxVal = -1;
		FOR (j, 0, 4) {
			maxVal = max(maxVal, cnt[i][j]);
		}
		res += maxVal * a[i];
	}

	cout << res << endl;

	return 0;
}