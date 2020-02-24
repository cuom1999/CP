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

ll st[4 * 200005];
ll h[200005], a[200005];

void update(int id, int l, int r, int u, ll v) {
	if (l == r) {
		st[id] = v;
		return;
	}

	int mid = (l + r) / 2;

	if (u <= mid) update(id * 2, l, mid, u, v);
	else update(id * 2 + 1, mid + 1, r, u, v);

	st[id] = max(st[id * 2], st[id * 2 + 1]);

}

ll getMax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;

	if (u <= l && r <= v) return st[id];

	int mid = (l + r) / 2;

	return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

ll d[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    FOR (i, 1, n) {
    	cin >> h[i];
    }
    FOR (i, 1, n) {
    	cin >> a[i];
    }

    d[1] = a[1];
    update(1, 1, n, h[1], d[1]);
    
    ll res = d[1];

    FOR (i, 2, n) {
    	d[i] = getMax(1, 1, n, 1, h[i]) + a[i];	
    	update(1, 1, n, h[i], d[i]);

    	//FOR (j, 1, n) cout << getMax(1, 1, n, j, j) << " "; cout << endl;
    	res = max(res, d[i]);
    }

    cout << res << endl;
    
	
    return 0;
}