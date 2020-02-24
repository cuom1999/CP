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

ld d[5000005];
ld c = 3 * pow(8000000, 1.0/3);
ld calc(int l) {
    if (l <= 5000000) return d[l];
    return 3 * pow(l, 1.0/3) - c + d[8000000];
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // cout << fixed << setprecision(10) << pow(8981422, 1.0/3) - pow(8976481, 1.0/3) << endl;

    ld e = 1e-15;
    FOR (i, 1, 5000000) {
        ld a = pow(i + e, 1.0/3);
        ld b = pow(i, 1.0/3);
        ld val = 1 / (a * a + a * b + b * b);
        d[i] = d[i - 1] + val;
    }

    int l, r;
    while (cin >> l >> r) {
        if (!l && !r) break;
        // ld res = 0;
        // ld e = 1e-15;
        // res = (calc(r) - calc(l - 1)) / 3;
        ld res = 0;
        if (r <= 5000000) {
            res = d[r] - d[l - 1];
        }
        else {
            ld e = 1e-15;
            FOR (i, l, r) {
                ld a = pow(i + e, 1.0/3);
                ld b = pow(i, 1.0/3);
                ld val = 1 / (a * a + a * b + b * b);
                res += val;
            }
        }

        cout << fixed << setprecision(5) << res << "E-015\n";
    }

    return 0;
}