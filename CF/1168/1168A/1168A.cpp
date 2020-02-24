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

int a[300005];

int n, m;

bool solve(int k) {
	int mi = 0;

	FOR (i, 1, n) {
		if (a[i] + k < m) {
			mi = max(mi, a[i]);
			if (mi > a[i] + k) return 0;
		}
		else {
			if (mi <= (a[i] + k) % m) {

			}
			else {
				mi = max(mi, a[i]);
			}
		}
	}
	return 1;
}

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> m;

	FOR (i, 1, n) {
		cin >> a[i];
	}


	int L = 0, R = m - 1;

	while (L < R) {
		int mid = (L + R) / 2;
		if (solve(mid)) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}

	cout << L << endl;

	return 0;
}