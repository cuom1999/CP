// Link : https://www.hackerrank.com/challenges/cat-jogging/problem

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
typedef pair < ll, ll > pll;

const int MAXN = 50005;
vector<int> v[MAXN];
vector<int> tmp[MAXN];
vector<II> degAndVer;
int visited[MAXN], marked[MAXN];

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

	FOR (i, 1, n) {
		degAndVer.pb({v[i].size(), i});
	}

	sort(all(degAndVer));
	reverse(all(degAndVer));

	ll res = 0;

	for (auto p: degAndVer) {
		int i = p.second;

		vector<int> tmpList;

		for (auto j: v[i]) {
			if (visited[j]) continue;
			for (auto u: v[j]) {
				if (u == i || visited[u]) continue;
				tmp[u].pb(j);
				if (!marked[u]) {
					marked[u] = 1;
					tmpList.pb(u);
				}
			}
		}

		for (auto u: tmpList) {
			if (tmp[u].size() >= 2) {
				res += tmp[u].size() * 1ll * (tmp[u].size() - 1) / 2;
			}
			tmp[u].clear();
			marked[u] = 0;
		}
		tmpList.clear();

		visited[i] = 1;
	}
	cout << res << endl;


	return 0;
}