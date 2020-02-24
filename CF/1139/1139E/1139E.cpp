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

int match[5004],vs[5005];
vector<int> v[5005];

bool findPath(int u, int t){
	// cout << u << " " << t << endl;
	if (vs[u] != t){
		vs[u] = t;
	}
	else return 0;

	for (auto i: v[u]){
		if (!match[i] || findPath(match[i], t)) {
			match[i] = u;
			return 1;
		}
	}
	return 0;
}

int biMatching (int m, int n) {
	FOR (i, 1, max(m,n)) match[i] = vs[i] = 0;
	int cnt = 0;

	FOR (i, 1, m){
		if (!findPath(i, i)) return i - 1;
	}

	return m;
}

int cnt[5005][5005];
int n, m;
int p[5005], c[5005];


int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> m;

	FOR (i, 1, n) {
		cin >> p[i];
	}

	FOR (i, 1, n) {
		cin >> c[i];
	}

	FOR (i, 1, n) {
		cnt[c[i]][p[i]]++;
		if (cnt[c[i]][p[i]] == 1) {
			v[p[i] + 1].pb(c[i]);
		} 
	}


	int res = biMatching(m, m);


	int d;
	cin >> d;


	FOR (z, 1, d) {
		int x;
		cin >> x;

		cnt[c[x]][p[x]]--;

		if (cnt[c[x]][p[x]] || p[x] > res) {
			cout << res << endl;
			continue;
		}
		else {
			for (int i = 0; i < v[p[x] + 1].size(); i++) {
				if (v[p[x] + 1][i] == c[x]) {
					v[p[x] + 1].erase(v[p[x] + 1].begin() + i);
					break;
				}
			}

			int a = p[x] + 1, b = c[x];
			if (match[b] != a) {
				cout << res << endl;
				continue;
			}

			match[b] = 0;

			FOR (i, 1, m) {
				if (match[i] && match[i] >= a) match[i] = 0;
			}

			// FOR (i, 1, m) cout << match[i] << " "; cout << endl;
			FOR (i, 0, res) vs[i] = 0;

			FOR (i, a, res) {
				vs[i] = 0;
				if (!findPath(i, i)) {
					res = i - 1;
					break;
				}
			}

			//FOR (i, 1, 3) cout << match[i] << " "; cout << endl;

			cout << res << endl;
		}
	}
	
	return 0;
}