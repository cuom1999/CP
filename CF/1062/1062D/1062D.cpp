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
typedef pair < ll, ll > II;

inline int abs(int n){
	if (n < 0) n = -n;
	return n;
}
vector<II> v[100005];
vector<int> CC[100005];
int dd[100005];
void dfs(int a, int C){
	dd[a] = 1;
	CC[C].pb(a);
	for (auto i: v[a]){
		if (!dd[i.first]){
			dfs(i.first, C);
		}
	}
}
ll val[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin >> n;
	FOR (i, 2, n){
		for (int j = 2; j <= n / i; j++){
			v[i].pb(II(i * j, j));
			v[i * j].pb(II(i, j));
			val[i] += j;
		}
	}    
	int C = 0;
	FOR (i, 2, n){
		if (!dd[i]) dfs(i, ++C);
	}
	ll R = 0;
	FOR (i, 1, C) {
		ll Q = 0;
		for (auto j: CC[i]){
			Q += val[j];
		}
		R = max(R, Q);
	}
	cout << R * 4 << endl;
	

         return 0;
}