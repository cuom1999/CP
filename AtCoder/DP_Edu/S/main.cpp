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

ll d[100005][105][2];
string s;
int n;
int k;
const int K = 1e9 + 7;

ll calc(int i, int r, bool type) {
	if (i == n + 1) {
		if (r == 0) return 1;
		return 0;
	}

	if (d[i][r][type] != -1) {
		return d[i][r][type];
	}

	ll res = 0;

	if (type == 0) {
		FOR (digit, 0, 9) {
			res = (res + calc(i + 1, (r + digit) % k, 0)) % K;
		}
	}
	else {
		FOR (digit, 0, s[i] - '0') {
			bool newType = 0;
			if (digit == s[i] - '0') newType = 1;

			res = (res + calc(i + 1, (r + digit) % k, newType)) % K;
		}
	}

	return d[i][r][type] = res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	cin >> s >> k;
	n = s.length();
	s = '*' + s;

	FOR (i, 1, 100000) {
		FOR (j, 0, 100) {
			FOR (k, 0, 1) d[i][j][k] = -1;
		}
	}

	cout << (calc(1, 0, 1) + K - 1) % K << endl;

    return 0;
}