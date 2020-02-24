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

int n, k;
int a[505];

II ask(vector<int>& v) {
    cout << "? ";
    for (auto i: v) cout << i << " ";
    cout << endl;
    int u, v1;
    cin >> u >> v1;
    return {u, v1};
}

void ans(int m) {
    cout << "! " << m << endl; 
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;

    vector<int> known, remain;
    set<int> toAsk;

    FOR (i, 1, k) {
        toAsk.insert(i);
    }

    FOR (i, 1, n - k + 1) {
        vector<int> v;
        for (auto j: toAsk) v.pb(j);
        II ans = ask(v);
        a[ans.first] = ans.second;
        known.pb(ans.first);
        toAsk.erase(ans.first);
        if (i + k <= n) toAsk.insert(i + k);
    }

    for (auto i: toAsk) remain.pb(i);
    int u = known[0], v = known[1];
    if (a[u] > a[v]) swap(u, v);

    int res = 0;
    for (auto i: remain) {
        vector<int> askNow;
        askNow.pb(u);
        askNow.pb(v);
        for (auto j: remain) {
            if (j != i) askNow.pb(j);
        }

        II m = ask(askNow);
        if (m.first == v) res++; 
    }
    ans(res + 1);

    return 0;
}