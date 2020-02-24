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

int n, m;
int a[300005][10];    

bool solve(int k, pair<int, int>& res) {
    vector<int> mask(1 << m);

    FOR (i, 1, n) {
        int bit = 0;
        FOR (j, 0, m - 1) {
            if (a[i][j] >= k) {
                bit |= (1 << j);
            }
        }
        mask[bit] = i;
        // cout << bit << endl;
    }

    FOR (i, 0, (1 << m) - 1) {
        FOR (j, 0, (1 << m) - 1) {
            if ((i | j) == ((1 << m) - 1) && mask[i] && mask[j]) {
                res = {mask[i], mask[j]};
                return 1;
            }
        }
    }
    return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    FOR (i, 1, n) {
        FOR (j, 0, m - 1) {
            cin >> a[i][j];
        }
    }
    // FOR (i, 0, 10) cout << solve(i) << " ";
    int lower = 0, upper = 1e9;
    pair<int, int> res;
    while (lower < upper) {
        int mid = (lower + upper + 1) / 2;
        if (solve(mid, res)) {
            lower = mid;
        }
        else upper = mid - 1;
    }

    solve(lower, res);
    cout << res.first << " " << res.second << endl;
    return 0;
}