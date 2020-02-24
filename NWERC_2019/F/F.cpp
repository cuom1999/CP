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


map<int, vector<int>> v;
struct Edge {
    int x, y, c;
};

int lab[200005];

int getRoot(int a) {
    while (lab[a] >= 0) a = lab[a];
    return a;
}

void dsu(int x, int y) {
    if (lab[x] > lab[y]) swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        int m;
        cin >> m;

        FOR (j, 1, m) {
            int x;
            cin >> x;
            v[x].pb(i);
        }
    }

    vector<Edge> edges;

    for (auto &i: v) {
        for (int j = 0; j + 1 < i.second.size(); j++) {
            edges.pb({i.second[j], i.second[j + 1], i.first});
        }
    }

    FOR (i, 1, n) lab[i] = -1;
    vector<Edge> res;

    for (auto e: edges) {
        int a = getRoot(e.x);
        int b = getRoot(e.y);
        if (a == b) continue;
        dsu(a, b);
        res.pb(e);
    }
    if (res.size() < n - 1) {
        cout << "impossible";
        return 0;
    }
    for (auto e: res) {
        cout << e.x << " " << e.y << " " << e.c << "\n";
    }

    return 0;
}