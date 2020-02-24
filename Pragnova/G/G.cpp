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

int vs[100005];
int t[100005];
int c = 0;

void dfs(int u) {
    c++;
    vs[u] = 1;
    if (!vs[t[u]]) dfs(t[u]);
}

int main()
{IN; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    // vector<int> p(n + 1);
    // FOR (i, 1, n) p[i] = i;
    // do {
    //     vector<int> v;
    //     FOR (i, 1, n) {
    //         v.pb(p[p[i]]);
    //     }
    //     cnt[v]++;
    // } while (next_permutation(p.begin() + 1, p.begin() + n + 1));

    // for (auto i: cnt) {
    //     for (auto j: i.first) cout << j << " ";
    //     cout << ": " << i.second << endl;
    // }

    FOR (i, 1, n) {
        cin >> t[i];
    }

    vector<int> cnt(n + 1);
    FOR (i, 1, n) {
        if (!vs[i]) {
            c = 0;
            dfs(i);
            cnt[c]++;
        }
    }   

    const ll MOD = 1e9 + 7;

    ll res = 1;
    FOR (i, 1, n) {
        vector<ll> d(cnt[i] + 1);
        d[0] = 1;
        FOR (j, 1, cnt[i]) {
            if (i % 2) d[j] = d[j - 1];
            if (j >= 2) {
                d[j] = (d[j] + d[j - 2] * i % MOD * (j - 1) % MOD) % MOD;
            }
        }
        res = res * d[cnt[i]] % MOD;
    }

    cout << res << endl;
    return 0;
}