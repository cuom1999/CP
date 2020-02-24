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

int n, k;
ld a[505];

int getPrev(int i) {
    if (i == 1) return n;
    return i - 1;
}

ld calc(int i) {
    if (n - i - 1 < k - 2) return 0;
    ld res = 1;
    FOR (j, 0, i - 2) {
        res *= (ld) (n - k - i + 2 + j) * 1.0 / (n - i + j);
    }
    res *= k * 1.0 / n * (k - 1) / (n - 1);
    return res;
}

ld c[505];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];

    if (k == 1) {
        FOR (i, 1, n) {
            cout << fixed << setprecision(8) << 100.0 / n << " ";
        }
        return 0;
    }
    FOR (i, 1, n) c[i] = calc(i);

    FOR (i, 1, n) {
        ld res = 0;
        ld sum = a[i];
        int cur = i;
        FOR (u, 1, n) {
            res += c[u] * sum;
            cur = getPrev(cur);
            sum += a[cur];
        }
        // res /= n;
        cout << fixed << setprecision(8) << res << " ";
    }

    return 0;
}