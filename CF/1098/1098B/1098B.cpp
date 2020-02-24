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

vector<char> a[300005];
vector<char> trace[300005];
int n, m;
    
int solveR(char x, char y, char z, char t) {
	int ans = 0;
	FOR (i, 1, n) {
		char a1, a2;
		if (i % 2 == 1) {
			a1 = x;
			a2 = y;
			int res = 0;
			FOR (j, 1, m) {
				if (a[i][j] != a1 && j % 2 == 1) res++;
				if (a[i][j] != a2 && j % 2 == 0) res++;
			}
			int res1 = 0;
			FOR (j, 1, m) {
				if (a[i][j] != a1 && j % 2 == 0) res1++;
				if (a[i][j] != a2 && j % 2 == 1) res1++;
			}
			ans += min(res, res1);
			if (res < res1) {
				FOR (j, 1, m) {
					if (j % 2 == 1) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
			else {
				FOR (j, 1, m) {
					if (j % 2 == 0) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
		}
		else {
			a1 = z;
			a2 = t;
			int res = 0;
			FOR (j, 1, m) {
				if (a[i][j] != a1 && j % 2 == 1) res++;
				if (a[i][j] != a2 && j % 2 == 0) res++;
			}
			int res1 = 0;
			FOR (j, 1, m) {
				if (a[i][j] != a1 && j % 2 == 0) res1++;
				if (a[i][j] != a2 && j % 2 == 1) res1++;
			}
			ans += min(res, res1);
			if (res < res1) {
				FOR (j, 1, m) {
					if (j % 2 == 1) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
			else {
				FOR (j, 1, m) {
					if (j % 2 == 0) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
		}
    }
    return ans;
}

int solveC(char x, char y, char z, char t) {
	int ans = 0;
	FOR (j, 1, m) {
		char a1, a2;
		if (j % 2 == 1) {
			a1 = x;
			a2 = y;
			int res = 0;
			FOR (i, 1, n) {
				if (a[i][j] != a1 && i % 2 == 1) res++;
				if (a[i][j] != a2 && i % 2 == 0) res++;
			}
			int res1 = 0;
			FOR (i, 1, n) {
				if (a[i][j] != a1 && i % 2 == 0) res1++;
				if (a[i][j] != a2 && i % 2 == 1) res1++;
			}
			ans += min(res, res1);
			if (res < res1) {
				FOR (i, 1, n) {
					if (i % 2 == 1) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
			else {
				FOR (i, 1, n) {
					if (i % 2 == 0) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
		}
		else {
			a1 = z;
			a2 = t;
			int res = 0;
			FOR (i, 1, n) {
				if (a[i][j] != a1 && i % 2 == 1) res++;
				if (a[i][j] != a2 && i % 2 == 0) res++;
			}
			int res1 = 0;
			FOR (i, 1, n) {
				if (a[i][j] != a1 && i % 2 == 0) res1++;
				if (a[i][j] != a2 && i % 2 == 1) res1++;
			}
			ans += min(res, res1);
			if (res < res1) {
				FOR (i, 1, n) {
					if (i % 2 == 1) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
			else {
				FOR (i, 1, n) {
					if (i % 2 == 0) trace[i][j] = a1;
					else trace[i][j] = a2;
				}	
			}
		}
    }
    return ans;
}

void printRes() {
	FOR (i, 1, n) {
		FOR (j, 1, m) cout << trace[i][j];
		cout << endl;
	}
}

vector<char> tableRes[300005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    
    FOR (i, 1, n) {
    	a[i].resize(m + 1);
    	trace[i].resize(m + 1);
    	tableRes[i].resize(m + 1);
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) cin >> a[i][j];
    }
    int res = INF;
    int u = solveC('A', 'C', 'G', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveC('A', 'T', 'G', 'C'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveC('A', 'G', 'C', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveC('G', 'C', 'A', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveC('G', 'T', 'A', 'C'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveC('T', 'C', 'G', 'A'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('A', 'C', 'G', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('A', 'T', 'G', 'C'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('A', 'G', 'C', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('G', 'C', 'A', 'T'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('G', 'T', 'A', 'C'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }
    u = solveR('T', 'C', 'G', 'A'); 
    if (res > u) {
    	res = u;
    	FOR (i, 1, n) tableRes[i] = trace[i];
    }	
    //cout << res << endl;
    FOR (i, 1, n) {
    	FOR (j, 1, m) cout << tableRes[i][j];
    	cout << endl;
    }
    return 0;
}