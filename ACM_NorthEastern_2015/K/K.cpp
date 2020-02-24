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

const int MAXN = 100005;

vector<int> in[MAXN], out[MAXN];
vector<II> edges;
int adjLast[MAXN], adjNext[MAXN];
bool vs[MAXN], dd[MAXN];



struct Edge {
	int to;
	vector<int> order;

	friend ostream & operator << (ostream &os, const Edge &e) {
		os << e.to << ": ";
		os << "(";

		for (auto i: e.order) {
			if (i != e.order.back()) os << i << "-";
			else os << i;
		}
		os << ")";
		return os;
	}
};

Edge edge[67];
vector< pair <Edge, int> > strongOut[45];
int strongInd[MAXN];

int n, m;

vector<int> strongVer;


void noAnswer() {
	cout << "There is no route, Karl!" << endl;
	exit(0);		
}

bool findGoodPath(int u, bool dd[MAXN], int numVer, vector<int> &res) {
	for (auto i: strongOut[strongInd[u]]) {
		if (i.first.to == strongVer[0]) {
			if (numVer + i.first.order.size() == n) {
				res.pb(i.second);
				return 1;
			}
		}
		if (dd[i.first.to]) continue;
		dd[i.first.to] = 1;
		
		res.pb(i.second);

		if (findGoodPath(i.first.to, dd, numVer + i.first.order.size() + 1, res)) {
			return 1;			
		}

		dd[i.first.to] = 0;
		res.pop_back();
	}
	return 0;
}


int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	bool isFirst = 0;
	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		if (x == y) continue;
		in[y].pb(x);
		out[x].pb(y);
		edges.pb({x, y});
		if (!isFirst) {
			in[y].pb(x);
			out[x].pb(y);
		}
		isFirst = 1;
	}

	FOR (i, 1, n) {

		if (!in[i].size() || !out[i].size()) {
			cout << "There is no route, Karl!" << endl;
			return 0;
		}

		if (in[i].size() == 1 && out[i].size() == 1) {
			int u = in[i][0];
			
			adjLast[i] = u;
			adjNext[i] = out[i][0];
			vs[i] = 1;
		}
			
	}

	FOR (i, 1, n) {
		if (!vs[i]) strongVer.pb(i);
	}

	for (int i = 0; i < strongVer.size(); i++) {
		strongInd[strongVer[i]] = i + 1;
	}

	int C = 0;

	FOR (i, 1, n) {
		vector<int> curEdge;
		int u = i;

		if (vs[i] && !dd[i]) {
			vector<int> tmp;
			while (vs[u]) {
				if (dd[u]) {
					noAnswer();
				}
				dd[u] = 1;
				tmp.pb(u);
				u = adjNext[u];
			}
			int to = u;

			u = i;
			vector<int> tmp2;
			while (vs[u]) {
				if (dd[u] && u != i) noAnswer();
				dd[u] = 1;
				tmp2.pb(u);
				u = adjLast[u];
			}
			int from = u;

			reverse(all(tmp2));
			tmp2.pop_back();

			for (auto j: tmp) tmp2.pb(j);
			curEdge = tmp2;

			strongOut[strongInd[from]].pb({{to, curEdge}, ++C});
			edge[C] = {to, curEdge};
		}
	}

	vector<int> empty;
	for (auto e: edges) {
		if (!vs[e.first] && !vs[e.second]) {
			strongOut[strongInd[e.first]].pb({{e.second, empty}, ++C});
			edge[C] = {e.second, empty};
		}
	}

	memset(dd, 0, sizeof(dd));
	dd[strongVer[0]] = 1;
	vector<int> res;

	if (!findGoodPath(strongVer[0], dd, 1, res)) {
		noAnswer();
	}

	vector<int> cycle;
	cycle.pb(strongVer[0]);
	for (auto i: res) {
		for (auto j: edge[i].order) {
			cycle.pb(j);
		}
		cycle.pb(edge[i].to);
	}

	cycle.pop_back();

	int pos1 = -1;
	for (int i = 0; i < cycle.size(); i++) {
		if (cycle[i] == 1) pos1 = i;
	}

	vector<int> ans;
	FOR (i, pos1, cycle.size() - 1) ans.pb(cycle[i]);
	FOR (i, 0, pos1 - 1) ans.pb(cycle[i]);
	ans.pb(1);

	if (pos1 == -1) noAnswer();

	if (ans.size() < n + 1) noAnswer();
	else {
		for (auto i: ans) cout << i << " ";
	}
	return 0;
}