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

int lab[500005];

int getRoot(int a) {
	while (lab[a] >= 0) a = lab[a];
	return a;
}

void dsu(int a, int b) {
	int x = lab[a] + lab[b];

	if (lab[a] < lab[b]) {
		lab[a] = x;
		lab[b] = a;
	}
	else {
		lab[b] = x;
		lab[a] = b;
	}
} 

int b[500005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	memset(lab, -1, sizeof(lab));

	int n, m;
	cin >> n >> m;

	FOR (i, 1, m) {
		int k;
		cin >> k;
		if (k == 0) continue;
		FOR (j, 1, k) {
			cin >> b[j];
		}

		int u = getRoot(b[1]);

		FOR (j, 2, k) {
			int v = getRoot(b[j]);
			if (u != v) dsu(u, v);
			u = getRoot(u);
		}
	}

	FOR (i, 1, n) {
		int u = getRoot(i);
		// cout << u << endl;

		cout << -lab[u] << " ";
	}


	return 0;
}