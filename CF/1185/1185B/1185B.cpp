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

typedef pair < char, int > II;
typedef pair < ll, ll > pll;

string s, t;

void process(string &s, vector<II> &v) {
	int cnt = 0;
	s += '.';

	for (int i = 0; i < s.length(); i++) {
		if (!i || s[i] == s[i - 1]) {
			cnt++;
		}
		else {
			v.pb({s[i - 1], cnt});
			cnt = 1;
		}
	}
	s.pop_back();
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int test;
	cin >> test;

	FOR (z, 1, test) {
		cin >> s >> t;

		vector<II> s1, t1;

		process(s, s1);
		process(t, t1);

		if (s1.size() != t1.size()) {
			cout << "NO\n";
			continue;
		}

		bool isTrue = 1;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i].first != t1[i].first) {
				isTrue = 0;
				break;
			}
			if (s1[i].second > t1[i].second) {
				isTrue = 0;
				break;
			}
		}

		if (isTrue) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}