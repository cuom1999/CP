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

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int r, c, k;
		int a[305][305];
		int l[305][305];

		cin >> r >> c >> k;

		FOR (i, 1, r) {
			FOR (j, 1, c) {
				cin >> a[i][j];
			}
		}

		FOR (i, 1, r) {
			FOR (j, 1, c) {
				int minVal = a[i][j], maxVal = a[i][j];
				l[i][j] = c - j + 1;
				FOR (u, j + 1, c) {
					minVal = min(minVal, a[i][u]);
					maxVal = max(maxVal, a[i][u]);
					if (maxVal - minVal > k) {
						l[i][j] = u - j;
						break;
					}
				}
			}
		}

		int res = 0;

		FOR (j, 1, c) {
			FOR (i, 1, r) {
				int minVal = l[i][j];
				FOR (u, i, r) {
					minVal = min(minVal, l[u][j]);
					res = max(res, minVal * (u - i + 1));
				}
			}
		}

		cout << res << endl;
	}

	return 0;
}