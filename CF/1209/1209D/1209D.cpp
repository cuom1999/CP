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

vector<int> v[100005];
bool vs[100005];
int num = 0;

void dfs(int a) {
	if (vs[a]) return;
	vs[a] = 1;
	num++;
	for (auto i: v[a]) dfs(i);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	FOR (i, 1, k) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	int c = 0;
	FOR (i, 1, n) {
		if (v[i].size() && !vs[i]) {
			dfs(i);
			c++;
		}
	}
	cout << k - num + c << endl;



	return 0;
}