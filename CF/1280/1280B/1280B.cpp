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

int a[65][65];
int row[65], col[65];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    FOR (z, 1, t) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                char c;
                cin >> c;
                if (c == 'A') a[i][j] = 1;
                else a[i][j] = 0;
                sum += a[i][j];
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }

        // check MORTAL
        if (sum == m * n) {
            cout << 0 << "\n";
            continue;
        }
        if (sum == 0) {
            cout << "MORTAL\n"; 
            continue;
        }

        // check 1
        if (row[1] == m || row[n] == m || col[1] == n || col[m] == n) {
            cout << 1 << "\n";
            continue;
        }

        // check 2
        bool isGood = 0;
        FOR (i, 1, n) {
            if (row[i] == m) isGood = 1;
        }
        FOR (i, 1, m) {
            if (col[i] == n) isGood = 1;
        }
        if (a[1][1] || a[1][m] || a[n][1] || a[n][m]) isGood = 1;
        if (isGood) {
            cout << 2 << '\n';
            continue;
        }

        // check 3
        if (!row[1] && !row[n] && !col[1] && !col[m]) {
            cout << 4 << "\n";
        }
        else {
            cout << 3 << '\n';
        }
    }

    return 0;
}