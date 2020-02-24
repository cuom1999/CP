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

// cout << "Case " << z << ": ";

bool vs[21][21];

int m, n;

bool check(int x, int y, int u, int v) {
	return ((x != u) && (y != v) && (x + y != u + v) && (x - y != u - v));
}

vector<II> ans;

bool solve(int x, int y, int c) {
	int res = 0;
	if (c == m * n) return 1;
	FOR (i, 1, m) {
		FOR (j, 1, n) {
			if (vs[i][j]) continue;
			if (check(x, y, i, j)) {
				vs[x][y] = 1;
				res |= solve(i, j, c + 1);
				if (res) {
					ans.pb(II(i, j));
					return 1;
				}
				vs[x][y] = 0;
			}
		}
	}
	return 0;
}
int ind[21][21];

void fill2(int r) {
	int cnt = 1;
	memset(ind, 0, sizeof(ind));

	FOR (i, 3, n) {
		ind[r + 1][i] = cnt;
		cnt += 2;
	}
	cnt = 2;
	FOR (i, 1, n - 2) {
		ind[r][i] = cnt;
		cnt += 2;
	}

	ind[r + 1][1] = cnt - 1;
	ind[r][n - 1] = cnt;
	ind[r + 1][2] = cnt + 1;
	ind[r][n] = cnt + 2;

	vector<III> v;

	FOR (i, r, r + 1) {
		FOR (j, 1, n) v.pb({ind[i][j], {i, j}});
	}

	sort(all(v));
	for (auto i: v) ans.pb(i.second);
}

void fill3(int r) {
	int cnt = 1;
	memset(ind, 0, sizeof(ind));

	FOR (i, 1, (n + 1) / 2) {
		ind[r][i] = cnt;
		cnt += 2;
	}

	cnt = 2;
	FOR (i, n / 2 + 1, n) {
		ind[r + 1][i] = cnt;
		cnt += 2;
	}

	cnt -= 1;
	int old = cnt;

	FOR (i, n / 2 + 1, n) {
		ind[r + 2][i] = cnt;
		cnt += 2;
	}

	cnt = old + 1;
	FOR (i, 1, n / 2) {
		ind[r + 1][i] = cnt;
		cnt += 2;
	}

	if (n % 2 == 1) {
		cnt--;
		old = cnt;
		cnt += 2;
		FOR (i, 1, n / 2) {
			ind[r + 2][i] = cnt;
			cnt += 2;
		}

		cnt = old + 1;

		FOR (i, (n + 1) / 2 + 1, n) {
			ind[r][i] = cnt;
			cnt += 2; 
		}
	}
	else {
		cnt--;
		old = cnt;
		cnt += 2;
		FOR (i, 1, n / 2) {
			ind[r + 2][i] = cnt;
			cnt += 2;
		}

		cnt = old + 3;

		FOR (i, (n + 1) / 2 + 1, n) {
			ind[r][i] = cnt;
			cnt += 2; 
		}
	}

	vector<III> v;

	FOR (i, r, r + 2) {
		FOR (j, 1, n) {
			v.pb({ind[i][j], {i, j}});
			// cout << ind[i][j] << " ";
		}
		// cout << endl;
	}

	sort(all(v));
	for (auto i: v) ans.pb(i.second);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
    	//cout << "Case #" << z << ": ";
		
		cin >> m >> n;
	    ans.clear();
	    
	    if (m <= 7 && n <= 7) {
	    	memset(vs, 0, sizeof(vs));
	    
	    	bool done = 0;

	    	FOR (i, 1, m) {
	    		FOR (j, 1, n) {
	    			memset(vs, 0, sizeof(vs));
	    			ans.clear();
	    			if (solve(i, j, 1)) {
	    				ans.pb(II(i, j));
	    				reverse(all(ans));
	    				done = 1;
	    				break;
	    			}
	    		}
	    		if (done) break;
	    	}
	    	if (!done) {
	    		cout << "IMPOSSIBLE" << endl;
	    	}
	    	else {
	    		cout << "POSSIBLE" << endl;
	    		for (auto i: ans) cout << i.first << " " << i.second << endl;
	    	}
	    	continue;
	    }

	    cout << "POSSIBLE" << endl;

	    bool swapped = 0;

	    if (n <= 7) {
	    	swap(m, n);
	    	swapped = 1;
	    }



	    if (m % 2) {
	    	for (int i = 1; i <= m - 3; i += 2) {
	    		fill2(i);
	    	}
	    	fill3(m - 2);
	    }
	    else {
	    	for (int i = 1; i <= m - 1; i += 2) {
	    		fill2(i);
	    	}
	    }
 
 		assert(ans.size() == m * n);
	    if (swapped) {
	    	for (auto i: ans) {
	    		cout << i.second << " " << i.first << endl;
	    	}
	    }
	    else {
	    	for (auto i: ans) {
	    		cout << i.first << " " << i.second << endl;
	    	}
	    }
	}
    
    return 0;
}
