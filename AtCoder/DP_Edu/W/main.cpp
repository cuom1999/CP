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
typedef pair < ll, ll > II;

ll d[200005];

ll st[200005 * 4], lz[200005 * 4];

void down(int id, int l, int r) {
	if (l == r || !lz[id]) return;

	st[id * 2] += lz[id];
	lz[id * 2] += lz[id];

	st[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll k) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		return;
	}

	int mid = (l + r) / 2;
	down(id, l, r);

	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll getMax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return -1e18;
	if (u <= l && r <= v) return st[id];

	int mid = (l + r) / 2;
	down(id, l, r);

	return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

vector<II> leftInt[200005];
vector<II> rightInt[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    FOR (i, 1, m) {
    	int l, r;
    	ll a;
    	cin >> l >> r >> a;

    	leftInt[l].pb(II(r, a));
    	rightInt[r].pb(II(l, a));
    }

    ll res = 0;

    FOR (i, 1, n) {
    	for (auto j: leftInt[i]) {
    		update(1, 0, n, 0, i - 1, j.second);
    	}

    	d[i] = getMax(1, 0, n, 0, i - 1);

    	update(1, 0, n, i, i, d[i]);

    	for (auto j: rightInt[i]) {
    		update(1, 0, n, 0, j.first - 1, -j.second);
    	}

    	res = max(res, d[i]);
    }

    cout << res << endl;
    
		
    return 0;
}