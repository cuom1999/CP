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

const ll K = 1e9 + 7;

string s;
int n;

ll d[5005][5005];

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;
	cin >> s;

	s = '0' + s;

	d[1][1] = 1;

	FOR (i, 2, n) {
		if (s[i - 1] == '<') {
			FOR (j, 1, i) {
				d[i][j] = (d[i - 1][j - 1] + d[i][j - 1]) % K;
			}		
		}
		else {
			FORD (j, i, 1) {
				d[i][j] = (d[i - 1][j] + d[i][j + 1]) % K; 
			}
		}
	}

	ll res = 0;

	FOR (i, 1, n) {
		res = (res + d[n][i]) % K;
	}

	cout << res << endl;
	
	return 0;
}
