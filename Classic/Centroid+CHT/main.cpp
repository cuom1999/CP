// https://open.kattis.com/problems/yatp
// using centroid decomposition + convex hull trick

// every path from u goes through its parents in CD, so we only
// need to build CHT for each subtree in CD 

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
typedef pair < int, ll > II;


const int N = 200005;

int subCD[N], cenDad[N], cenRoot;
vector<int> cenChild[N];
vector<II> v[N];
set<int> s[N];

int dfsCD(int a, int p){
	subCD[a]=1;
	for (int i:s[a]){
		if (i!=p){
			dfsCD(i,a);
			subCD[a]+=subCD[i];
		}
	}
	return subCD[a];
}

int centroid(int a, int p, int n){
	for (auto i:s[a]){
		if (i!=p && subCD[i]>n/2){
			return centroid(i,a,n);
		}
	}
	return a;
}

//call centroidDecomposition(1,0)
void centroidDecomposition(int a, int p){
	int n = dfsCD(a,p);
	int cen = centroid(a,p,n);
	cenDad[cen] = p;
	if (p) cenChild[p].pb(cen);
	else cenRoot = cen;

	for (int i: s[cen]){
		s[i].erase(cen);
		centroidDecomposition(i,cen);
	}
}

int h[N], p[N][22];
ll len[N];

void dfs(int a, int par) {
	h[a] = h[par] + 1;
	p[a][0] = par;
	for (auto i: v[a]) {
		if (i.first == par) continue;
		len[i.first] = len[a] + i.second;
		dfs(i.first, a);
	}
}

void init(int n){
    FOR (i, 1, 19){
        FOR (j, 1, n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,19,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,19,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,19,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

ll dist(int u, int v) {
	int l = LCA(u, v);
	return len[u] + len[v] - 2 * len[l];
}


struct Point {
	ll x, y;
};

struct CHT {
	vector<Point> v;

	ld cross (Point a, Point b) {return (ld)(b.y - a.y) / (b.x - a.x);}

	void addLine(ll x, ll y) {
		if (v.size() && v.back().x == x && v.back().y == y) return;

		while(v.size() >= 2 && cross(v[v.size()-2], v.back()) > cross(v.back(), (Point){x, y})){
			v.pop_back();	
		}
		v.push_back({x, y});
	}

	ll query(ll x) {
		int s = 0, e = v.size()-1;
		auto f = [&](int p) {
			return v[p].x * x + v[p].y;
		};

		while(s != e){
			int m = (s + e) / 2;
			if(f(m) <= f(m+1)) e = m;
			else s = m + 1;
		}
		return v[s].x * x + v[s].y;
	}
}cht[N];


ll cost[N];
vector<Point> pts[N];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> cost[i];
	}

	FOR (i, 1, n) {
		int x, y; 
		ll c;
		cin >> x >> y >> c;

		v[x].pb({y, c});
		v[y].pb({x, c});
	}

	FOR (i, 1, n) {
		for (auto j: v[i]) s[i].insert(j.first);
	}

	centroidDecomposition(1, 0);
	dfs(1, 0);
	init(n);
	
	FOR (i, 1, n) {
		int tmp = i;
		while (tmp) {
			pts[tmp].pb({cost[i], dist(i, tmp)});
			tmp = cenDad[tmp];
		}
	}

	FOR (i, 1, n) {
		sort(all(pts[i]), [](Point &a, Point &b) {
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		});
		for (auto j: pts[i]) {
			cht[i].addLine(j.x, j.y);
		}
	}


	ll ans = 0;
	FOR (i, 1, n) {
		int tmp = i;
		ll res = 1e18;
		while (tmp) {
			res = min(res, cht[tmp].query(cost[i]) + dist(i, tmp));
			tmp = cenDad[tmp];
		}
		// cout << res << " ";
		ans += res;
	}
	cout << ans << endl;

	return 0;
}