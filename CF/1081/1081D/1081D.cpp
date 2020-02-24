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

int special[100005], lab[100005];

struct Edge {
    int x, y, c;
    bool operator < (const Edge& e) {
        return c < e.c;
    }
};

int getRoot(int a) {
    while (lab[a] >= 0) a = lab[a];
    return a;
}

void dsu(int a, int b) {
    if (lab[a] > lab[b]) swap(a, b);
    lab[a] += lab[b];
    special[a] += special[b];
    lab[b] = a;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    FOR (i, 1, k) {
        int x;
        cin >> x;
        special[x] = 1;
    }

    vector<Edge> edges;
    FOR (i, 1, m) {
        int x, y, c;
        cin >> x >> y >> c;
        edges.pb({x, y, c});
    }   

    sort(all(edges));
    memset(lab, -1, sizeof(lab));

    int res;
    for (auto i: edges) {
        int a = getRoot(i.x);
        int b = getRoot(i.y);
        if (a == b) continue;
        dsu(a, b);
        if (special[a] == k || special[b] == k) {
            res = i.c;
            break;
        }
    }

    FOR (i, 1, k) {
        cout << res << " ";
    }

    return 0;
}