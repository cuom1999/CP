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

typedef pair < int, int > II;
typedef pair < int, II > III;


int lab[100005];

int getRoot(int a) {
	while (lab[a] >= 0) {
		a = lab[a];
	}
	return a;
}

void dsu(int a, int b) {
	int x = lab[a] + lab[b];
	if (lab[a] < lab[b]) {
		lab[b] = a;
		lab[a] = x;
	}
	else {
		lab[a] = b;
		lab[b] = x;
	}
}

vector<II> edges[2], query[100005];
vector<int> v[100005];
int deg[100005], n, ans[100005];

void dfs(int a, int p) {
	vector<int> degs;
	deg[a] = -lab[a];

	int sum = deg[a];

	for (auto i: v[a]) {
		if (i == p) continue;
		dfs(i, a);
		deg[a] += deg[i];
		sum += deg[i];
		degs.pb(deg[i]);
	}
	if (p) degs.pb(n - sum);

	// cout << a << endl;
	// for (auto i: degs) {
	// 	cout << i << " ";
	// }
	// cout << endl << endl;
	sort(all(degs));

	vector<int> prefixSum;
	prefixSum.pb(0);

	for (auto i: degs) {
		prefixSum.pb(prefixSum.back() + i);
	}

	for (auto q: query[a]) {
		if (q.first < -lab[a]) {
			ans[q.second] = -1;
		}
		else {
			int m = degs.size();
			ans[q.second] = m - (upper_bound(all(prefixSum), q.first + lab[a]) - prefixSum.begin() - 1);
		}
	}
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int q;
	cin >> n >> q;

	memset(lab, -1, sizeof(lab));

	FOR (i, 1, n - 1) {
		int x, y, c;
		cin >> x >> y >> c;

		edges[c].pb({x, y});

	}

	for (auto i: edges[0]) {
		int m1 = getRoot(i.first);
		int m2 = getRoot(i.second);
		dsu(m1, m2);
	}

	for (auto i: edges[1]) {
		int u1 = getRoot(i.first);
		int u2 = getRoot(i.second);
		v[u1].pb(u2);
		v[u2].pb(u1);
		// cout << u1 << " " << u2 << endl; 
	}

	int root = getRoot(1);

	FOR (i, 1, q) {
		int q_p, q_s;
		cin >> q_p >> q_s;
		query[getRoot(q_p)].pb({q_s, i});
	} 


	// cout << root << endl;
	dfs(root, 0);

	FOR (i, 1, q) {
		cout << ans[i] << endl;
	}




	return 0;
}