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
const ll K = 1e9 + 7;

ll mu (ll a, ll n){
	if (n == 0) return 1;
	ll q = mu(a, n/2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll st[400005];
ll lz[400005];

void down (int id, int l, int r){
	if (l == r || !lz[id]) return;
	ll u = lz[id];
	int mid = (l + r) / 2;

	lz[id * 2] = (lz[id * 2] + u) % K;
	lz[id * 2 + 1] = (lz[id * 2 + 1] + u) % K;

	st[id * 2] = (st[id * 2] + u * 1ll * (mid - l + 1) % K) % K;
	st[id * 2 + 1] = (st[id * 2 + 1] + u * 1ll * (r - mid) % K) % K;

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll k){
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		st[id] = (st[id] + k * 1ll * (r-l+1) % K) % K;
		lz[id] = (lz[id] + k) % K;
		return ;
	}
	int mid = (l + r) / 2;
	down (id, l, r);
	update(id * 2, l , mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);
	st[id] = (st[id * 2] + st[id * 2 +1]) % K;
}

ll sum (int id, int l, int r, int u, int v){
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return st[id];
	int mid = ( l + r ) / 2;
	down(id, l, r);
	return (sum(id * 2, l, mid, u, v) + sum(id * 2 + 1, mid + 1, r, u, v))% K;
}

ll A[100005], C[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int q;
    cin >> n >> q;
    ll res = 0;

    FOR (z, 1, q){
    	int t;
    	cin >> t;
    	if (t == 1){
    		int l, r;
    		cin >> l >> r;
    		ll u = r - l + 1;
    		u = mu(u, K-2);
    		res = (res + sum(1, 1, n, l , r) * 2ll %K * u % K + 1) % K;
    		update(1, 1, n, l, r, u);
    		/*FOR (i, l, r){
    			C[i] = (C[i] + u * (2ll * A[i] + 1) % K) % K;
    			A[i] = (A[i] + u) % K;
    		}*/
    	}
    	else{
    		/*ll res1 = 0;
    		FOR (i, 1, n){
    			res1 = (res1 + C[i]) % K;
    		}
    		cout << res << " " << res1 <<endl;*/
    		cout << res << endl;
    	}
    }


    
	
         return 0;
}