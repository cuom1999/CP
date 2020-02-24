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



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	cin >> s;
	s = 'o' + s + '*';

	vector<int> v;

	int cnt = 0;
	for(int i = 0; i < s.length(); i++) {
		if (!i || s[i] != s[i - 1]) {
			if (i) {
				if (v.size() % 2 == 0) v.pb(cnt);
				else v.pb(cnt - 1);
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	ll res = 0;
	ll sum = 0; 
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 1) {
			sum += v[i];
		}
	}

	// for (auto i: v) cout << i << " "; cout << endl;

	// cout << sum << endl;	
	ll cur = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) {
			res += cur * (sum - cur) * 1ll * v[i]; 
		}
		else {
			cur += v[i];
		}
	}

	cout << res << endl;

	return 0;
}