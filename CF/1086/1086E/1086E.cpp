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

const ll K = 998244353;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

int a[2005][2005];
int n;
ll gt[2005], rev[2005];

int x[2005], y[2005];

struct BIT{
	int fen[2005];

	void add(int u, int v) {
		for (int i = u; i <= n; i += i & -i) {
			fen[i] += v;
		}
	}

	int getSum(int u) {
		int res = 0;
		for (int i = u; i; i -= i & -i) {
			res += fen[i];
		}
		return res;
	}
} S1, S2;


ll calc1(int a[2005]) {
	ll res = 0;
	FOR (i, 1, n) S1.add(i, 1);
	FOR (i, 1, n) {
		ll u = S1.getSum(a[i]) - 1;
		if (u < 0) u = 0;
		res = (res + u * gt[n - i] % K) % K;
		S1.add(a[i], -1);
	}
	return res;
}

ll d[2005][2005];

ll calc(ll n, ll k) {
/*	ll res = gt[n];
	FOR (i, 1, k) {
		ll u = gt[k] * rev[i] % K * rev[k - i] % K * gt[n - i] % K;
		if (i % 2 == 1) {
			res = (res - u + K) % K;
		}
		else {
			res = (res + u) % K;
		}
	}
	return res; */
	if (k < 0) return 0;
	return d[n][k]; 
}

ll calc2(int a[2005], int b[2005]) {
	ll res = 0;
	FOR (i, 1, n) {
		S1.fen[i] = 0;
		S2.fen[i] = 0;
		x[i] = 1;
		y[i] = 1;
	}
	FOR (i, 1, n) {
		S1.add(i, 1);
		S2.add(i, 1);
	}
	
	FOR (i, 1, n) {
		if (x[a[i]]){
			x[a[i]] = 0;
			S1.add(a[i], -1);
		}
		ll k = S1.getSum(n);
		if (a[i] > b[i]) {
			ll u = S1.getSum(b[i] - 1);
			res = (res + u * calc(n - i, k - 1) % K) % K; 
			ll v = S2.getSum(b[i] - 1) - u;
			if (v < 0) v = 0;
			res = (res + v * calc(n - i, k) % K) % K;
		}
		else {
			ll u = S1.getSum(b[i] - 1);
			res = (res + u * calc(n - i, k - 1) % K) % K;
			ll v = S2.getSum(b[i] - 1) - u;
			if (y[a[i]]) v--;
			if (v < 0) v = 0; 		
			res = (res + v * calc(n - i, k) % K) % K;
		}
		if (x[b[i]]){
			x[b[i]] = 0;
			S1.add(b[i], -1);
		}
		S2.add(b[i], -1);
		y[b[i]] = 0;
	}
	return res;
}

ll calc1_trau(int a[2005]) {
	int b[2005];
	FOR (i, 1, n) b[i] = i;
	vector<ll> v;
	do {
		ll A = 0;
		FOR (i, 1, n) {
			A = (A * 15 + b[i]);
		}
		v.pb(A);
	} while(next_permutation(b + 1, b + n + 1));
	sort(all(v));
	ll A = 0;
	FOR (i, 1, n) {
		A = (A * 15 + a[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == A) return i;	
	}
	return 0;
}

ll calc2_trau(int a[2005], int b[2005]) {
	int c[2005];
	FOR (i, 1, n) c[i] = i;
	vector<ll> v;
	do {
		ll A = 0;
		bool q = 0;
		FOR (i, 1, n) {
			if (c[i] == a[i]) q = 1;
		}
		if (q) continue;
		FOR (i, 1, n) {
			A = (A * 15 + c[i]);
		}
		v.pb(A);
	} while(next_permutation(c + 1, c + n + 1));

	sort(all(v));
	ll A = 0;
	FOR (i, 1, n) {
		A = (A * 15 + b[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == A) return i;
	} 
	return 0;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0] = rev[0] = 1;
    FOR (i, 1, 2000) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }

    FOR (i, 0, 2000) d[i][0] = gt[i];
    FOR (j, 1, 2000) {
    	FOR (i, j, 2000) {
    		d[i][j] = (d[i][j - 1] - d[i - 1][j - 1] + K) % K;
    	}
    }

    cin >> n;
    FOR (i, 1, n) {
    	FOR (j, 1, n) cin >> a[i][j];
    }

    ll res = 0;
    ll S = calc(n, n);
    res = calc1(a[1]) * mu(S, n - 1) % K;
    
    FOR (i, 2, n) {
    	res = (res + calc2(a[i - 1], a[i]) * mu(S, n - i) % K) % K;
    }
    cout << res << endl;
      
	return 0;
}