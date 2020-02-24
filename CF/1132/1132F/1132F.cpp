#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

string s;
int d[505][505];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	int n;

	cin >> n;
	cin >> s;

	s = '0' + s;

	FOR (len, 0, n - 1) {
		FOR (i, 1, n - len) {
			if (len == 0) {
				d[i][i] = 1;
				continue;
			}
			int j = len + i;
			d[i][j] = 1 + d[i + 1][j];

			FOR (k, i + 1, j) {
				if (s[k] == s[i]) {
					d[i][j] = min(d[i][j], d[i + 1][k - 1] + d[k][j]);
				}
			}
		}
	}

	cout << d[1][n] << endl;


    return 0;
}