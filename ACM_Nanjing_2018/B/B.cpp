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
typedef pair < ll, ll > II;

ll a[300005], s[300005];

// https://sites.google.com/site/ubcprogrammingteam/news/1d1ddynamicprogrammingoptimization-parti
// use when opt[i] <= opt[j], i <= j
struct Opt1D {
    int n;
    ll c;
    vector<ll> dp, numGroup;

    Opt1D(int n, ll c): n(n), c(c) {
        dp.resize(n + 1);
        numGroup.resize(n + 1);
    }

    ll cost(int l, int r) { // i -> j
        int mid = (l + r) / 2;
        if ((l + r) % 2 == 0) {
            return s[r] + s[l] - 2 * s[mid] + c;
        }
        return s[r] + s[l] - s[mid] - s[mid + 1] + c;
    }

    void solve() {
        vector<pair<int, int> > opt; // start pos, best-k
        opt.push_back(make_pair(0, 0)); // maybe (0, 0) if start at 0
        dp[0] = 0;

        for (int x = 1; x <= n; x++) {
            // Find the value of dp[x]
            int k = (--lower_bound(opt.begin(), opt.end(), make_pair(x + 1, 0)))->second;
            dp[x] = dp[k] + cost(k, x);
            numGroup[x] = numGroup[k] + 1;

            // Update the segments
            for (int i = opt.size() - 1; i >= 0; i--) {
                int y = opt[i].first, oldk = opt[i].second;
                // Case 1
                if (y > x && dp[x] + cost(x, y) <= dp[oldk] + cost(oldk, y))
                    opt.pop_back();
                // Case 2
                else {
                    int lo = y + 1, hi = n + 1;
                    while(lo < hi) {
                        int mid = (lo + hi) / 2;
                        if (dp[x] + cost(x, mid) <= dp[oldk] + cost(oldk, mid))
                            hi = mid;
                        else
                            lo = mid + 1;
                    }
                    if (hi != n + 1) opt.push_back(make_pair(hi, x));
                    break;
                }
            }
            if (opt.size() == 0)
                opt.push_back(make_pair(0, x)); // maybe (0, x) if start at 0
        }
    }
};

II solve(int n, ll cost) {
    Opt1D solver(n, cost);
    solver.solve();
    return {solver.dp[n], solver.numGroup[n]};
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    FOR (i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    ll lower = 0, upper = 5e14;
    while (lower < upper) {
        ll mid = (lower + upper + 1) / 2;
        auto u = solve(n, mid);
        if (u.second >= k) {
            lower = mid;
        }
        else {
            upper = mid - 1;
        }
    }
    auto u = solve(n, lower);
    cout << u.first - k * lower << endl;

    return 0;
}