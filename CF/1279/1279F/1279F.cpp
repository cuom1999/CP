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

struct Solver {
    int n;
    int k, l;
    int a[1000005];

    Solver(string s, int kk, int l1) {
        k = kk, l = l1;
        n = s.size();
        FOR (i, 1, n) {
            a[i] = s[i - 1] - '0';
            // cout << a[i] << " ";
        }
        // cout << endl;
    }

    II calc(ll cost) {
        vector<ll> d(n + 1), cnt(n + 1);
        FOR (i, 1, n) {
            d[i] = d[i - 1] + a[i];
            cnt[i] = cnt[i - 1];
            int u = min(i, l);
            if (d[i] < d[i - u] + u - cost) {
                d[i] = d[i - u] + u - cost;
                cnt[i] = cnt[i - u] + 1;
            }
            // cout << i << " " << d[i] << endl;
        }
        return {d[n], cnt[n]};
    }

    ll solve() {
        int lower = 0, upper = n;
        // FOR (i, lower, upper) {
        //     cout << calc(i).first << " " << calc(i).second << endl;
        // }
        // return 0;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            auto u = calc(mid);
            if (u.second > k) {
                lower = mid + 1;
            }
            else {
                upper = mid;
            }
        }
        auto u = calc(lower);
        return u.first + k * 1ll * lower;
    }

};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k, l;
    cin >> n >> k >> l;

    string s, s2;
    cin >> s;
    s2 = s;

    FOR (i, 0, n - 1) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = '1';
            s2[i] = '0';
        }
        else {
            s[i] = '0';
            s2[i] = '1';
        }
    }

    Solver a(s, k, l);
    // cout << a.solve();
    // return 0;
    Solver b(s2, k, l);

    cout << n - max(a.solve(), b.solve()) << endl;

    return 0;
}