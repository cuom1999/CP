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
ll a[100005][5];
ll d[100005][5];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
    	ll x, y;
    	cin >> x >> y;
    	ll u = x * y - 1;
    	ll m = (x + y) % 2;
    	u = mu(2, u);
    	a[i][m] = a[i][m + 2] = u;
    }
    d[0][0] = 1;
    FOR (i, 1, n) {
    	FOR (j, 0, 3){
    		FOR (k, 0, 3) {
    			d[i][j ^ k] = (d[i][j ^ k] + d[i - 1][j] * a[i][k] % K) % K;
    		}
    	}
    }
    cout << d[n][0] << endl;
    
	
    return 0;
}