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

struct Data {
    int l, r;
};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<II> v;
    vector<Data> data(n + 1);
    FOR (i, 1, n) {
        int l1;
        int r1;
        cin >> l1 >> r1;
        v.pb({l1, -i});
        v.pb({r1, i});
    }

    sort(all(v));

    int curr = 0;

    for (int i = 0; i < v.size(); i++) {
        if (!i || v[i].first != v[i - 1].first) {
            curr++;
        }

        if (v[i].second < 0) {
            data[-v[i].second].l = curr;
        }
        else data[v[i].second].r = curr;
    }

    sort(all(data), [&](const Data& a, const Data& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    });

    vector<int> color(n * 2 + 5);

    FOR (i, 1, n) {
        FOR (j, data[i].l, data[i].r - 1) {
            color[j] = i;
        }
        // FOR (i, 1, 2 * n) {
        //     cout << color[i] << " ";
        // }
        // cout << endl;

    }

    // FOR (i, 1, 2 * n) {
    //     cout << color[i] << " ";
    // }
    // cout << endl;

    set<int> s1, s2;
    FOR (i, 1, n) {
        s1.insert(data[i].l);
        s2.insert(data[i].r);
    }

    cout << max(s1.size(), s2.size()) << endl;
    return 0;
}