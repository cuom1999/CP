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

ll a[100005], b[100005];

// use when opt[i] <= opt[j], i <= j
struct Opt1D {
    int n;
    vector<ll> dp;

    Opt1D(int n): n(n) {
        dp.resize(n + 1);
    }

    ll cost(int i, int j) { // i -> j
        return b[i] * a[j];
    }

    void solve() {
        vector<pair<int, int> > opt; // start pos, best-k
        opt.push_back(make_pair(1, 1)); // maybe (0, 0) if start at 0
        dp[1] = 0;

        for (int x = 2; x <= n; x++) {
            // Find the value of dp[x]
            int k = (--lower_bound(opt.begin(), opt.end(), make_pair(x + 1, 0)))->second;
            dp[x] = dp[k] + cost(k, x);

            // Update the segments
            for (int i = opt.size() - 1; i >= 0; i--) {
                int y = opt[i].first, oldk = opt[i].second;
                // Case 1
                if (y > x && dp[x] + cost(x, y) < dp[oldk] + cost(oldk, y))
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
                opt.push_back(make_pair(1, x)); // maybe (0, x) if start at 0
        }
    }
};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    Opt1D solver(n);

    FOR (i, 1, n) {
        cin >> a[i];
    }

    FOR (i, 1, n) {
        cin >> b[i];
    }

    solver.solve();
    cout << solver.dp[n] << endl;

    return 0;
}