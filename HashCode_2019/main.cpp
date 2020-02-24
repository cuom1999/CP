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

const int MAXN = 100005;

map<string, int> tags;
int n;

vector<int> v[MAXN], contain[10000005], ver[MAXN], oldIndex[MAXN];
int stt[MAXN];
char type[MAXN];
int curInd = -1;
int curIndV = -1;

void readFile() {
	cin >> n;

	FOR (i, 0, n - 1) {
		cin >> type[i];
		if (type[i] == 'V') {
			curIndV++;

			int z;
			cin >> z;
			FOR (j, 1, z) {
				string s;

				cin >> s;

				if (!tags.count(s)) {
					tags[s] = tags.size();
				}

				int temp = tags[s];
				ver[curIndV].pb(temp);

				stt[curIndV] = i;
			}
			continue;
		}

		curInd++;

		int z;
		cin >> z;
		FOR (j, 1, z) {
			string s;
			
			cin >> s;

			if (!tags.count(s)) {
				tags[s] = tags.size();
			}

			int temp = tags[s];
			v[curInd].pb(temp);

			contain[temp].pb(curInd);
		}
		oldIndex[curInd].pb(i);
		
	}
}

int cnt[10000005];

int cost(int i, int j) {
	vector<int> V;

	for (auto u: v[i]) {
		cnt[u]++;
		V.pb(u);
	}

	for (auto u: v[j]) {
		cnt[u]++;
		if (cnt[u] == 1) V.pb(u);
	}

	int common = 0;

	for (auto u: V) {
		if (cnt[u] == 2) common++;
		cnt[u] = 0;
	}

	return min(min((int) v[i].size() - common, common), (int) v[j].size() - common);
}



vector<II> adj[MAXN];


int deg[MAXN];

int numCCs = 0;

int dist[MAXN], par[MAXN], used[MAXN];
vector<int> diameter;


void dfs(int a){
	for (auto i: adj[a]) {
		if (!dist[i.second] && !used[i.second]) {
			dist[i.second] = dist[a] + i.first;
			par[i.second] = a;
			dfs(i.second);
		}
	}
}

void findDiameter(int r){

	diameter.clear();

	FOR (i, 0, n - 1) {
		dist[i] = 0;
		par[i] = -1;
	}
	dist[r] = 1;

	dfs(r);

	int ma = 0, root = r;

	FOR (i, 0, n - 1){
		if (dist[i] > ma) {
			ma = dist[i];
			root = i;
		}
	}

	FOR (i, 0, n - 1) {
		dist[i] = 0;
		par[i] = -1;
	}

	dist[root] = 1;

	dfs(root);

	int leaf = root;

	ma = 0;

	FOR (i, 0, n - 1){
		if (dist[i] > ma) {
			ma = dist[i];
			leaf = i;
		}
	}

	int u = leaf;

	while (u != root) {
		diameter.pb(u);
		u = par[u];
	}

	diameter.pb(root);
}

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

void processVer() {
	int ind[MAXN];

	FOR (i, 0, curIndV) ind[i] = i;

	shuffle(ind, ind + curIndV + 1, gen);

	FOR (i, 0, curIndV) {
		if (i % 2 == 0) {
			set<int> S;
			for (auto u: ver[ind[i]]) S.insert(u);
			for (auto u: ver[ind[i + 1]]) S.insert(u);
			
			curInd++;
			for (auto u: S) {
				v[curInd].pb(u);
				contain[u].pb(curInd);
			}
			oldIndex[curInd].pb(stt[ind[i]]);
			oldIndex[curInd].pb(stt[ind[i + 1]]);
		}
	} 

	n = curInd + 1;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	readFile();
	processVer();

	int numEdges = 0;


	FOR (i, 0, 3000) {
		for (auto u: v[i]) {
			for (auto j: contain[u]) {
				if (j >= i) break;
				int val = cost(i, j);

				if (val) {
					numEdges++;
					adj[i].pb(II(val, j));
					adj[j].pb(II(val, i));
				}
			}
		}
	}



	FOR (i, 0, n - 1) {
		sort(all(adj[i]));
		reverse(all(adj[i]));
	}

		
	int ind[MAXN];

	FOR (i, 0, n - 1) ind[i] = i;

	shuffle(ind, ind + n, gen);

	vector<int> ans;

	int res = 0;

	FOR (i, 0, n - 1) {
		if (used[ind[i]]) continue;
		findDiameter(ind[i]);

		for (auto j: diameter) {
			ans.pb(j);
			used[j] = 1;
		}
	}

	FOR (i, 1, ans.size() - 1) {
		res += cost(ans[i], ans[i - 1]);
	}

	cout << res << endl;

	cout << ans.size() << endl;

	for (auto i: ans) {
		for (auto j: oldIndex[i]) cout << j << " "; cout << endl;		
	}

		return 0;
}