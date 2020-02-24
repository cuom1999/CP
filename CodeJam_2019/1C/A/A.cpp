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

vector<string> v;

int MAXN = 500;

void process(string &s) {
	string u;
	FOR (i, 0, MAXN - 1) {
		u += s[i % s.length()];
	}
	s = u;
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	int t;
	cin >> t;
	FOR (z, 1, t) {
		v.clear();

		cout << "Case #" << z << ": ";
		int n;
		cin >> n;

		FOR (i, 1, n) {
			string s;
			cin >> s;
			process(s);
			v.pb(s);
		}

		string res;
		FOR (i, 0, MAXN) {
			vector<string> P, R, S;

			if (!v.size()) {
				cout << res << endl;
				break;
			}

			for (auto s: v) {
				if (s[i] == 'P') P.pb(s);
				else if (s[i] == 'R') R.pb(s);
				else S.pb(s);
			} 
			if (P.size() && S.size() && R.size()) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
			else {
				if (P.size() && S.size()) {
					res += 'S';
					v = S;
				}
				else if (P.size() && R.size()) {
					res += 'P';
					v = P;
				}
				else if (R.size() && S.size()) {
					res += 'R';
					v = R;
				}
				else if (P.size()) {
					res += 'S';
					v.clear();
				}
				else if (R.size()) {
					res += 'P';
					v.clear();
				}
				else {
					res += 'R';
					v.clear();
				}
			}
		} 
	}



	return 0;
}