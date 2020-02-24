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

string s;
int g[300005], h[300005];
multiset<int> st[300005 * 8];
int val[300005 * 8];

inline int min(int x, int y) {
	if (x < y) return x;
	return y;
}

void update (int id, int l, int r, int u, int v) {
	if (l == r) {
		st[id].insert(v);
		val[id] = *(st[id].begin());
		return;
	}
	int mid = (l + r) / 2;
	if (u <= mid) update(id * 2, l, mid, u, v);
	else update(id * 2 + 1, mid + 1, r, u, v);
	val[id] = min(val[id * 2], val[id * 2 + 1]);
} 

void del (int id, int l, int r, int u, int v) {
	if (l == r) {
		st[id].erase(st[id].find(v));
		if (st[id].size() == 0) val[id] = INF;
		else val[id] = *(st[id].begin());
		return;
	}
	int mid = (l + r) / 2;
	if (u <= mid) del(id * 2, l, mid, u, v);
	else del(id * 2 + 1, mid + 1, r, u, v);
	val[id] = min(val[id * 2], val[id * 2 + 1]);
}

int getMin (int id, int l, int r, int u, int v) {
	if (v < l || r < u || u > v) return INF;
	if (u <= l && r <= v) {
		return val[id];
	}
	int mid = (l + r) / 2;
	return min(getMin(id * 2, l, mid, u, v), getMin(id * 2 + 1, mid + 1, r, u, v));
}

int d[300005];

int main()
{//IN;
	freopen("redistricting.in","r",stdin);
	freopen("redistricting.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cin >> s;
    s = '0' + s;
    int N = 2 * n;
    FOR (i, 0, 4 * N) val[i] = INF;
    FOR (i, 1, n) {
    	g[i] = g[i - 1];
    	h[i] = h[i - 1];
    	if (s[i] == 'H') h[i]++;
    	else g[i]++;
    }	

    update(1, 0, N, n, 0);

    FOR (i, 1, n) {
    	int u = getMin(1, 0, N, 0, n + h[i] - g[i] - 1);
    	d[i] = val[1] + 1;
    	if (u < INF) d[i] = min(d[i], u);
    	update(1, 0, N, n + h[i] - g[i], d[i]);
    	//cout << i << " " << u << " " << d[i] << endl;
    	
    	if (i - k >= 0) {
    		del(1, 0, N, n + h[i - k] - g[i - k], d[i - k]);
    	}
    }

    cout << d[n] << endl;




    
	
    return 0;
}