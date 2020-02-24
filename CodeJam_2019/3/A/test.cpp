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

ll m = 100;

ll d[100005]; 

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	FOR (i, 1, 10000) {
		set<ll> s;
		FOR (a, 0, i - m) {
			s.insert(d[a] ^ d[i - m - a]);
		}

		FOR (j, 0, 100) {
			if (s.find(j) == s.end()) {
				d[i] = j;
				break;
			}
		}

		cout << i << " " << d[i] << endl;
	}

	return 0;
}