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

ll in[100005], out[100005];
struct Data {
    int x, y;
    ll c;
};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        in[x] += c;
        out[y] += c;
    }

    FOR (x, 1, n) {
        ll val = min(in[x], out[x]);
        in[x] -= val;
        out[x] -= val;
    }

    int j = 1;
    vector<Data> res;
    FOR (i, 1, n) {
        while (in[i]) {
            while (j <= n && !out[j]) j++;
            if (j == n + 1) break;
            ll val = min(out[j], in[i]);
            in[i] -= val;
            out[j] -= val;
            if (val) res.pb({i, j, val});
        }
    }

    cout << res.size() << "\n";
    for (auto i: res) {
        cout << i.x << " " << i.y << " " << i.c << "\n";
    }


    return 0;
}