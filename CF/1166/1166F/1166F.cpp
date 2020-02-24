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

const int MAXN = 100006;
int lab[MAXN];

map<int, vector<int> > v[MAXN];
set<int> s[MAXN];
vector<int> cc[MAXN], allV[MAXN];

int getRoot(int a) {
	while (lab[a] >= 0) a = lab[a];
	return a;
}

void dsu(int a, int b) {
	int x = lab[a] + lab[b];
	if (lab[a] < lab[b]) {
		lab[a] = x;
		lab[b] = a;

		for (auto i: cc[b]) {
			for (auto j: allV[i]) {
				s[j].erase(b);
				s[j].insert(a);
			}
		}
		for (auto i: cc[b]) cc[a].pb(i);
		cc[b].clear();
	}
	else {

		lab[b] = x;
		lab[a] = b;

		for (auto i: cc[a]) {
			for (auto j: allV[i]) {
				s[j].erase(a);
				s[j].insert(b);
			}
		}
		for (auto i: cc[a]) cc[b].pb(i);
		cc[a].clear();
	}
}

void addEdge2(int x, int y) {
	int m = getRoot(x);
	int n = getRoot(y);
	if (m == n) {
		return;
	}

	dsu(m, n); 
}

void addEdge(int x, int y, int c) {
	if (v[y][c].size()) {
		addEdge2(x, v[y][c][0]);
	}
	if (v[x][c].size()) {
		addEdge2(y, v[x][c][0]);
	}
	v[x][c].pb(y);
	v[y][c].pb(x);
	allV[x].pb(y);
	allV[y].pb(x);
	s[x].insert(getRoot(y));
	s[y].insert(getRoot(x));
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, c, q;
	cin >> n >> m >> c >> q;

	FOR (i, 1, n) {
		lab[i] = -1;
		cc[i].pb(i);
	}

	FOR (i, 1, m) {
		int x, y, c;
		cin >> x >> y >> c;
		addEdge(x, y, c);
	}

	FOR (i, 1, q) {
		char c;
		cin >> c;
		if (c == '+') {
			int x, y, c;
			cin >> x >> y >> c;
			addEdge(x, y ,c);
		}
		else {
			int x, y;
			cin >> x >> y;
			int u = getRoot(x);
			// cout << u << endl;
			// for (auto i: s[y]) cout << i << " "; cout << endl;
			if (s[y].find(u) != s[y].end() || u == getRoot(y)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	// FOR (i, 1, n) cout << lab[i] << " ";


	return 0;
}