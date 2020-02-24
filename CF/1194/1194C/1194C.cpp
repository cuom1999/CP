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

	int t;
	cin >> t;

	FOR (z, 1, t) {
		vector<int> cnt(500);

		string s, p, t;
		cin >> s >> t >> p;

		for (int i = 0; i < s.length(); i++) {
			cnt[s[i]]++;
		}
		for (int i = 0; i < t.length(); i++) {
			cnt[t[i]]--;
		}
		for (int i = 0; i < p.length(); i++) {
			cnt[p[i]]++;
		}

		bool q = 1;
		FOR (i, 'a', 'z') {
			if (cnt[i] < 0) {
				cout << "NO\n";
				q = 0;
				break;
			}
		}
		if (q) {
			int j = 0;
			int i = 0;
			while (i < s.length() && j < t.length()) {
				while (j < t.length() && t[j] != s[i]) {
					j++;
				}
				if (j < t.length() && t[j] == s[i]) {
					i++;
					j++;
				}
			}
			if (i == s.length()) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}


	return 0;
}