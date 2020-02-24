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

struct Point {
	int x, y;
} p[22];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 0, n - 1) cin >> p[i].x >> p[i].y;

	int res = 0;
	FOR (bit, 1, (1 << n) - 1) {
		int a = INF, b = 0, z = INF;
		FOR (i, 0, n - 1) {
			if (bit & (1 << i)) {
				a = min(a, p[i].x);
				b = max(b, p[i].x);
				z = min(z, p[i].y);
			}
		}

		bool isGood = 1;
		FOR (i, 0, n - 1) {
			if ((bit & (1 << i)) == 0) {
				if (a <= p[i].x && p[i].x <= b && p[i].y >= z) {
					isGood = 0;
				}
			}
		}
		res += isGood;
	}

	cout << res << endl;



	return 0;
}