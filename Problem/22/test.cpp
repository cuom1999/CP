#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

ll dp[1005][1005];
vector<char> parenStack;

ll a, b, c, d, e, f;
string s;

ll dist[1005][1005];
int MAXN = 1001;

struct data {
	int x, y;
	ll val;
	data (int __x = 0, int __y = 0, ll __val = 1e18) {
		x = __x;
		y = __y;
		val = __val;
	}
};

struct cmp {
	bool operator() (data a, data b) {
		return a.val > b.val;
	}
};

priority_queue <data, vector<data>, cmp> pq;

void dijsktra() { //from (0, 0)
	FOR (i, 0, MAXN) {
		FOR (j, 0, MAXN) {
			dist[i][j] = 1e18;
		}
	}
	dist[0][0] = 0;
	pq.push(data(0, 0, 0));

	while (pq.size()) {
		auto u = pq.top();
		int x = u.x;
		int y = u.y;
		ll val = u.val;
		pq.pop();
		if (dist[x][y] != val) continue;

		//cout << x << " " << y << " " << val << endl;
		if (y + 2 <= MAXN) {
			if (dist[x][y + 2] > val + a) {
				dist[x][y + 2] = val + a; 
				pq.push(data(x, y + 2, val + a));
			}
		}

		if (x + 2 <= MAXN) {
			if (dist[x + 2][y] > val + b) {
				dist[x + 2][y] = val + b;
				pq.push(data(x + 2, y, val + b));
			}
		}

		if (y + 1 <= MAXN) {
			if (dist[x][y + 1] > val + min(c, e)) {
				dist[x][y + 1] = val + min(c, e);
				pq.push(data(x, y + 1, val + min(c, e)));
			}
		}

		if (x + 1 <= MAXN) {
			if (dist[x + 1][y] > val + min(c, d)) {
				dist[x + 1][y] = val + min(c, d);
				pq.push(data(x + 1, y, val + min(c, d)));
			}
		}

		if (x + 1 <= MAXN && y + 1 <= MAXN) {
			if (dist[x + 1][y + 1] > val + f) {
				dist[x + 1][y + 1] = val + f;
				pq.push(data(x + 1, y + 1, val + f));
			}
		}

		if (x + 1 <= MAXN && y - 1 >= 0) {
			if (dist[x + 1][y - 1] > val + b) {
				dist[x + 1][y - 1] = val + b;
				pq.push(data(x + 1, y - 1, val + b));
			}
		}

		if (y + 1 <= MAXN && x - 1 >= 0) {
			if (dist[x - 1][y + 1] > val + a) {
				dist[x - 1][y + 1] = val + a;
				pq.push(data(x - 1, y + 1, val + a));
			}
		}
	}
}

int main()
{IN;//OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	FOR (z, 1, t) {
		parenStack.clear();
		cin >> s;
		cin >> a >> b >> c >> d >> e >> f;

	    //remove unnecessary parentheses

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				parenStack.pb(s[i]);
			} 
			else {
				if (!parenStack.size() || parenStack.back() == ')') {
					parenStack.pb(s[i]);
				}
				else {
					parenStack.pop_back();
				}
			}
		}


		ll numOpen = 0, numClose = 0;
		
		for (int i = 0; i < parenStack.size(); i++) {
			if (parenStack[i] == ')') numClose++;
			else numOpen++;
		}

		MAXN = max(numOpen, numClose) + 1;

		dijsktra();

		cout << dist[numClose][numOpen] << endl;
	}
	return 0;
}