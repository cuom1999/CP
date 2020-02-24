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

const int K = 2520;
int k[1005], m[1005], e[1005][12];

struct SCC {
	static const int N = 1005 * 2520;

	vector<int> v[N];

	int num[N], low[N], vs[N], res[N], dd[1005];
	int TIME, numSCC;
	vector<int> SCC[N], STACK;

	int index(int x, int c) {
		return (x - 1) * 2520 + c;
	}

	int getVertex(int x) {
		return x / 2520 + 1;
	} 

	void addEdge(int x1, int c1, int x2, int c2) {
		// cout << x1 << " " << c1 << " " << x2 << " " << c2 << endl;
		v[index(x1, c1)].pb(index(x2, c2));		
	}

	void dfs(int a){
		// cout << a << " " << getVertex(a) << " " << a % 2520 << endl;
		low[a]=num[a]=++TIME;
		STACK.pb(a);
		for (auto i: v[a]){
			if (!num[i]) dfs(i);
			if (!vs[i]) low[a]=min(low[a],low[i]);
			if (res[i]) {
				// cout << a << " " << i << " " << res[i] << endl;
				res[a] = res[i];
				// cout << res[a] << endl;
			}
		}

		if (num[a]==low[a]) {
			numSCC++;
			while (STACK.size()){
				int b = STACK.back(); SCC[numSCC].pb(b);
				STACK.pop_back();
				vs[b]=1;
				if (b == a) break;
			}
			
			if (res[a]) return;

			int cnt = 0;

			for (auto i: SCC[numSCC]) {
				if (!dd[getVertex(i)]) {
					cnt++;
					dd[getVertex(i)] = 1;
				}
			} 
			for (auto i: SCC[numSCC]) {
				res[i] = cnt;
				// cout << i << " " << res[i] << " K" << endl;
				dd[getVertex(i)] = 0;
			}
		}
	}

	int getResult(int x, int c) {
		dfs(index(x, c));
		return res[index(x, c)];
	}
}scc;

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> k[i];
		k[i] = (k[i] % K + K) % K;
	}

	FOR (i, 1, n) {
		cin >> m[i];
		FOR (j, 0, m[i] - 1) {
			cin >> e[i][j];
		}
	}

	FOR (i, 1, n) {
		FOR (j, 0, 2519) {
			int newX = e[i][j % m[i]];
			int newC = (k[newX] + j) % K;
			scc.addEdge(i, j, newX, newC);
		}
	}

	int q;
	cin >> q;

	FOR (z, 1, q) {
		int x, c;
		cin >> x >> c;
		c = (c % K + k[x] + K) % K;
		cout << scc.getResult(x, c) << "\n";
	}

	return 0;
}