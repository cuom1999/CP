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

vector<int> v[100005];

int tin[100005], tout[100005];
int par[100005];
int h[100005];
vector<int> EulerTour;
int TIME;

void dfs(int a, int p){
	par[a] = p;
	h[a] = h[p] + 1;
	tin[a] = ++TIME;
	EulerTour.pb(a);
	for (auto i: v[a]){
		if (i != p){
			dfs(i, a);
		}
	}
	tout[a] = ++TIME;
	EulerTour.pb(a);
}

int root;

int st[800005], lz[800005], val[800005];

void updatePar(int id){
	if (st[id * 2] > st[id * 2 + 1]) {
		st[id] = st[id * 2];
		val[id] = val[id * 2];
	}
	else {
		st[id] = st[id * 2 + 1];
		val[id] = val[id * 2 + 1];
	}
}

void build (int id, int l, int r){
	if (l == r) {
		//cout << l << " " << EulerTour[l] << endl;
		st[id] = h[EulerTour[l]];
		val[id] = EulerTour[l];
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	updatePar(id);
}

void down(int id, int l, int r) {
	if (l == r || !lz[id]) {
		return;
	} 
	st[id * 2] += lz[id];
	st[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
}

void update(int id, int l , int r, int u, int v, int k) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		return;
	}
	down(id, l, r);
	int mid = (l + r) / 2;
	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);
	updatePar(id);
}

int get(int id, int l, int r, int u){
	if (l == r) {
		return st[id];
	}
	int mid = (l + r) / 2;
	down (id, l, r);
	if (u <= mid) return get(id * 2, l, mid, u);
	return get(id * 2 + 1, mid + 1, r, u);
}

vector<int> res;
int dd[100005];
int cnt = 0;
int n;

void add(int a){
	vector<int> vertex;
	while (!dd[a]) {
		cnt++;
		dd[a] = 1;
		vertex.pb(a);
		a = par[a];
	}	
	reverse(all(vertex));
	for (auto i: vertex){
		update(1, 1, 2 * n, tin[i], tout[i], -get(1, 1, 2 * n, tin[i]));
		//cout << i << endl;
		//FOR (i, 1, 2 * n) cout << get(1, 1, 2 * n, i) << " "; cout << endl;
	}
		
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }

    dfs(1, 0);
    root = 1;
    FOR (i, 1, n){
    	if (h[i] > h[root]) root = i;
    }
    EulerTour.clear(); EulerTour.pb(0);
    TIME = 0;
    dfs(root, 0);
    
    build (1, 1, 2 * n);

    //for (auto i: EulerTour) if (i) cout << i << " "; cout << endl;

    //FOR (i, 1, 2 * n) cout << get(1, 1, 2 * n, i) << " "; cout << endl;

    dd[0] = 1;
    add(root);
    res.pb(1);
    cnt = 1;

    FOR (k, 2, n){
    	if (st[1] <= 0) break;
    	int u = val[1];
    	add(u);
    	//cout << u << endl;
    	//FOR (i, 1, 2 * n) cout << get(1, 1, 2 * n, i) << " "; cout << endl;

    	res.pb(cnt);
    }
    if (res.size() < n){
    	int y = res.back();
    	while (res.size() < n) res.pb(y);
    }
    for (auto i: res) cout << i << " "; cout << endl;

    return 0;
}