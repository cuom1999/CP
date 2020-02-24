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

int NUM_DAY = 100;
int NUM_VASE = 20;
// int d[24];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	int t;
	cin >> t;

	FOR (z, 1, t) {
		FOR (i, 1, NUM_DAY - 1) {
			int x;
			cin >> x;
			if (x == -1) return 0;
			// cout << 1 << " 0" << endl;
			// int n;
			// cin >> n;
			// FOR (j, 1, n) cin >> x;
			cout << i % 19 + 2 << " " << 100 << endl;
			// d[i % 19 + 2]++;
			// d[rand() % 20 + 1]++;
		}
		int x;
		cin >> x;
		cout << 1 << " " << NUM_DAY << endl;
		// d[1]++;
		// FOR (i, 1, 20) cout << d[i] << " "; cout << endl;
	}

	return 0;
}