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



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;

	cin >> n;
	
	int cnt = 0;

	FOR (i, 1, n) {
		ld x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2) swap(x1, x2);

		int x = floor(x1 - eps);
		if (x + 1 <= x2) {
			cnt++;
		}
	}

	ld x = cnt * 1.0 / n;
	cout << fixed << setprecision(8) << 2.0 / x << endl;

	return 0;
}