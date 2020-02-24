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

ll mu(ll a, ll n){
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll gt[1000005];
ll rev[1000005];
ll P[1000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0] = rev[0] = 1;
    FOR (i, 1, 1000002){
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }

    ll n, k;
    cin >> n >> k;
    FOR (i, 1, k + 1){
    	P[i] = (P[i - 1] + mu(i, k)) % K;
    }

    if (n <= k + 1) {
    	cout << P[n] << endl;
    	return 0;
    }
    ll res = 0;
    ll prod = 1;

    FOR (i, 0 , k + 1){
    	prod = prod * (n - i) % K;
    }

    FOR (i, 1, k + 1){
    	ll Q = P[i] * prod % K;
    	Q = Q * mu(n - i, K - 2) % K;
    	Q = Q * rev[i] % K * rev[k + 1 - i] % K;
    	if ((k + 1 - i) % 2 == 0) res = (res + Q) % K;
    	else res = (res - Q + K) % K;
    }

    cout << res << endl;



	
    return 0;
}