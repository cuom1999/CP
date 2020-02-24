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


const int MAXS = 1000001;
bitset<MAXS> curDP, oldDP;
int a[5005], firstApp[MAXS];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(NULL));
	int n, S;

	// cin >> n >> S;
	n = 5000;
	S = MAXS - 1;
	cout << n << " " << S << endl;

	FOR (i, 1, n) {
		// cin >> a[i];
		if (i < 4000) a[i] = 1;
		else a[i] = rand() * rand() % MAXS;
	}


	curDP[0] = 1;

	FOR (i, 1, n) {
		oldDP = curDP;
		curDP = curDP | (curDP << a[i]);

		bitset<MAXS> tmp = curDP & (oldDP.flip());
		for(int j = tmp._Find_first(); j < tmp.size(); j = tmp._Find_next(j)) {
			firstApp[j] = i;
		}
	}

	if (!firstApp[S]) {
		cout << -1 << endl;
		return 0;
	}
	else {
		vector<int> res;
		while (S) {
			res.pb(firstApp[S]);
			S -= a[firstApp[S]];
		}
		reverse(all(res));
		cout << res.size() << endl;
		int sum = 0;
		for (auto i: res) {
			cout << i << " ";
			sum += a[i];
		}
		cout << endl;
		cout << sum << endl;
	}
	return 0;
}