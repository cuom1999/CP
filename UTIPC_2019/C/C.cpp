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

vector<int> per;
int res[1005];

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int last = 0;
	per.pb(1);

	FOR (i, 2, n) {
		cout << "? 1 " << i << endl;
		int x;
		cin >> x;

		int val = x - last;
		per.insert(per.end() - val, i);

		last = x;
	}

	cout << "! ";

	for (int i = 0; i < per.size(); i++) {
		res[per[i]] = i + 1;
	}

	FOR (i, 1, n) cout << res[i] << " "; cout << endl;

	return 0;
}