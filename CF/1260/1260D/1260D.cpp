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

const int MAXN = 200005;
int a[MAXN], l[MAXN], r[MAXN], d[MAXN];
int m, n, k, t;

bool check(int x) {
    int agi = a[x];
    vector<II> queries;
    FOR (i, 1, k) {
        if (d[i] > agi) {
            queries.pb({l[i], r[i]});
        }
    }
    sort(all(queries));
    int curL = 0, curR = -1;
    ll res = 0;
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i].first > curR) {
            res += 2 * (curR - curL + 1);
            curL = queries[i].first;
            curR = queries[i].second;
        }
        else {
            curR = max(curR, queries[i].second);
        }
    }
    res += 2 * (curR - curL + 1);
    return res <= t;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n >> k >> t;
    a[0] = INF;
    FOR (i, 1, m) {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    t -= (n + 1);
    FOR (i, 1, k) {
        cin >> l[i] >> r[i] >> d[i]; 
    }
    int lower = 0, upper = m;
    while (lower < upper) {
        int mid = (lower + upper + 1) / 2;
        if (check(mid)) {
            lower = mid;
        }
        else {
            upper = mid - 1;
        }
    }
    cout << lower << endl;
    return 0;
}