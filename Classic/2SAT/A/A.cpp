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

#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
struct TwoSat {
	static const int MAXV = 2e5 + 5; // = 2 * V
	int n;
	vector<int> forward[MAXV], backward[MAXV];
	bool used[MAXV];
	int cnt, order[MAXV], comp[MAXV];

	TwoSat(int _n) {
		n = _n;
		for (int i = 0; i < n; i++) {
			forward[i].clear();
			backward[i].clear();
		}
	}

	void add(int u, int v) {
		// cout << u / 2 << " " << v / 2 << endl;
		cout << u << " " << v << endl;
		forward[u].push_back(v);
		backward[v].push_back(u);
	}
	void dfs1(int u) {
		used[u] = true;
		for (int i = 0; i < forward[u].size(); i++) {
			int v = forward[u][i];
			if (!used[v]) dfs1(v);
		}
		order[cnt++] = u;
	}
	void dfs2(int u, int c) {
		comp[u] = c;
		for (int i = 0; i < backward[u].size(); i++) {
			int v = backward[u][i];
			if (comp[v] == -1) dfs2(v, c);
		}
	}

	// res: list of true variable
	int solve(vector<int>& res) {
		cnt = 0;
		memset(used, 0, sizeof(used));
		for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
			memset(comp, -1, sizeof(comp));
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			int u = order[i];
			if (comp[u] == -1) dfs2(u, c++);
		}
		for (int u = 0; u < n; u += 2)
			if (comp[u] == comp[u ^ 1]) return 0;
		res.clear();
		for (int u = 0; u < n; u += 2) {
			int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
			if (!(choose & 1)) res.push_back(choose >> 1);
		}
		return 1;
	}
};


struct Point {
	int x, y;
};

bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
} 

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
	int val = (q.y - p.y) * (r.x - q.x) - 
	(q.x - p.x) * (r.y - q.y); 

    if (val == 0) return 0;  // colinear 

    return (val > 0)? 1: 2; // clock or counterclock wise 
} 


// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

    // General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

    return false; // Doesn't fall in any of the above cases 
} 

struct Seg {
	Point a, b;
};

Seg diagonal[2005];

bool isIntersect(Seg& a, Seg& b) {
	return doIntersect(a.a, a.b, b.a, b.b);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	TwoSat ts(4);
	ts.add(pos(0), pos(1));
	ts.add(neg(0), neg(1));
	vector<int> res;
	cout << ts.solve(res) << endl;
	for (auto i: res) cout << i << " ";
	return 0;

	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		TwoSat ts(4 * n);

		FOR (i, 1, n) {
			int minY, maxY;
			int minX = minY = INF + 1;
			int maxX = maxY = -INF - 1;
			FOR (j, 1, 8) {
				int u;
				cin >> u;
				if (j % 2 == 1) {
					minX = min(minX, u);
					maxX = max(maxX, u);
				}
				else {
					minY = min(minY, u);
					maxY = max(maxY, u);
				}
			}
			diagonal[(i - 1) * 2] = {{minX, minY}, {maxX, maxY}};
			diagonal[(i - 1) * 2 + 1] = {{minX, maxY}, {maxX, minY}};
			ts.add(pos((i - 1) * 2), pos((i - 1) * 2 + 1));
		}

		FOR (i, 0, 2 * n - 1) {
			FOR (j, i + 1, 2 * n - 1) {
				if (isIntersect(diagonal[i], diagonal[j])) {
					ts.add(neg(i), neg(j));
				}
			}
		}

		vector<int> res;
		if (ts.solve(res)) {
			cout << "YES\n";
			for (auto i: res) {
				cout << i << " ";
			}
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}