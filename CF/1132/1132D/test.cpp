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

int n;
ll k;
ll a[200005], b[200005];
ll s[200005];
ll st[200005 * 4], lz[200005 * 4];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = -l;
		lz[id] = 0;
		return;
	}

	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
	lz[id] = 0;
}

void down(int id, int l, int r) {
	if (l == r || !lz[id]) return;

	st[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	
	st[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id]++;
		lz[id]++;
		return;
	}

	int mid = (l + r) / 2;
	down(id, l, r);

	update(id * 2, l, mid, u, v);
	update(id * 2 + 1, mid + 1, r, u, v);

	st[id] = max(st[id * 2], st[id * 2 + 1]); 
}

bool solve(ll x) {
	if (k == 1) return 1;

	build(1, 1, k - 1);

	FOR (i, 1, n) {
		ll val = a[i];

		while (val / b[i] < k - 1) {
			//cout << val / b[i] + 1 << " " << i << endl;

			update(1, 1, k - 1, val / b[i] + 1, k - 1);

			if (st[1] > 0) return 0;

			//cout << st[1] << endl;

			val += x;
		}
	}


	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> k;

    FOR (i, 1, n) cin >> a[i];

    FOR (i, 1, n) cin >> b[i];
	
    //cout << solve(0) << endl;
	//cout << solve(1) << endl;
	//FOR (i, 0, 10) cout << solve(i) << " ";

    ll L = 0, R = 1e18;

    while (L < R) {
    	ll mid = (L + R) / 2;
    	if (solve(mid)) {
    		R = mid;
    	}
    	else {
    		L = mid + 1;
    	}
    }


    if (solve(L)) {
    	cout << L << endl;
    }
    else {
    	cout << -1 << endl;
    }

    return 0;
}