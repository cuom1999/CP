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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int n;

struct BIT {
	ll fen[2][1000005];

	void add(int u, ll v, int pos) {
		for (int i = u; i <= n; i += i & -i) {
			fen[pos][i] += v;
		}
	}

	ll query(int u, int pos) {
		ll res = 0;
		for (int i = u; i; i -= i & -i) {
			res += fen[pos][i]; 
		}
		return res;
	}

	void add(int u, int v, ll a, ll b) {
		if (u > v) return;

		add(u, a, 1);
		add(v + 1, -a, 1);
		add(u, b, 0);
		add(v + 1, -b, 0);
	}

	ll getVal(int u) {
		return query(u, 0) + query(u, 1) * 1ll * u;
	}
} fenL, fenR;

const int MAXN = 1000005;

int a[MAXN], l[MAXN], r[MAXN], parL[MAXN], parR[MAXN];

vector<II> queryL[MAXN], queryR[MAXN];
vector<int> stackL, stackR;



ll ans[MAXN];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    FOR (i, 1, q) {
    	cin >> l[i];
    }

    FOR (i, 1, q) {
    	cin >> r[i];
    }

    FOR (i, 1, q) {
    	queryR[r[i]].pb(II(l[i], i));
    	queryL[l[i]].pb(II(r[i], i));
    }
	
    FOR (i, 1, n) {
    	while (stackL.size() && a[stackL.back()] < a[i]) stackL.pop_back();
    	
    	if (stackL.size()) {
    		parL[i] = stackL.back();
    	}
    	else {
    		parL[i] = 0;
    	}

    	stackL.pb(i);
    }

    FOR (i, 1, n) {
    	fenL.add(1, parL[i], 0, i - parL[i] - 1);
    	fenL.add(parL[i] + 1, i - 1, -1, i);

    	for (auto j: queryR[i]) {
    		ans[j.second] += fenL.getVal(j.first);
    	}
    }

    FORD (i, n, 1) {
    	while (stackR.size() && a[stackR.back()] < a[i]) stackR.pop_back();
    	
    	if (stackR.size()) {
    		parR[i] = stackR.back();
    	}
    	else {
    		parR[i] = n + 1;
    	}

    	stackR.pb(i);
    }

    FORD (i, n, 1) {
    	fenR.add(parR[i], n, 0, parR[i] - i - 1);
    	fenR.add(i + 1, parR[i] - 1, 1, -i);

    	for (auto j: queryL[i]) {
    		ans[j.second] += fenR.getVal(j.first);
    	}
    }

    FOR (i, 1, q) {
    	cout << ans[i] + r[i] - l[i] + 1 << " ";
    }

    return 0;
}