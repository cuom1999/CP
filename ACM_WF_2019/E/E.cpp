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


const int N = 500005;
int n, m;
vector<int> v[N];
int CriticalEdge=0;
bool CriticalNode[N];
int num[N], low[N], Time=0;
vector<II> res;
int rev[N];
vector<III> v2[N];

// visit 1 first
void visit(int u, int p) {
    int NumChild = 0;
    low[u] = num[u] = ++Time;
    rev[Time] = u;
    for (auto i: v[u]){
        if (i != p) {
            if (num[i])
                low[u] = min(low[u], num[i]);
            else {
                visit(i, u);
                NumChild++;
                low[u] = min(low[u], low[i]);

                if (low[i] > num[u]) {
                    // CriticalEdge++; /// Bridge
                	// s[i].insert(u);
                	// s[u].insert(i);
                	v2[low[i]].pb(III(low[u], II(i, u)));
                	v2[low[u]].pb(III(low[i], II(u, i)));
                }
            }
        }
    }
}

int vs[N];

vector<int> cc[N];

void dfs(int a, int c) {
	vs[a] = 1;
	cc[c].pb(a);
	for (auto i: v2[a]) {
		if (!vs[i.first]) {
			dfs(i.first, c);
		}
	}
}

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
    	if (!num[i]) visit(i, 0);
    }

    int c = 0;
    FOR (i, 1, n) {
    	if (!vs[low[i]]) {
    		dfs(low[i], ++c);
    	}
    }

    FOR (i, 1, c) {
    	for (auto j: cc[i]) {
    		if (v2[j].size() > 1) {
    			for (auto k: v2[j]) {
    				res.pb(k.second);
    			}
    			break;
    		}
    	}
    }


    sort(all(res));

    cout << res.size() << endl;

	

    return 0;
}