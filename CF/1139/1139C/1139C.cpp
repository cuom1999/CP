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

int vs[100005];
vector<int> v[100005];
ll c[100005];

void dfs(int u, int cc) {
	c[cc]++;
	vs[u] = 1;
	for (auto i: v[u]) {
		if (!vs[i]) dfs(i, cc);
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, k;

    cin >> n >> k;

    FOR (i, 1, n - 1) {
    	int u, vv, x;
    	cin >> u >> vv >> x;
    	if (x == 0) {
    		v[u].pb(vv);
    		v[vv].pb(u);
    	}
    }

    int cc = 0;

    FOR (i, 1, n) {
    	if (!vs[i]) {
    		dfs(i, ++cc);
    	}
    }

    ll res = mu(n, k);

    FOR (i, 1, cc) {
    	//cout << c[i] << " ";
    	res = (res - mu(c[i], k)) % K;
    }

    res = (res + K) % K;

    cout << res << endl;



    
	
    return 0;
}