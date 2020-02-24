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

ll a[100005], t[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n;

    t[0] = 1e11 + 1;
    FOR (i, 1, n) {
        cin >> a[i];
        t[i] = min(t[i - 1], a[i]);
    }

    cin >> q;

    FOR (i, 1, q) {
        ll x;
        cin >> x;
        int cur = 1;
        while (cur <= n) {
            int lower = cur, upper = n + 1;
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                if (t[mid] <= x) {
                    upper = mid;
                }
                else {
                    lower = mid + 1;
                }
            }
            cur = lower;
            if (cur <= n) {
                x %= a[cur];
            }
        }   
        cout << x << '\n';
    }

    return 0;
}