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

const int MAXN = 100005;

vector<int> in[MAXN], out[MAXN];
int lastVer[MAXN], nextVer[MAXN], adjLast[MAXN], adjNext[MAXN];
int vs[MAXN];

int getLast(int u) {
	if (!vs[u]) return u;
	return lastVer[u] = getLast(lastVer[u]);
}

int getNext(int u) {
	if (!vs[u]) return u;
	return nextVer[u] = getNext(nextVer[u]);
}

int n, m;

void print() {
	FOR (i, 1, n) {
		cout << i << ": ";
		for (auto j: in[i]) cout << getLast(j) << " "; cout << "- ";
		for (auto j: out[i]) cout << getNext(j) << " "; cout << endl; 
	}	
	cout << endl;
}

vector<int> strongVer;

void simplify(vector<int> &v, int u) {
	sort(all(v));
	vector<int> tmp;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0 || v[i] == u) continue;
		if (!i || v[i] != v[i - 1]) {
			tmp.pb(v[i]);
		}
	}
	v = tmp;
}

bool findGoodPath(int u, bool dd[MAXN], int sz, vector<int> &res) {
	if (sz == strongVer.size()) {
		for (auto i: out[u]) {
			if (i == strongVer[0]) {
				res.pb(strongVer[0]);
				return 1;
			}
		}
	}
	for (auto i: out[u]) {
		if (dd[i]) continue;
		dd[i] = 1;
		res.pb(i);
		if (findGoodPath(i, dd, sz + 1, res)) {
			return 1;			
		}
		dd[i] = 0;
		res.pop_back();
	}
	return 0;
}

void noAnswer() {
	cout << "There is no route, Karl!" << endl;
	exit(0);		
}

bool dd[MAXN];

vector<int> resIn[MAXN], resOut[MAXN];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		if (x == y) continue;
		in[y].pb(x);
		out[x].pb(y);
	}

	FOR (i, 1, n) {

		// print();
		
		if (!in[i].size() || !out[i].size()) {
			cout << "There is no route, Karl!" << endl;
			return 0;
		}

	}
	FOR (i, 1, n) strongVer.pb(i);
	vector<int> res;

	// print();
	if (strongVer.size() == 1) {
		res.pb(strongVer[0]);
		res.pb(strongVer[0]);
	}
	else {
		res.pb(strongVer[0]);
		dd[strongVer[0]] = 1;
		if (!findGoodPath(strongVer[0], dd, 1, res)) {
			noAnswer();
		}
	}
	for (auto i: res) cout << i << " "; cout << endl;
	
	return 0;
}