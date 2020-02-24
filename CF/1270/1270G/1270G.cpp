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
typedef pair < ll, ll > pll;

int cnt[200005 * 505];

int bucket(int a, int b) {
    return a * 500 + b;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();

    vector<int> a(n + 1);
    FOR (i, 1, n) {
        a[i] = a[i - 1];
        if (s[i - 1] == '1') a[i]++;
    }

    int T = sqrt(n) + 1;
    ll res = 0;

    // k <= T
    FOR (k, 1, T) {
        FOR (i, 0, n) {
            res += cnt[k * a[i] - i + n];
            cnt[k * a[i] - i + n]++;
        }
        FOR (i, 0, n) cnt[k * a[i] - i + n] = 0;
    }

    // k > T
    // u = a[i] - a[j] <= n / T;
    FOR (u, 1, n / T) {
        FOR (i, 0, n) {
            int j = i - (T + 1) * u;
            if (j >= 0 && j <= i) {
                cnt[bucket(a[j], j % u)]++;
            }

            if (a[i] - u >= 0) {
                res += cnt[bucket(a[i] - u, i % u)];
            }
        }
        FOR (i, 0, n) {
            cnt[bucket(a[i], i % u)] = 0;
        }
        // cout << u << " " << res << endl;
    }

    cout << res << endl;

    return 0;
}