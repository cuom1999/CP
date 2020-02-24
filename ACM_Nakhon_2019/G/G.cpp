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

const int N=205;

struct Tarjan {

    vector<int> v[N];

    vector<int> num;
    vector<int> low;
    vector<int> vs;
    int TIME,res;
    vector<int> SCC[N], STACK;

    Tarjan() {
        num.resize(N);
        low.resize(N);
        vs.resize(N);
        res = TIME = 0;
    }
    
    void dfs(int a){
        low[a]=num[a]=++TIME;
        STACK.pb(a);
        for (auto i:v[a]){
            if (!num[i]) dfs(i);
            if (!vs[i]) low[a]=min(low[a],low[i]);
        }

        if (num[a]==low[a]) {
            res++;
            while (STACK.size()){
                int b=STACK.back(); SCC[res].pb(b);
                STACK.pop_back();
                vs[b]=1;
                if (b==a) break;
            }
        }
    }
};


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        Tarjan tarjan;
        int m;
        cin >> m;

        FOR (i, 1, m) {
            int u, v1;
            cin >> u >> v1;
            tarjan.v[u + 1].pb(v1 + 1);
        }
        FOR (i, 1, n) {
            if (!tarjan.num[i]) {
                tarjan.dfs(i);
            }
        }
        cout << tarjan.res << "\n";
    }
 


    return 0;
}