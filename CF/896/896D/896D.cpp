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

ll n, p, l, r, K;

ll gt[100005], rev[100005], gt1[100005];

ll mu(ll a, ll n, ll K) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2, K);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
} 

ll Combi(ll n, ll k, ll p) {
	if (n < k || k < 0) return 0;
	ll u = gt1[n] - gt1[n - k] - gt1[k];
	ll res = gt[n] * rev[k] % K * rev[n - k] % K;
	
	res = res * mu(p, u, K) % K;
	return res;
}

ll solve(ll p, ll k) { // mod p^k
	K = 1;
	ll phi = 1;
	FOR (i, 1, k) K *= p;
	phi = K / p * (p - 1);

	gt[0] = rev[0] = 1;

	FOR (i, 1, 100000) {
		gt1[i] = gt1[i - 1];
		int j = i;
		while (j % p == 0) {
			j /= p;
			gt1[i]++;
		}
		gt[i] = gt[i - 1] * 1ll * j % K;
		rev[i] = mu(gt[i], phi - 1, K);
	}

	ll res = 0;
	FOR (m, 1, n) {
		int u = (m + l - 1) / 2 + 1;
		int v = (m + r) / 2;
		res = (res + Combi(n, m, p) * (Combi(m, u, p) - Combi(m, v + 1, p)) % K + K) % K;
	}
	return res;
}

vector<II> divi;

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) {
		ll q = a / b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}

// x % r1 == m1
ll CRT(ll m1, ll r1, ll m2, ll r2) {
	ll s, t;
	extended_euclid(r1, r2, s, t);
	ll K = r1 * r2;
	ll res = (m2 - m1) * s % K * r1 % K;
	res = (res + m1 + K) % K;
	return res;
}

ll val[100005];
ll mod[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> p >> l >> r;
    if (p == 1) {
    	cout << 0 << endl;
    	return 0;
    }

    for (int i = 2; i <= p / i; i++) {
    	if (p % i == 0) {
    		int cnt = 0;
    		while (p % i == 0) {
    			p /= i;
    			cnt++;
    		}
    		divi.pb(II(i, cnt));
    	}
    }
    if (p > 1) divi.pb(II(p, 1));

    //for (auto i: divi) cout << i.first << " " << i.second << endl;
    
    //if (l == 0) res++;
    for (int i = 0; i < divi.size(); i++) {
    	val[i] = solve(divi[i].first, divi[i].second);
    	mod[i] = 1;
    	FOR (j, 1, divi[i].second) mod[i] *= divi[i].first;
    	//cout << mod[i] << " " << val[i] << endl;
    }
    
    ll res = val[0];
    ll M = mod[0];
    for (int i = 1; i < divi.size(); i++) {
    	res = CRT(res, M, val[i], mod[i]);
    	M *= mod[i];
    }
    if (l == 0) res = (res + 1) % M;

    cout << res << endl;



    return 0;
}