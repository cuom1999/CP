#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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
ll d[6005][6005];

ll C[6005][6005];

ll A[6005], B[6005];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll pw[5015];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll N, n, m, k;

    cin >> N >> n >> m >> k;

    FOR (i, 1, 5010) {
    	pw[i] = mu(i, N);
    }

    FOR (l, 1, n) {
    	FOR (u, 1, n - l + 1) {
    		A[l] = (A[l] + pw[u] * pw[n + 2 - u - l] % K) % K;
    	}
    }

    FOR (c, 1, m) {
    	FOR (v, 1, m - c + 1) {
    		B[c] = (B[c] + pw[v] * pw[m + 2 - v - c] % K) % K;
    	}
    }

    FOR (l, 1, n) {
    	FOR (c, 1, m) C[l][c] = A[l] * B[c] % K; 
    }

    ll res = 0;
    
   	FORD (l, n, 1) {
   		FORD (r, m, 1) {
   			d[l][r] = (C[l][r] - 2 * d[l + 1][r] - 2 * d[l][r + 1]) % K;
   			if (l * r >= k) res = (res + d[l][r]) % K; 
   			cout << l << " " << r << " " << d[l][r] << endl;
   		}
   	}

   	if (res < 0) res += K;
   	cout << res << endl;
	
    return 0;
}