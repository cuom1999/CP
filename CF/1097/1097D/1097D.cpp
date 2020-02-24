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

const ll K = 1e9 + 7;

ll d[18][106][10005];
ll s[105][10005];
vector<II> divisors;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) {
		return q * q % K;
	}
	return q * q % K * a % K;
}

ll res = 0;
ll n, k;


void solve(int i, ll a, ll p) {
	if (i == divisors.size()) {
		res = (res + a % K * p % K) % K;
		//cout << a << endl;
		return;
	}
	ll prod = 1;
	for (int j = 0; j <= divisors[i].second; j++) {
		solve(i + 1, a * prod % K, p * d[i][j][k] % K);
		prod = prod * divisors[i].first % K;
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;

    for (ll i = 2; i <= n / i; i++) {
    	if (n % i == 0) {
    		ll num = 0;
    		while (n % i == 0) {
    			num++;
    			n /= i;
    		}
    		divisors.pb(II(i, num));
    	}
    }
    if (n > 1) {
    	divisors.pb(II(n, 1));
    }

    int m = divisors.size();

    FOR (i, 0, m - 1) {
    	int t = divisors[i].second;  
    	d[i][t][0] = 1;
    	FOR (j, 0, t - 1) d[i][j][0] = 0;
    	
    	FOR (j, 0, t) s[j][0] = mu(t + 1, K - 2);
    	s[t + 1][0] = 0;

    	FOR (j, 1, k) {
    		s[t + 1][j] = 0;
    		FORD (u, t, 0) {
    			d[i][u][j] = s[u][j - 1];
    			s[u][j] = (s[u + 1][j] + d[i][u][j] * mu(u + 1, K - 2) % K) % K;
    		}
    		//FOR (u, 0, t) cout << d[u][j] << " "; cout << endl;
    	}
    	//FOR (j, 0, t) cout << d[i][j][k] << " "; cout << endl;
    }
    solve(0, 1, 1);

    cout << res << endl;




    
	
    return 0;
}