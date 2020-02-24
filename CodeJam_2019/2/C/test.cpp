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
typedef pair < ll, ll > II;

II a[15];
ll b[15];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {

		cout << "Case #" << z << ": ";
		int n;
		cin >> n;

		FOR (i, 1, n) {
			cin >> a[i].first >> a[i].second; 
		}
		bool isDone = 0;
		FOR (x, 1, 200) {
			bool isGood = 0;
			FOR (y, 1, 200) {
				FOR (j, 1, n) {
					b[j] = a[j].first * x + a[j].second * y; 
				}
				bool isTrue = 1;
				FOR (j, 2, n) {
					if (b[j] <= b[j - 1]) {
						isTrue = 0;
						break;
					}
				}
				if (isTrue) {
					cout << x << " " << y << endl;
					isGood = 1;
					isDone = 1;
					break;
				}
			}
			if (isGood) break;
		}
		if (!isDone) {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}