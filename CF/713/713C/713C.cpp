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

int median(IndexTree& s) {
    int n = s.size();
    assert(n);
    return (*s.find_by_order((n - 1) / 2)).first;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] -= i;
    }

    vector<int> opt(n + 1);
    vector<IndexTree> v;
    IndexTree s;
    FOR (i, 1, n) {
        IndexTree tree;
        tree.insert(II(a[i], i));
        v.pb(tree);
        while (v.size() >= 2) {
            IndexTree& t1 = v.back();
            IndexTree& t2 = v[v.size() - 2];
            if (median(t1) < median(t2)) {
                if (t1.size() > t2.size()) {
                    swap(t1, t2);
                }
                for (auto i: t1) {
                    t2.insert(i);
                } 
                v.pop_back();
            }
            else break;
        }
        opt[i] = median(v.back());
    }

    vector<int> res(n + 1);
    res[n] = opt[n];
    FORD (i, n - 1, 1) {
        res[i] = min(res[i + 1], opt[i]);
    }

    ll cost = 0;
    FOR (i, 1, n) {
        cost += abs(res[i] - a[i]);
    }
    cout << cost << endl;

    return 0;
}