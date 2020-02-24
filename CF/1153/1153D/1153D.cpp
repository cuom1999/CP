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

int f[300005];
vector<int> v[300005];
int d[300005];

int numLeaf = 0;

void dfs(int a) {
	if (f[a] == 1) d[a] = INF;
	else d[a] = 0;

	if (!v[a].size()) d[a] = 1, numLeaf++;

	for (auto i: v[a]) {
		dfs(i);
		if (f[a] == 1) {
			// if (a == 1) {
			// 	cout << a << " " << d[a] << " " << i << " " << d[i] << endl;
			// }
			d[a] = min(d[a], d[i]);
		}
		else {
			d[a] += d[i];
		}
	}
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> f[i];

    FOR (i, 1, n - 1) {
    	int x;
    	cin >> x;
    	v[x].pb(i + 1);
    } 
    dfs(1);
    // cout << d[1] << endl;
    cout << numLeaf + 1 - d[1] << endl;

	
    return 0;
}