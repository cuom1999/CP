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

char c[2005][2005], d[2005][2005];
II tail[305], head[305];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		int n, m;
		cin >> n >> m;

		int k = 0;
		FOR (i, 1, n) {
			FOR (j, 1, m) {
				cin >> c[i][j];
				d[i][j] = '.';
				k = max(k, c[i][j] - 'a' + 1);
			}
		}
		FOR (cc, 'a', 'z') {
			head[cc] = tail[cc] = II(0, 0);
		}

		FOR (i, 1, n) {
			FOR (j, 1, m) {
				if (head[c[i][j]] == II(0, 0) || head[c[i][j]] > II(i, j)) {
					head[c[i][j]] = II(i, j);
				}
				if (tail[c[i][j]] == II(0, 0) || tail[c[i][j]] < II(i, j)) {
					tail[c[i][j]] = II(i, j);
				}
			}
		}
		
		bool isTrue = 1;

		FORD(cc, 'a' + k - 1, 'a') {
			if (head[cc] == II(0, 0)) {
				head[cc] = head[cc + 1];
				tail[cc] = head[cc];
			}
		}

		FOR (cc, 'a', 'a' + k - 1) {
			if (head[cc].first != tail[cc].first && head[cc].second != tail[cc].second) {
				isTrue = 0;
				break;
			}
			if (head[cc].first == tail[cc].first) {
				FOR (i, head[cc].second, tail[cc].second) {
					d[head[cc].first][i] = cc;
				}
			}
			else {
				FOR (i, head[cc].first, tail[cc].first) {
					d[i][head[cc].second] = cc;
				}
			}
		}

		if (!isTrue) {
			cout << "NO\n";
		}
		else {
			FOR (i, 1, n) {
				FOR (j, 1, m) {
					if (c[i][j] != d[i][j]) {
						isTrue = 0;
						break;
					}
				}
			}
			if (!isTrue) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
				cout << k << "\n";
				FOR (cc, 'a', 'a' + k - 1) {
					cout << head[cc].first << " " << head[cc].second << " " << tail[cc].first << " " << tail[cc].second << "\n";
				}	
			}
		}
	}


	return 0;
}