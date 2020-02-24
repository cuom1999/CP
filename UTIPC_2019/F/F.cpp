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

int a[100005];
ll fen[100005];
int n;

void add(int u, int v) {
	for (int i = u; i <= n; i += i & -i) {
		fen[i] += v;
	}
}

ll getSum(int u) {
	ll res = 0;
	for (int i = u; i; i -= i & -i) {
		res += (ll) fen[i];
	}
	return res;
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	FOR (i, 1, n) {
		cin >> a[i];
	}
	ll res = 0;
	FOR (i, 1, n) {
		ll sum = getSum(n) - getSum(a[i]);
		res += sum * 1ll * (n + 1 - i);

		add(a[i], i);
	}

	cout << res << endl;


	// ll cnt = 0;
	// FOR (l, 1, n) {
	// 	FOR (r, l, n) {
	// 		FOR (i, l, r) {
	// 			FOR (j, i, r) {
	// 				if (a[i] > a[j]) {
	// 					cnt++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// cout << cnt << endl;
	return 0;
}