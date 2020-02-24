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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> v;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, I;
	cin >> n >> I;

	FOR (i, 1, n) {
		// cin >> a[i];
		int x;
		cin >> x;
		v.pb(x);
	}

	int k = 8 * I / n;

	if (k > 20) {
		cout << 0 << endl; 
	}
	else {
		int K = 1 << k;

		sort(all(v));
		int cnt = 0;

		vector<int> v1;
		for (int i = 0; i < v.size(); i++) {
			if (!i || v[i - 1] != v[i]) {
				if (i) {
					v1.pb(cnt);
				}
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		v1.pb(cnt);

		vector<int> s;
		int sum = 0;
		s.pb(0);
		for (int i = 0; i < v1.size(); i++) {
			sum += v1[i];
			s.pb(sum);
		}

		// for (auto i: s) cout << i << " "; cout << endl;
		if (K >= v1.size()) {
			cout << 0;
		}
		else {
			int res = 0;
			for (int i = 0; i + K < s.size(); i++) {
				// cout << s[i + K] - s[i] << endl;
				res = max(res, s[i + K] - s[i]);
			}
			cout << n - res << endl;
		}
	}

	return 0;
}