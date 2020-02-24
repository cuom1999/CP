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

char vowel[5] = {'a', 'i', 'u', 'e', 'o'};
string s[5];

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int m = -1, k = -1;
	FOR (i, 5, n) {
		if (n % i == 0) {
			if (n / i < 5) {
				cout << -1 << endl;
				return 0;
			}
			else {
				m = i, k = n / i;
				break;
			}
		}
	}

	if (m == -1) {
		cout << -1;
		return 0;
	}

	FOR (i, 0, m - 1) {
		FOR (j, 0, 4) {
			s[j] += vowel[(i + j) % 5];
		}
	}

	string res;
	FOR (i, 0, k - 1) {
		// res += s[i % 5];
		cout << s[i % 5];
	}

	// cout << res << endl;

	// FOR (i, 0, m - 1) {
	// 	FOR (j, 0, k - 1) {
	// 		cout << res[i * k + j];
	// 	}
	// 	cout << endl;
	// }
	return 0;
}