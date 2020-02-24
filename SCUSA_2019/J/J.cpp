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

char c[55][55];
int row[55], col[55];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cin >> c[i][j];
            if (c[i][j] == 'W') {
                row[i]++;
                col[j]++;
            }
        }
    }

    FOR (i, 1, n) {
        if (row[i] != n / 2 || col[i] != n / 2) {
            cout << 0;
            return 0;
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, n - 2) {
            if (c[i][j] == c[i][j + 1] && c[i][j + 1] == c[i][j + 2]) {
                cout << 0;
                return 0;
            }

            if (c[j][i] == c[j + 1][i] && c[j + 1][i] == c[j + 2][i]) {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1;

    return 0;
}