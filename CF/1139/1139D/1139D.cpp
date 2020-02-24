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

const ll K = 1e9 + 7;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);

	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

vector<int> divisors[100005];
vector<int> coef[100005];

ll E[100005], f[100005];
int mob[100005], comp[100005], trace[100005];

vector<int> prime;

void sieve(int n) {
    FOR (i, 2, n) {
        if (!comp[i]) {
            prime.pb(i);
            trace[i] = i;
            mob[i] = -1;
        }

        for (int j = 0; j < prime.size() && prime[j] <= n / i; j++) {
            comp[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                trace[i * prime[j]] = trace[i];
                mob[i * prime[j]] = 0;
                break; 
            }
            else {
                trace[i * prime[j]] = prime[j];
                mob[i * prime[j]] = -mob[i]; 
            }
        }

    }
}

vector<int> sqFreeDiv[100005];

int calc(int a, int b) { // x <= a and gcd(x, b) = 1
    if (b == 1) return a;
    
    int res = a;

    for (auto i: sqFreeDiv[b]) {
        res += (a / i) * mob[i];
    }
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int m;
    cin >> m;

    sieve(m);


    FOR (i, 1, m) {
    	FOR (j, 1, m / i) {
    		divisors[i * j].pb(i);
    		if (mob[i]) sqFreeDiv[i * j].pb(i);
    	}
    }


    FOR (i, 1, m) {
    	reverse(all(divisors[i]));

    	for (int j = 0; j < divisors[i].size(); j++) {
			coef[i].pb(calc(m / divisors[i][j], i / divisors[i][j]));
    	}

    	// for (auto j: divisors[i]) cout << j << " "; cout << endl;
		// for (auto j: coef[i]) cout << j << " "; cout << endl << endl;
    }

    ll invM = mu((ll) m, K - 2);

    ll res = 0;

    FOR (i, 2, m) {
    	ll val = 0;
    	for (int j = 1; j < divisors[i].size(); j++) {
    		val = (val + coef[i][j] * invM % K * E[divisors[i][j]] % K) % K;
    	} 
    	val = val + 1;
    	val = val * 1ll * m % K * mu(m - coef[i][0], K - 2) % K;

    	E[i] = val;
    	res = (res + E[i]) % K;
    } 

    res = res * invM % K;
    res = (res + 1) % K;

    cout << res << endl;

    // f[1] = 0;

    // FOR (i, 2, m) {
    // 	int cnt = 0;
    // 	ll val = 0;
    // 	FOR (j, 1, m) {
    // 		int u = __gcd(i, j);
    // 		if (u == i) {
    // 			cnt++;
    // 		}
    // 		else {
    // 			val += f[u] * invM % K;
    // 		}
    // 	}
    // 	val++;
    // 	f[i] = val * 1ll * m % K * mu(m - cnt, K - 2) % K;
    // }

    // FOR (i, 1, m) cout << E[i] << " "; cout << endl;
    // FOR (i, 1, m) cout << f[i] << " "; cout << endl;
    
    
	
    return 0;
}