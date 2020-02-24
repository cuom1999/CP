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
/*
vector<int> v[100005];
int C = 0;
int dd[100005];

void dfs(int a) {
	dd[a] = 1;
	for (auto i: v[a]) if (!dd[i]) dfs(i);
}

int solve(int a, int b) {
	FOR (i, 1, max(a, b)) {
		v[i].clear();
		dd[i] = 0;
	}
	C = 0;
	FOR (i, 1, a) v[i].pb(a + 1 - i);
	FOR (i, 1, b) v[i].pb(b + 1 - i);
	FOR (i, 1, max(a, b)) {
		if (!dd[i]) {
			dfs(i);
			C++;
		}
	}
	return C;
}

int solve(vector<int> &V) {
	FOR (i, 1, V.back()) {
		v[i].clear();
		dd[i] = 0;
	}
	C = 0;
	FOR (i, 0, V.size() - 1) {
		int a = V[i];
		FOR (i, 1, a) v[i].pb(a + 1 - i);
	}
	FOR (i, 1, V.back()) {
		if (!dd[i]) {
			dfs(i);
			C++;
		}
	}
	return C;
}

ll calc(set<int> &V) {
	if (V.size() == 1) return ((*V.begin()) + 1) / 2;
	auto u = (--V.end());
	int M = *u;
	u--;
	int N = *u;
	V.erase(--V.end());
	if (M >= 2 * N) {
		return (M - 2 * N + 1) / 2 + calc(V); 
	}
	else {
		V.insert(2 * N - M);
		return calc(V);
	}
}
*/
ll mu[2005];
ll d[2005];

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, S, K;
    cin >> n >> S >> K;
    mu[0] = 1;
    FOR (i, 1, 2 * n) mu[i] = mu[i - 1] * S % K;

    d[2] = S;
    ll res = d[2] * mu[n - 2] % K;
    FOR (i, 3, n) {
    	d[i] = mu[(i + 1) / 2];
    	FOR (j, 2, (i + 1) / 2) {
    		d[i] = (d[i] - d[j] * mu[(i - 2 * j + 1) / 2] % K + K) % K;
    	}
    	//cout << i << " " << d[i] << endl;
    	res = (res + d[i] * mu[n - i] % K) % K;
    }
    res = (mu[n] - res + K) % K;
    cout << res << endl;

    return 0;
}