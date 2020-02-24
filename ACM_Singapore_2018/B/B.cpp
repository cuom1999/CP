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

vector<int> v[500005], cc[500005];
int dd[500005];


void dfs(int a, int C, int u) {
	if (dd[a]) return;
	dd[a] = u; 
	cc[C].pb(a);
	for (auto i: v[a]) {
		dfs(i, C, u % 2 + 1);
	}
}



bool check(int C) {
	for (auto a: cc[C]) {
		for (auto i: v[a]) {
			if (dd[i] + dd[a] != 3) return 0;
		}
	}
	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	int C = 0;
	FOR (i, 1, n) {
		if (!dd[i]) dfs(i, ++C, 1);
	}
	int res = 1;
	FOR (i, 1, C) {
		if (!check(i)) res = 0; 
	}

	res += C - 1;

	cout << res << endl;



	
    return 0;
}