#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("roxor.inp","r",stdin)
#define OUT freopen("roxor.out","w",stdout)
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

/* Cho day a[1], a[2],..., a[n]
1 l r c: a[i] ^= c voi i = l -> r
2 l r: xet tap S = {a[l] -> a[r]}, voi moi tap con P cua S, tinh OR cua tat ca phan tu cua
P. Tinh tong tat ca P mod 10^9 + 7.

Format:
n q 
a[1] a[2] ... a[n]
q queries
*/

const ll K = 1e9 + 7;

int st[35][400005];
int lz[35][400005];
int a[100005];

void build (int bit, int id, int l, int r) {
	if (l == r) {
		st[bit][id] = (bool) (a[l] & (1 << bit));
		return;
	}
	int mid = (l + r) / 2;
	build (bit, id * 2, l, mid);
	build (bit, id * 2 + 1, mid + 1, r);
	st[bit][id] = st[bit][id * 2] + st[bit][id * 2 + 1];
}

void down (int bit, int id, int l, int r){
	if (l == r || !lz[bit][id]) return;
	int mid = (l + r) / 2;
	st[bit][id * 2] = mid - l + 1 -st[bit][id * 2];
	lz[bit][id * 2] ^= 1;
	st[bit][id * 2 + 1] = r - mid - st[bit][id * 2 + 1];
	lz[bit][id * 2 + 1] ^= 1;
	lz[bit][id] = 0;
}

// only update if bit(c) = 1
void update (int bit, int id, int l, int r, int u, int v) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[bit][id] = r - l + 1 - st[bit][id];
		lz[bit][id] ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	down (bit, id, l, r);
	update(bit, id * 2, l, mid, u, v);
	update(bit, id * 2 + 1, mid + 1, r, u, v);
	st[bit][id] = st[bit][id * 2] + st[bit][id * 2 + 1];
}

int getSum (int bit, int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return st[bit][id];
	int mid = (l + r) / 2;
	down(bit, id, l, r);
	return getSum(bit, id * 2, l, mid, u, v) + getSum(bit, id * 2 + 1, mid + 1, r, u, v);
}
int mu[100005];

int main()
{IN; OUT;
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
    mu[0] = 1;
    FOR (i, 1, 100000){
    	mu[i] = mu[i - 1] * 2ll % K;
    }

	int n, q;
	// cin >> n >> q;
	scanf("%d%d", &n, &q);

	FOR (i, 1, n) {
		// cin >> a[i];
		scanf("%d", &a[i]);
	}
	FOR (i, 0, 31) build (i, 1, 1, n);

	FOR (z, 1, q) {
		int t;
		// cin >> t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, c;
			// cin >> l >> r >> c;
			scanf("%d%d%d", &l, &r, &c);
			FOR (i, 0, 31) {
				if (c & (1 << i)) update(i, 1, 1, n, l, r);
			}
		}
		else {
			int l, r;
			// cin >> l >> r;
			scanf("%d%d", &l, &r);
			ll res = 0;
			FOR (i, 0, 31) {
				int y = r - l + 1 - getSum(i, 1, 1, n, l, r);
				res += mu[i] * 1ll * (mu[r - l + 1] - mu[y] + K) % K;
				res %= K;
			}
			// cout << res << endl;
			printf("%lld\n", res);
		}
	}

	
    return 0;
}