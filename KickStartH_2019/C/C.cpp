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

struct Solver {
    ll a[10];
    ll sum = 0;
    ll n = 0;

    void input() {
        FOR (i, 1, 9) {
            cin >> a[i];
            sum += a[i] * 1ll * i;
            n += a[i];
        }
        sum = sum * 6 % 11;
    }

    bool d[10][105][11];
    void bruteForce() {
        ll m = 0;
        d[0][0][0] = 1;
        FOR (i, 1, 9) m += a[i];

        FOR (i, 1, 9) {
            FOR (k, 0, m) {
                FOR (s, 0, 10) {
                    d[i][k][s] = 0;
                    FOR (j, 0, a[i]) {
                        if (j <= k) d[i][k][s] |= d[i - 1][k - j][(s - i * j % 11 + 11) % 11];
                    }
                }
            }
        }
    }

    bool solve() {
        if (n < 20) {
            bruteForce();
            return d[9][n / 2][sum];
        }
        else {
            int cnt = 0;
            int index = 0;
            FOR (i, 1, 9) {
                if (a[i] >= 10) {
                    cnt++;
                    a[i] = 0;
                    index = i;
                }
            }
            if (cnt >= 2) return 1;
            if (cnt == 0) {
                bruteForce();
                return d[9][n / 2][sum];
            }
            bruteForce();
            ll m = 0;
            FOR (i, 1, 9) m += a[i];
            FOR (k, 0, m) {
                FOR (s, 0, 10) {
                    if (d[9][k][s] && k <= n / 2) {
                        ll val = (n / 2 - k) * index + s;
                        val %= 11;
                        if ((val - sum) % 11 == 0) return 1;
                    }
                }
            }
            return 0;
        }
    }
};


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";
        Solver solver;
        solver.input();
        if (solver.solve()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}