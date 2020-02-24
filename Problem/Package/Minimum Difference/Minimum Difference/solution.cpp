#include <bits/stdc++.h>
#define base 1000000007LL
#define ll long long
#define X first
#define Y second
#define ld double
#define pb push_back
#define EPS 1e-9
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
using namespace std;
typedef pair<int, int> II;
typedef pair<ll, II> III;

ll a[500010], b[500010], g[500010], h[500010], x;
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m >> x;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> b[i];
    ll step1 = 0, step2 = 0;
    FOR(i,1,n) {
        step1 += a[i] / x;
        a[i] %= x;
    }
    FOR(i,1,m) {
        step2 += b[i] / x;
        b[i] %= x;
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    if (step1 > step2) {
        step1 -= step2;
        step1 %= m;
        FORE(i,m,m-int(step1)+1) b[i] -= x;
        sort(b+1, b+m+1);
    }
    else if (step2 > step1) {
        step2 -= step1;
        step2 %= n;
        FORE(i,n,n-int(step2)+1) a[i] -= x;
        sort(a+1, a+n+1);
    }
    int gcd = __gcd(n,m);
    FOR(i,0,gcd-1) g[i] = h[i] = 1000000000000000000LL;
    g[0] = a[n] - a[1];
    FOR(i,1,n-1) g[i%gcd] = min(g[i%gcd], a[n-i] + x - a[n-i+1]);
    h[0] = b[m] - b[1];
    FOR(i,1,m-1) h[i%gcd] = min(h[i%gcd], b[m-i] + x - b[m-i+1]);
    ll res = 1000000000000000000LL;
    FOR(i,0,gcd-1) res = min(res, g[i] + h[i]);
    cout << res;
    return 0;
}
