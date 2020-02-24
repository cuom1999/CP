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

const ll K = 1e9 + 7;

ll d[4005];
ll gt[4005];
ll rev[4005];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

vector<vector<II>> V;

void solve(int S, int i, vector<II> v) {
	if (S == 0) {
		V.pb(v);
		return;
	}
	if (i > S) return;
	

	for (int j = 0; j <= S / i; j++) {
		vector<II> v1 = v;
		if (j) v1.pb(II(i, j));
		solve(S - i * j, i + 1, v1);
	}
}

vector<II> rong;
ll mu2[4005];
ll pre[4005]; 

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    d[0] = 1;
    gt[0] = 1;
    rev[0] = 1;
    mu2[0] = 1;
    FOR (i, 1, 4000) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    	mu2[i] = mu2[i - 1] * 2ll % K;
    }
    int n, m;
    cin >> n >> m;
    if (m < n) swap(m, n);

    solve(n, 1, rong);
    ll res = 0;

    for (auto v: V) {
	   	FOR (i, 1, m) {
    		d[i] = 0;
    	}
        FOR (i, 1, m) {
            ll Q = 0;
            for (auto k: v) {
                Q = (Q + __gcd(k.first, i) * k.second);
            }
            pre[i] = Q;
        }
    	FOR (i, 1, m) {
    		FOR (j, 1, i) {
    			ll Q = 0;
    			d[i] = (d[i] + d[i - j] * gt[i - 1] % K * rev[i - j] % K * mu2[pre[i]]) % K;
    		}
    	}
    	ll P = gt[n];
    	for (auto i: v) {
    		P = P * mu(mu(i.first, i.second), K - 2) % K;
    		P = P * mu(gt[i.second], K - 2) % K;
    	}
    	//cout << P << " " << d[m] << " " << P * d[m] << endl;
    	res = (res + d[m] * P % K) % K;
    }
    res = res * mu (gt[m] * gt[n] % K, K - 2) % K;
    cout << res << endl;
    
    return 0;
}