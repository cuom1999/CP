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

int star[300005], en[300005];
int a[300005];
int st[300005 * 4], d[300005];

void update(int id, int l, int r, int u, int k) {
    if (l == r) {
        st[id] = k;
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) update(id * 2, l, mid, u, k);
    else update(id * 2 + 1, mid + 1, r, u, k);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -INF;
    if (u <= l && r <= v) {
        return st[id];
    }
    int mid = (l + r) / 2;
    return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        int cnt = 0;
        
        FOR (i, 1, 4 * n) st[i] = 0;
        FOR (i, 1, n) {
            star[i] = en[i] = 0;
        }

        FOR (i, 1, n) {
            cin >> a[i];
        }
        vector<II> v;
        FOR (i, 1, n) {
            v.pb({a[i], i});
        }
        sort(all(v));
        int cur = 0;
        for (int i = 0; i < v.size(); i++) {
            if (!i || v[i].first != v[i - 1].first) {
                cur++;
            }
            a[v[i].second] = cur;
        }

        FOR (i, 1, n) {
            if (!star[a[i]]) {
                star[a[i]] = i;
                cnt++;
            }
            en[a[i]] = i;
        }
        FOR (i, 1, n) {
            if (en[a[i]] == i && star[a[i]] > en[a[i] - 1]) {
                d[a[i]] = d[a[i] - 1] + 1; 
            }
            else if (en[a[i]] == i) d[a[i]] = 1;
        }

        int res = 0;
        FOR (i, 1, cnt) {
            // cout << i << " " << d[i] << endl;
            res = max(res, d[i]);
        }
        cout << cnt - res << endl;
    }

    return 0;
}