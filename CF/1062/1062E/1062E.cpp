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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int p[100005][21], h[100005];
vector<int> v[100005];
int tin[100005], tout[100005];
int TIME; 
int n;

void dfs(int a, int par){
	h[a] = h[par] + 1;
	tin[a] = ++TIME;
	for (auto i: v[a]){
		dfs(i, a);
	}
	tout[a] = ++TIME;
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
    if (h[v]<h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,17,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

vector<int> st[100005 * 4];

bool cmp(int a, int b){
	return tin[a] < tin[b];
}
vector<int> V;

void build (int id, int l, int r){
	if (l == r){
		st[id].pb(l);
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	merge(all(st[id * 2]), all(st[id * 2 + 1]), back_inserter(st[id]), cmp);
}

int min(int a, int b){
	if (tin[a] < tin[b]) return a;
	return b; 
}

int max(int a, int b){
	if (tin[a] < tin[b]) return b;
	return a;
}

II get(int id, int l, int r, int u, int v){
	if (v < l || r < u) return II(n + 1, 0);
	if (u <= l && r <= v) {
		return II(st[id][0], st[id].back()); 
	}
	int mid = (l + r) / 2;
	II a = get(id * 2, l, mid, u, v);
	II b = get(id * 2 + 1, mid + 1, r, u, v);
	return II(min(a.first, b.first), max(a.second, b.second));
}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    FOR (i, 2, n){
    	cin >> p[i][0];
    	v[p[i][0]].pb(i);
    }
    dfs(1, 0);
    build(1, 1, n);
    tin[n + 1] = 1e9;
    init();

    FOR (z, 1, q){
    	int l, r;
    	cin >> l >> r;
    	II u = get(1, 1, n, l, r);
    	int a = u.first;
    	int b = u.second;
    	II u1 = get(1, 1, n, l, a - 1);
    	II u2 = get(1, 1, n, a + 1, r);
    	int p1 = min(u1.first, u2.first);
    	int p2 = max(u1.second, u2.second);
    	int res = LCA(p1, p2);
    	res = h[res];

		u1 = get(1, 1, n, l, b - 1);
    	u2 = get(1, 1, n, b + 1, r);
    	p1 = min(u1.first, u2.first);
    	p2 = max(u1.second, u2.second);
    	int res1 = LCA(p1, p2);
    	res1 = h[res1];
    	if (res > res1)	cout << a << " " << res - 1 << endl;
    	else cout << b << " " << res1 - 1 << endl;
    }
	
         return 0;
}