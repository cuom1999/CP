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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n) {
    	cin >> a[i];
    }
    FOR (z, 1, q){
    	int t;
    	cin >> t;
    	if (t == 1) {
    		int l, r, c;
    		cin >> l >> r >> c;
    		FOR (i, l, r) a[i] ^= c;
    	}
    	else {
    		int l, r;
    		cin >> l >> r;
    		int m = r - l + 1;
    		ll res = 0;
    		FOR (i, 1, (1 << m) - 1) {
    			ll u = 0;
    			FOR (j, 0, m - 1) {
    				if (i & (1 << j)) {
    					u |= a[j + l];
    				}
    			}
    			res = (res + u) % K;
    		}
    		cout << res << endl;
    	}
    }
	
    return 0;
}