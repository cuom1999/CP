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

string s;
vector<string> v;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	int n;
	cin >> n;

	cin >> s;

	while (1) {
		int cur = 0;
		v.clear();
		while (cur < s.size()) {
			if (cur == n - 1) {
				v.pb(s.substr(cur, 1));
				cur++;
			}
			else {
				int m = rand() % 2 + 1;
				v.pb(s.substr(cur, m));
				cur += m;
			}
		}		
		int res = 0;
		for (auto i: v) {
			res += stoi(i);
		}

		vector<string> v1;
		string tmp = to_string(res);

		res = 0;
		for (int i = 0; i < tmp.size(); i++) {
			v1.pb(tmp.substr(i, 1));
			res += stoi(tmp.substr(i, 1));
		}

		vector<string> v2;
		tmp = to_string(res);

		res = 0;
		for (int i = 0; i < tmp.size(); i++) {
			v2.pb(tmp.substr(i, 1));
			res += stoi(tmp.substr(i, 1));
		}		
		if (res <= 9) {
			for (int i = 0; i < v.size(); i++) {
				if (i + 1 == v.size()) {
					cout << v[i] << endl;
				}
				else {
					cout << v[i] << "+";
				}
			}

			for (int i = 0; i < v1.size(); i++) {
				if (i + 1 == v1.size()) {
					cout << v1[i] << endl;
				}
				else {
					cout << v1[i] << "+";
				}
			}

			for (int i = 0; i < v2.size(); i++) {
				if (i + 1 == v2.size()) {
					cout << v2[i] << endl;
				}
				else {
					cout << v2[i] << "+";
				}
			}
			return 0;
		}
	}
	return 0;
}