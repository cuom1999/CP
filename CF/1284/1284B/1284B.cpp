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

bool isDec(vector<int>& a) {
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] < a[i + 1]) return 0;
    }
    return 1;
}

ll fen[1000005];

void add(int u, int v) {
    for (int i = u; i <= 1000003; i += i & -i) {
        fen[i] += v;
    }
}

ll getSum(int u) {
    ll res = 0;
    for (int i = u; i; i -= i & -i) {
        res += fen[i];
    }
    return res;
}

ll cnt[1000005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<II> allPairs;
    FOR (i, 1, n) {
        int m;
        cin >> m;
        vector<int> v;
        FOR (j, 1, m) {
            int x;
            cin >> x;
            x++;
            v.pb(x);
        }

        if (isDec(v)) {
            allPairs.pb({v.back(), v[0]});
        }
    }

    sort(all(allPairs));
    ll res = 0;

    for (auto i: allPairs) {
        add(i.second, 1);
        res += getSum(i.first);
        if (i.first == i.second) {
            cnt[i.first]++;
        }
    }

    FOR (i, 1, 1000001) {
        res += cnt[i] * 1ll * (cnt[i] - 1) / 2;
    }

    res = n * 1ll * n - res;
    cout << res << endl;

    return 0;
}