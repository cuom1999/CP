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

vector<int> v[10];
int mi[10], ma[10];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		FOR (i, 0, 9) {
			v[i].clear();
			mi[i] = INF;
			ma[i] = -1;
		}

		FOR (i, 0, n - 1) {
			v[s[i] - '0'].pb(i);
			mi[s[i] - '0'] = min(mi[s[i] - '0'], i);
			ma[s[i] - '0'] = i;
		}

		int index = -1;
		int curMax = -1;
		FOR (i, 0, 9) {
			if (curMax > mi[i]) {
				index = i;
				break;
			}
			curMax = max(curMax, ma[i]);
		}

		if (index == -1) {
			FOR (i, 0, n - 1) cout << 1;
			cout << "\n";
		}
		else {
			string res;
			res.resize(n);
			FOR (i, 0, n - 1) res[i] = '2';
			int maxPos = -1;
			FOR (i, 0, index - 1) {
				for (auto j: v[i]) {
					res[j] = '1';
					maxPos = max(maxPos, j);
				}
			}
			FOR (j, maxPos + 1, n - 1) {
				if (s[j] == index + '0') {
					res[j] = '1';
				}
			}
			vector<int> q;
			FOR (i, 0, n - 1) {
				if (res[i] == '1') q.pb(s[i]);
			}
			FOR (i, 0, n - 1) {
				if (res[i] == '2') q.pb(s[i]);
			}
			bool isGood = 1;
			FOR (i, 0, n - 2) {
				if (q[i] > q[i + 1]) {
					isGood = 0;
					break;
				}
			}
			if (isGood) {
				cout << res << "\n";
			}
			else {
				cout << "-\n";
			}
		}
	}


	return 0;
}