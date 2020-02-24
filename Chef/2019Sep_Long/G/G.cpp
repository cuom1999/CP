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

bitset<100005> bs[30];
int numLevel;

void dfs(int l, int r, int level) {
	if (l == r) return;
	numLevel = max(numLevel, level);

	int mid = (l + r) / 2;
	FOR (i, l, mid) {
		bs[level][i] = 0;
	}
	FOR (i, mid + 1, r) {
		bs[level][i] = 1;
	}
	dfs(l, mid, level + 1);
	dfs(mid + 1, r, level + 1);
}
int main()
{IN; 
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	FOR (i, 1, m) {
		int a, b;
		cin >> a >> b;
	}

	dfs(1, n, 1);
	cout << numLevel << "\n";
	FOR (i, 1, numLevel) {
		FOR (j, 1, n) {
			cout << bs[i][j];
		}
		cout << "\n";
	}

	return 0;
}