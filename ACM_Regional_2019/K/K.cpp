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
typedef pair < ll, ll > pll;

struct Node {
    vector<int> vec;
    int i, j;
};
map<vector<int>, vector<Node>> adj;
map<vector<int>, int> d;
map<vector<int>, II> par;

vector<II> res;

void init(int n) {
    vector<int> p(n + 1);
    FOR (i, 1, n) p[i] = i;
    do {
        FOR (i, 1, n) {
            FOR (j, i + 1, n) {
                vector<int> tmp = p;
                int c1 = 0, c2 = 0;
                FOR (k, i, j - 1) {
                    if (p[k + 1] > p[k]) c1++;
                    if (p[k + 1] < p[k]) c2++;
                }
                if (!c1 || !c2) {
                    reverse(tmp.begin() + i, tmp.begin() + j + 1);
                    adj[p].pb({tmp, i, j});
                }
            }
        }
    } while (next_permutation(p.begin() + 1, p.end()));
}

void bfs(int n) {
    vector<int> root(n + 1);
    FOR (i, 1, n) root[i] = i;

    queue<vector<int>> q;
    q.push(root);
    d[root] = 1;
    while (q.size()) {
        auto v = q.front();
        q.pop();

        for (auto &u: adj[v]) {
            if (!d[u.vec]) {
                d[u.vec] = d[v] + 1;
                q.push(u.vec);
                par[u.vec] = {u.i, u.j};
            }
        }
    }
}

void solveSmall(vector<int>& a) {
    int n = a.size();
    n--;
    init(n);
    bfs(n);
    vector<int> p(n + 1);
    FOR (i, 1, n) p[i] = i;

    while (a != p) {
        II u = par[a];        
        res.pb(u);
        reverse(a.begin() + u.first, a.begin() + u.second + 1);
    }
}

void solveLarge(vector<int>& a) {
    int n = a.size();
    n--;
    vector<int> b(9);
    vector<II> tmp;
    FOR (i, 1, 8) {
        tmp.pb({a[i], i});
    }
    sort(all(tmp));
    FOR (i, 0, 7) {
        b[tmp[i].second] = i + 1;
    }
    solveSmall(b);

    sort(a.begin() + 1, a.begin() + 9);

    FOR (i, 9, n) {
        int index = i;
        FOR (j, 1, i - 1) {
            if (a[j] > a[i]) {
                index = j;
                break;
            }
        }
        if (index == i) continue;
        res.pb({index, i - 1});
        res.pb({index, i});
        sort(a.begin() + 1, a.begin() + i + 1);
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR (i, 1, n) {
        int x;
        cin >> x;
        a[i] = x;
    }

    if (n <= 8) {
        solveSmall(a);
    }
    else {
        solveLarge(a);
    }

    cout << res.size() << "\n";
    for (auto i: res) cout << i.first << " " << i.second << "\n";

    return 0;
}