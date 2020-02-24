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

const int MAXN = 100005;

vector<int> v[MAXN];
const ll K = 1e9 + 7;

ll d[MAXN][2];

void dfs(int a, int p) {

	for (auto i: v[a]) {
		if (i == p) continue;
		dfs(i, a);
	}
	
	d[a][0] = d[a][1] = 1;

	for (auto i: v[a]) {
		if (i == p) continue;
		d[a][0] = d[a][0] * (d[i][0] + d[i][1]) % K;
		d[a][1] = d[a][1] * d[i][0] % K; 
	}
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }

    dfs(1, 0);

    cout << (d[1][0] + d[1][1]) % K << endl;

    return 0;
}