#include <bits/stdc++.h>

#define pb push_back
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define ll long long int
#define all(x) x.begin(),x.end()

using namespace std;

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

struct QueenMeetup {
	int n;
	int x[20], y[20];
	vector<int> res;

	bool move1(int i, int u, int v) { // x,y -> x,v -> u, v
		FOR (j, 0, n - 1) {
			if (j == i) continue;
			if (y[i] <= y[j] && y[j] <= v && x[i] == x[j]) return 0;
		}
		FOR (j, 0, n - 1) {
			if (j == i) continue;
			if (x[i] <= x[j] && x[j] <= u && v == y[j]) return 0;
		}
		if (minmax(x[i], y[i]) != minmax(x[i], v)) {
			res.pb(i);
			res.pb(x[i]);
			res.pb(v);
		}
		if (minmax(x[i], v) != minmax(u, v)) {
			res.pb(i);
			res.pb(u);
			res.pb(v);
		}
		return 1;
	}

	bool move2(int i, int u, int v) { // x,y -> u,y -> u, v
		FOR (j, 0, n - 1) {
			if (j == i) continue;
			if (x[i] <= x[j] && x[j] <= u && y[i] == y[j]) return 0;
		}
		FOR (j, 0, n - 1) {
			if (j == i) continue;
			if (y[i] <= y[j] && y[j] <= v && u == x[j]) return 0;
		}
		if (minmax(x[i], y[i]) != minmax(u, y[i])) {
			res.pb(i);
			res.pb(u);
			res.pb(y[i]);
		}
		if (minmax(u, y[i]) != minmax(u, v)) {
			res.pb(i);
			res.pb(u);
			res.pb(v);
		}
		return 1;
	}

	vector<int> move(int d, vector <int> r, vector <int> c) {
		n = r.size();

		FOR (i, 0, n - 1) {
			x[i] = r[i];
			y[i] = c[i];
		}

		int curX = 0, curY = 0;
		vector<II> newC;
		FOR (i, 1, n) {
			newC.pb({curX, curY});
			curY++;
			if (curY == d) {
				curX++;
				curY = 0;
			}
		}
		bool vs[25];
		FOR (i, 0, n - 1) vs[i] = 0;

		FOR (i, 0, n - 1) {
			bool isDone = 0;
			FOR (j, 0, n - 1) {
				if (vs[j]) continue;
				isDone = move1(j, newC[i].first, newC[i].second);
				if (isDone) {
					vs[j] = 1;
					break;
				}
				isDone = move2(j, newC[i].first, newC[i].second);
				if (isDone) {
					vs[j] = 1;
					break;
				}
			}
		}
		return res;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	vector<int> v = a.move(5,
{0, 1, 3},
{0, 1, 3});

	for (auto i: v) cout << i << " ";
	return 0;
}