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


int minInd[2], maxInd[2];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	s = '.' + s;
	FOR (i, 1, n) {
		if (s[i] == '0') {
			maxInd[0] = i;
		}
		else {
			maxInd[1] = i;
		}
	}

	FORD (i, n, 1) {
		if (s[i] == '0') {
			minInd[0] = i;
		}
		else {
			minInd[1] = i;
		}
	}

	if (maxInd[0] - minInd[0] + 1 <= k || maxInd[1] - minInd[1] + 1 <= k) {
		cout << "tokitsukaze";
		return 0;
	}

	if (maxInd[0] - minInd[0] - 1 >= k || maxInd[1] - minInd[1] - 1 >= k) {
		cout << "once again";
		return 0;
	}

	if (maxInd[0] < minInd[1] || maxInd[1] < minInd[0]) {
		cout << "once again";
		return 0;
	}

	cout << "quailty";

	return 0;
}