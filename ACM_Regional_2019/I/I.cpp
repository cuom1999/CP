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

vector<int> st[4005];
vector<int> query[35];
bool ans[1005][35];
int n;
int q = 0;

void init(int l, int r, int level) {
    if (l == r) return;
    q = max(q, level);
    int mid = (l + r) / 2;

    FOR (i, l, mid) query[level].pb(i);
    init(l, mid, level + 1);
    init(mid + 1, r, level + 1);
}

int p[1005];

void solve(int id, int l, int r, int level) {
    if (l == r) {
        p[st[id][0]] = l;
        return;
    }
    int mid = (l + r) / 2;
    for (auto i: st[id]) {
        if (ans[i][level]) {
            st[id * 2].pb(i);
        }
        else {
            st[id * 2 + 1].pb(i);
        }
    }
    solve(id * 2, l, mid, level + 1);
    solve(id * 2 + 1, mid + 1, r, level + 1);
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    init(1, n, 1);
    FOR (i, 1, q) {
        cout << "ASK ";
        cout << query[i].size() << " ";
        for (auto j: query[i]) cout << j << " ";
        cout << endl;
        FOR (j, 1, query[i].size()) {
            int x;
            cin >> x;
            ans[x][i] = 1;
        }
    }
    FOR (i, 1, n) st[1].pb(i);
    solve(1, 1, n, 1);

    cout << "ANSWER ";
    FOR (i, 1, n) cout << p[i] << " "; cout << endl;

    return 0;
}