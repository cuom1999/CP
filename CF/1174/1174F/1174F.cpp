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

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int n, x;
vector<int> v[200005];

void genTree() {
	n = Rand(2, 2000);
	x = Rand(1, n);
	cout << n << " " << x << endl;
	FOR (i, 2, n) {
		int u = Rand(1, i - 1);
		// cout << i << " " << u << endl;
		v[i].pb(u);
		v[u].pb(i);
	}
}

int h[200005], p[200005][20];

void dfs(int u, int par) {
	for (auto i: v[u]) {
		if (i != par) {
			p[i][0] = u;
			h[i] = h[u] + 1; 
			dfs(i, u);
		}
	}
}

void init(){
    FOR (i,1,18){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,18,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,18,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,18,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

int distQuery(int u) {
	int l = LCA(u, x);
	return h[u] + h[x] - h[l] * 2;
}

int secondQuery(int u) {
	int l = LCA(u, x);
	if (l != u || u == x) {
		cout << "Bad query!" << endl;
		exit(0); 
	}
	int cur = x;
	while (p[cur][0] != u) cur = p[cur][0];
	return cur;
}

int d[200005];

void bfs(int u) {
	memset(d, -1, sizeof(d));
	queue<int> q;
	d[u] = 0;
	q.push(u);

	while (q.size()) {
		int t = q.front();
		q.pop();
		for (auto i: v[t]) {
			if (d[i] >= 0) continue;
			d[i] = d[t] + 1;
			q.push(i); 
		}
	}
}

int ans[200005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	genTree();
	h[1] = 1;
	dfs(1, 0);
	init();

	int curRoot = 1;

	FOR (i, 1, 36) {
		int u = Rand(1, n);
		int dist = distQuery(u);
		bfs(u);
		FOR (j, 1, n) {
			if (d[j] == dist) {
				ans[j]++;
			}
		}
	}
	vector<int> res;
	FOR (i, 1, n) {
		if (ans[i] == 36) {
			res.pb(i);
		}
	}

	for (auto i: res) cout << i << " "; cout << endl;

	return 0;
}