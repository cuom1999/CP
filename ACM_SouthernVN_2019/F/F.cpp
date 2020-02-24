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
    bool operator< (const Data& a) {
        if (l != a.l) return r < a.r;
        return l < a.l;
    }
};


int d[605][605];
int n;
vector<Data> data;

int dp(int l, int r, vector<Data>& data) {
    if (l > r) return 0;
    int res = 0;
    FOR (i, 1, n) {
        vector<Data> newData;
        if (data[i].l == l && data[i].r == r) {
            for (auto i: data) {
                if (i.l != l || i.r != r) newData.pb({max(l + 1, i.l), min(r - 1, i.r)});
            }
            res = max(res, dp(l + 1, r - 1, newData) + 1);
        }
        if (data[i].l == l && data[i].r < r) {
            int maxR = 
            for (auto i: data) {

            }
            res = max(res, dp(l + 1, r) + 1);
        }
        if (data[i].l > l && data[i].r >= r) {
            res = max(res, dp(l, r - 1) + 1);
        }
    }

    cout << l << " " << r << " " << res << endl;

    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    data.resize(n + 1);

    vector<II> v;
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

    memset(d, -1, sizeof(d));
    // cout << curr << endl;
    cout << dp(1, curr) << endl;


    return 0;
}