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

ll a[200005], cnt[200005];
map<II, int> d;

ll res = 0;

void remove(int u) {
    cnt[u]--;
    res++;
    if (cnt[u] >= a[u]) res--;
}
void add(int u) {
    cnt[u]++;
    res--;
    if (cnt[u] > a[u]) res++;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        res += a[i];
    }

    int q;
    cin >> q;
    FOR (z, 1, q) {
        int s, t, u;
        cin >> s >> t >> u;
        int v = d[{s, t}];
        if (v && u) {
            remove(v);
            add(u);
        }
        else if (u) {
            add(u);
        }
        else if (v) {
            remove(v);
        }
        d[{s, t}] = u;
        // FOR (i, 1, n) cout << cnt[i] << " "; cout << endl;
        cout << res << endl;
    }

    return 0;
}