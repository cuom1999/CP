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

ll a[100005];
const ll K = 1e9 + 7;
ll mu[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    mu[0] = 1;
    FOR (i, 1, 200000) mu[i] = mu[i - 1] * 2 % K;

	int n, q;
	cin >> n >> q;
	FOR (i, 1, n) cin >> a[i];
	FOR (z, 1, q) {
		int t, l, r;
		cin >> t;
		if (t == 1) {
			ll c;
			cin >> l >> r >> c;
			FOR (i, l, r) a[i] ^= c;
		}
		else {
			cin >> l >> r;
			ll res = 0;
			FOR (b, 0, 31) {
				ll cnt = r - l + 1;
				FOR (i, l, r) {
					if (a[i] & (1 << b)) cnt--;
				}
				res = (res + mu[b] * (mu[r - l + 1] - mu[cnt] + K) % K) % K; 
			}
			cout << res << endl;
		}
	}    
	
    return 0;
}