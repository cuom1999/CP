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

const int MAXN = 1000005;

ll a[MAXN];
ll p[MAXN], s[MAXN], s0[MAXN];
ld maxPre[MAXN], maxSuf[MAXN];
int n;

bool calc(ld ans) {
    FORD (i, n, 1) {
        maxSuf[i] = max(maxSuf[i + 1], s[i] - ans * (n + 1 - i));
    }

    FOR (i, 1, n) {
        // cout << i << " " << maxPre[i] << " " << maxSuf[i + 1] << endl;
        if (p[i] - ans * i + maxSuf[i + 1] >= 0) return 1;
    }
    FOR (i, 1, n) {
        if (s[i] - ans * (n + 1 - i) >= 0) return 1;
    }
    return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    FORD (i, n, 1) {
        s[i] = s[i + 1] + a[i];
        s0[i] = s0[i + 1] + i;
    }

    ld L = 0, R = 1e9;
    FOR (i, 1, 200) {
        ld mid = (L + R) / 2;
        if (calc(mid)) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    cout << fixed << setprecision(13) << L << endl;


    return 0;
}