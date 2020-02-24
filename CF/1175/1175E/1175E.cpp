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

int anc[500005], p[500005][20], root[500005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int MAX_X = 500000;
	int n, m;
	cin >> n >> m;

	FOR (i, 0, MAX_X) anc[i] = i;

	FOR (i, 1, n) {
		int l, r;
		cin >> l >> r;
		anc[l] = max(anc[l], r);
	}

	FOR (i, 1, MAX_X) {
		anc[i] = max(anc[i], anc[i - 1]);
	}

	FOR (i, 0, 19) p[MAX_X + 1][i] = MAX_X + 1;

	FORD (i, MAX_X, 0) {
		p[i][0] = anc[i];
		if (anc[i] == i) {
			root[i] = i;
			p[i][0] = MAX_X + 1;
		}
		else {
			root[i] = root[anc[i]];
		}
	}

	FOR (j, 1, 19) {
		FOR (i, 0, MAX_X) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}

	FOR (z, 1, m) {
		int x, y;
		cin >> x >> y;
		// cout << x << " " << root[x] << endl;

		if (y > root[x]) {
			cout << -1 << endl;
		}
		else {
			int res = 0;
			int cur = x;
			while (cur != y) {

				FOR (i, 0, 19) {
					if (p[cur][i] == y) {
						res += (1 << i);
						cur = y;
						break;
					}
					else if (p[cur][i] > y) {
						if (i) {
							res += (1 << (i - 1));
							cur = p[cur][i - 1];
						}
						else {
							res++;
							cur = y;
						}
						break;
					}
				}
			}
			cout << res << endl;
		}
	}


	return 0;
}