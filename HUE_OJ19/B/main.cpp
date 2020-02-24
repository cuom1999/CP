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
typedef pair < int, int > II;

const int MAXN = 1000004;

vector<II> v[MAXN];

int vs[1000005];
int n, m;

void dfs(int a, int x) {
	vs[a] = 1;
	for (auto i: v[a]) {
		if (i.second <= x && !vs[i.first]) dfs(i.first, x);
	}
}

bool solve(int x) {
	FOR (i, 1, n) vs[i] = 0;

	dfs(1, x);

	FOR (i, 1, n) {
		if (!vs[i]) return 0;
	}

	return 1;
}

int lab[MAXN];

int getRoot(int a) {
	while (lab[a] >= 0) a = lab[a];
	return a;
}

void dsu(int a, int b) {
	int x = lab[a] + lab[b];
	if (lab[a] < lab[b]) {
		lab[b] = x;
		lab[a] = b;
	}
	else {
		lab[a] = x;
		lab[b] = a;
	}
}

struct Edge {
	int x, y, c;
	Edge(int __x = 0, int __y = 0, int __c = 0): x(__x), y(__y), c(__c) {}

	bool operator < (const Edge &a) {
		return c < a.c;
	}
};

vector<Edge> e;

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    while (1) {
    	//cin >> n >> m;
    	sf("%d%d", &n, &m);
    	if (n == 0 && m == 0) return 0;

    	if (m < n - 1) {
    		printf("IMPOSSIBLE\n");
    		continue;
    	}

    	FOR (i, 1, n) {
    		//v[i].clear();
    		lab[i] = -1;
    	}

    	e.clear();

    	FOR (i, 1, m) {
    		int x, y, c;
    		//cin >> x >> y >> c;
    		sf("%d%d%d", &x, &y, &c);
    		x++;
    		y++;
    		//v[x].pb(II(y, c));
    		//v[y].pb(II(x, c));
    		e.pb(Edge(x, y, c));
    	}

    	sort(all(e));

    	int res = -1;

    	for (auto i: e) {
    		int a = getRoot(i.x);
    		int b = getRoot(i.y);

    		if (a == b) continue; 
    		else dsu(a, b);

    		if (lab[a] == -n || lab[b] == -n) {
    			res = i.c;
    			break;
    		}
    	}


    	if (res == -1) printf("IMPOSSIBLE\n");
    	else printf("%d\n", res); 
    }
	    
	
    return 0;
}