#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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


int vs[200005];

int a, b;
int cnt = 1;

void dfs(int u, int x) {
	// cout << u << " " << x << endl;
	if (u > x || u < 0 || vs[u]) return;
	vs[u] = 1;
	cnt++;
	dfs(u + a, x);
	dfs(u - b, x);
}

int solve(int x) {
	memset(vs, 0, sizeof(vs));
	dfs(0, x);
	int cnt = 0;
	FOR (i, 0, x) {
		if (vs[i]) cnt++;
	}
	return cnt;
}

ll f[200005];

void calc(int a, int b) {
	f[0] = 1;
	memset(vs, 0, sizeof(vs));
	vs[0] = 1;

	FOR (i, 1, a + b - 2) {
		if (i - a >= 0 && vs[i - a]) {
			vs[i - a] = 0;
			cnt--;
			dfs(i - a, i);
		}
		f[i] = cnt;
	}
}

ll sum(int x) {
	return x * 1ll * (x + 1) / 2;
} 
 
int main()
{//IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
    int m;
    cin >> m >> a >> b;

    int d = __gcd(a, b);

    a /= d;
    b /= d;

    int M = m / d - 1;

    calc(a, b);

    ll res = 0;
    
    if (a == 1) {
    	res = sum(M + 1);
    }
    else if (M > a + b - 2) {
    	FOR (i, 0, a + b - 2) {
    		res += 1ll * f[i];
    	}

    	res += sum(M + 1) - sum(a + b - 1);
    }
    else {
    	FOR (i, 0, M) {
    		res += 1ll * f[i];
    		// cout << f[i] << endl;
    	}
    }

    res *= (ll) d;

    int curF = 0;

    if (a == 1 || M + 1 > a + b - 2) curF = M + 2;
    else curF = f[M + 1];

    // cout << res << endl;

    res += curF * 1ll * (m - (M + 1) * d + 1);

    cout << res << endl;
    return 0;
}