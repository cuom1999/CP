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

int l[100], r[100], pos[100], color[100], used[100];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> l[i] >> r[i];
    }

    FOR (i, 1, n) pos[i] = i;
    int res = 0;

    do {
        memset(color, 0, sizeof(color));
        memset(used, 0, sizeof(used));
        FOR (i, 1, n) {
            FOR (j, l[pos[i]], r[pos[i]] - 1) {
                color[j] = i;
            }
        }
        FOR (i, 1, 99) {
            used[color[i]] = 1;
        }

        int val = 0;
        FOR (i, 1, n) {
            val += used[i];
        }
        if (val == 4) {
            FOR (i, 1, n) cout << pos[i] << " ";
            cout << endl;
        }

        res = max(res, val);
    } while (next_permutation(pos + 1, pos + n + 1));

    cout << res << endl;
    return 0;
}