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

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree<II,null_type,less<II>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;




int main()
{IN;
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

    vector<II> v;
    FOR (i, 1, n) {
        v.pb({a[i], i});
    }

    sort(all(v), [](II a, II b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    int q;
    cin >> q;

    vector<II> queries[200005];
    FOR (z, 1, q) {
        int len, pos;
        cin >> len >> pos;
        queries[len].pb({z, pos});
    }

    vector<int> res(q + 1);
    IndexTree s;
    FOR (len, 1, n) {
        s.insert({v[len - 1].second, v[len - 1].first});
        for (auto qq: queries[len]) {
            II val = *s.find_by_order(qq.second - 1);
            res[qq.first] = val.second;
        }
    }

    FOR (i, 1, q) cout << res[i] << "\n";



    return 0;
}