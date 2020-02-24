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

map<string, int> d; 

int lead[8], follow[8];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	d["swing"] = 0;
	d["bachata"] = 1;
	d["country"] = 2;

	int l, f;
	ll M;

	cin >> l >> f >> M;

	FOR(i, 1, l) {
		int val = 0;
		int x;
		cin >> x;
		FOR (j, 1, x) {
			string s;
			cin >> s;
			val |= (1 << d[s]);
		}
		lead[val]++;
	}

	FOR(i, 1, f) {
		int val = 0;
		int x;
		cin >> x;
		FOR (j, 1, x) {
			string s;
			cin >> s;
			val |= (1 << d[s]);
		}
		follow[val]++;
	}	
	ll res = 0;
	FOR (i, 1, 7) {
		res += min(lead[i], follow[i]) * popcnt(i);
	}

	cout << fixed << setprecision(10) << M * res / 3.0 << endl;

	return 0;
}