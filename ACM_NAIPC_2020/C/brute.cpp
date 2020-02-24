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


struct Circle {
    ll x, y, r;
    int index;
} circle[200005];


int p[200005];
vector<int> adj[200005];
int res[200005][3];
// 0: not take this
// 1: take this 
int n, q;
    
void dfs(int a) {
    for (auto i: adj[a]) {
        dfs(i);
    }

    if (a <= n) {
        res[a][1] = 1;
    }
    for (auto i: adj[a]) {
        if (i <= n) {
            res[a][0] += max(res[i][0], res[i][1]);
            res[a][1] += res[i][0];
        }
        else {
            res[a][0] += max(res[i][0], res[i][1]);
            res[a][1] += res[i][1];
        }
    }
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> q;

    FOR (i, 1, n) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
        circle[i].index = i;
    }

    FOR (i, 1, q) {
        cin >> circle[i + n].x >> circle[i + n].y >> circle[i + n].r;
        circle[i + n].index = i + n;
    }

    FOR (i, 1, n + q) {
        int index = 0;
        int minVal = INF;
        FOR (j, 1, n + q) {
            if (j == i) continue;
            if (sq(circle[i].x - circle[j].x) + sq(circle[i].y - circle[j].y) < sq(circle[i].r + circle[j].r)
                && circle[i].r < circle[j].r) {
                if (minVal > circle[j].r) {
                    minVal = circle[j].r;
                    index = j;
                }
            }
        }
        p[i] = index;
    }

    FOR (i, 1, n + q) {
        adj[p[i]].pb(i);
    }

    dfs(0);

    FOR (i, 1, q) {
        cout << max(res[i + n][0], res[i + n][1] + 1) << "\n";
    }

    return 0;
}