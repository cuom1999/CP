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

const int MAXN = 500005;

int id[MAXN], p[MAXN], leaf[MAXN], sub[MAXN];
ll w[MAXN], dist[MAXN];
vector<int> v[MAXN], eulerTour;
int n, q, C = 0;

    
void preDfs(int a) {
	id[a] = ++C;
	sub[a] = 1;
	eulerTour.pb(a);
	for (auto i: v[a]) {
		if (!id[i]) {
			dist[i] = dist[a] + w[i];
			preDfs(i), sub[a] += sub[i];
		}
	}
}

struct query {
	int l, r, stt;
	query(int __l = 0, int __r = 0, int __stt = 0) {
		l = __l, r = __r, stt = __stt;
	}
};

vector<query> Q[MAXN];
ll st[MAXN * 4], lz[MAXN * 4];

void build (int id, int l, int r) {
	if (l == r) {
		if (leaf[eulerTour[l]]) {
			st[id] = dist[eulerTour[l]];
		} 
		else {
			st[id] = 1e18;
		}
		return;
	}

	int mid = (l + r) / 2;

	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void down(int id, int l, int r) {
	if (!lz[id] || l == r) return;
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	st[id * 2] += lz[id];
	st[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll W) {
	if (v < l || r < u || u > v) return;
	if (u <= l && r <= v) {
		st[id] += W;
		lz[id] += W;
		return;
	}

	down(id, l, r);

	int mid = (l + r) / 2;
	update(id * 2, l, mid, u, v, W);
	update(id * 2 + 1, mid + 1, r, u, v, W);

	st[id] = min(st[id * 2], st[id * 2 + 1]);
} 

ll getMin(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 1e18;
	if (u <= l && r <= v) {
		return st[id];
	}

	down(id, l, r);

	int mid = (l + r) / 2;

	return min(getMin(id * 2, l, mid, u, v), getMin(id * 2 + 1, mid + 1, r, u, v));
}

int vs[MAXN];
ll ans[MAXN];

void dfsSolve(int a) {
	vs[a] = 1;

	//solve for a
	update(1, 1, n, id[a], id[a] + sub[a] - 1, -w[a]);
	update(1, 1, n, 1, id[a] - 1, w[a]);
	update(1, 1, n, id[a] + sub[a], n, w[a]);

	for (auto i: Q[a]) {
		//cout << a << " " << i.l << " " << i.r << endl;
		ans[i.stt] = getMin(1, 1, n, i.l, i.r);
	}

	for (auto i: v[a]) {
		if (!vs[i]) {
			dfsSolve(i);
		}
	}

	update(1, 1, n, id[a], id[a] + sub[a] - 1, w[a]);
	update(1, 1, n, 1, id[a] - 1, -w[a]);
	update(1, 1, n, id[a] + sub[a], n, -w[a]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;
    FOR (i, 2, n) {
    	cin >> p[i] >> w[i];
    	v[i].pb(p[i]);
    	v[p[i]].pb(i);
    }

    FOR (i, 1, n) sort(all(v[i]));

    FOR (i, 2, n) {
    	if (v[i].size() == 1) {
    		leaf[i] = 1;
    	}
    }

    eulerTour.pb(0);
    preDfs(1);

    FOR (i, 1, q) {
    	int l, r, vv;
    	cin >> vv >> l >> r;
    	Q[vv].pb(query(l, r, i));
    }

    build(1, 1, n);

    dfsSolve(1);

    FOR (i, 1, q) cout << ans[i] << endl;





	
    return 0;
}