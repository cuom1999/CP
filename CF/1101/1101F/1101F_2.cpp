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

ll d[505][505], d1[505][505], opt[505][505], opt1[505][505];
ll a[505];

struct data {
	int s, f;
	ll c;
	data (int __s = 0, int __f = 0, ll __c = 0) {
		s = __s;
		f = __f;
		c = __c;
	}
};

vector<data> trucks[505];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 0, 500) {
    	FOR (j, 0, 500) {
    		d[i][j] = 1e18 + 10;
    	}
    }

    int n, m;
    cin >> n >> m;
    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, m) {
    	int s, f, r;
    	ll c;
    	cin >> s >> f >> c >> r;
    	trucks[min(r + 1, n)].pb(data(s, f, c));
    }

    FOR (i, 1, n) {
    	FOR (j, 1, i) d[i][j] = 0;
    }
    ll res = 0;

    FOR (K, 1, n) {
    	FOR (l, 1, n) {
    		FOR (r, l, n) {
    			d1[l][r] = d[l][r];
    			d[l][r] = 1e18 + 10;
    		}
    	}
    	FOR (l, 1, n) {
    		int opt = l;
    		FOR (r, l, n) {
    			while (opt <= r && max(d1[l][opt], a[r] - a[opt]) < d[l][r]) {
    				d[l][r] = max(d1[l][opt], a[r] - a[opt]); 
    				opt++;
    			}
    			opt--;
    			//cout << l << " " << r << " " << d[l][r] << endl;
    		}
    	}
    	for (auto i: trucks[K]) {
    		res = max(res, i.c * 1ll * d[i.s][i.f]);
    		//cout << i.s << " " << i.f << " " << i.c * d[i.s][i.f] << endl;
    	}
    }

    cout << res << endl;

    
	
    return 0;
}