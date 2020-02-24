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

bool solve(vector<int>&a, int m, int k, int x) {
    int n = a.size() - 1;
    int l = 1, r = n;
    FOR (i, 1, m - 1) {
        if (a[l] >= x) {
            l++;
        }
        else if (a[r] >= x) {
            r--;
        }
        else {
            if (k) k--;
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n + 1);
        FOR (i, 1, n) {
            cin >> a[i];
        }
        k = min(k, m - 1);
        int res = INF;
        FOR (i, 1, m + 1) {
            if (a[i] < a[n - m - i]) continue;
            vector<int> v;
            FOR (j, 1, i - 1) {
                v.pb(a[j]);
            }
            FOR (j, 1, m - i + 1) {
                v.pb(a[n + 1 - j]);
            }
            sort(all(v));
            res = min(res, v[k]);
        }
        cout << res << '\n';
    }


    return 0;
}