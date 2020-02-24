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

int n;
int A[200005];
int comp[200005];
vector<int> primeDiv[200005], v[200005];
int h[200005];

void dfs1(int a, int p){
	h[a] = h[p] + 1;
	for (auto i: v[a]) {
		if (i != p) dfs1(i, a);
	}
}

int m[200005][10];
int res = 0;
int dd[200005];
int M1[10], M2[10];

void dfs(int a, int p) {
	for (auto i: v[a]) {
		if (i != p) dfs(i, a);
	}
	int C = 0;
	for (auto i: primeDiv[A[a]]) {
		m[a][C] = h[a];
		M1[C] = M2[C] = h[a];
		dd[i] = C++;
	}

	for (auto i: v[a]) {
		if (i != p) {
			for (int j = 0; j < primeDiv[A[i]].size(); j++) {
				int u = primeDiv[A[i]][j];
				//cout << u << " " << a << " " << dd[u] << endl;
				if (dd[u] == -1) continue;
				if (M1[dd[u]] < m[i][j]) {
					M1[dd[u]] = m[i][j];
					if (M1[dd[u]] > M2[dd[u]]) swap(M1[dd[u]], M2[dd[u]]);
				}
			} 
		}
	}

	for(int i = 0; i < primeDiv[A[a]].size(); i++) {
		res = max(res, M1[i] + M2[i] - 2 * h[a] + 1);
	}
	//if (a == 1) cout << M1[0] << " " << M2[0] << " " << m[3][0] << endl;

	for (auto i: v[a]) {
		if (i != p) {
			for (int j = 0; j < primeDiv[A[i]].size(); j++) {
				int u = primeDiv[A[i]][j];
				//cout << a << " " << u << " " << dd[u] << endl;
				if (dd[u] == -1) continue;
				m[a][dd[u]] = max(m[a][dd[u]], m[i][j]);
			} 
		}
	}
	C = 0;

	for (auto i: primeDiv[A[a]]) {
		M1[C] = M2[C] = 0;
		dd[i] = -1;
	}
	/*
	cout << a << ": ";
	for (int i = 0; i < primeDiv[A[a]].size(); i++) {
		cout << primeDiv[A[a]][i] << "," << m[a][i] << " ";
	}

	cout << endl;
	*/

}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 2, 200000) {
    	if (!comp[i]) {
    		FOR (j, 1, 200000 / i) {
    			primeDiv[i * j].pb(i);
    			comp[i * j] = 1;
    		}
    	}
    	dd[i] = -1;
    }


    cin >> n;
    FOR (i, 1, n) {
    	 cin >> A[i];
    }

    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    dfs1(1, 0);
    dfs(1, 0);
    cout << res << endl;

    
	
    return 0;
}