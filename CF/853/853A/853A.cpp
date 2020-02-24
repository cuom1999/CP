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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;



int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	n = 300000;
	k = 100000;
	II a[300005];

	FOR (i, 1, n) {
		cin >> a[i].first;
		a[i].first = rand();
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);

	int pos[300005];
	vector<bool> dd(2 * n + 1);

	ll res = 0;
	int cur = k + 1;

	FOR (i, 1, n) {
		int curPos = cur;
		if (cur < a[i].second) {
			curPos = a[i].second;
		}
		dd[curPos] = 1;
		while (dd[cur]) {
			cur++;
		}
		pos[a[i].second] = curPos;
		res += (curPos - a[i].second) * 1ll * a[i].first;
	}

	cout << res << endl;
	FOR (i, 1, n) cout << pos[i] << " ";


	return 0;
}