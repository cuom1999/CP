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

ld w, g, h, r;

ld calc(ld w1) {
    ld w2 = w - w1;
    ld l1 = sqrt(sq(w1) + sq(g - r));
    ld l2 = sqrt(sq(w2) + sq(h - r));
    ld ma = l1 + l2;
    return ma;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> w >> g >> h >> r;

        ld mi = sqrt(sq(w) + sq(g - h));

        ld L = 0, R = w, LL = (2 * L + R) / 3, RR = (L + 2 * R) / 3;
        FOR (j, 1, 100) {
            if (calc(LL) > calc(RR)) {
                L = LL;
            }
            else R = RR;
            LL = (2 * L + R) / 3;
            RR = (L + 2 * R) / 3;
        }

        cout << fixed << setprecision(9) << mi << " " << calc(L) << "\n";
    }

    return 0;
}