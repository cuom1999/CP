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

int lostMoney(int dice, int money) {
    if (dice == 0) {
        return -money;
    }
    return money * dice;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int cnt[4];
    FOR (i, 1, 3) cin >> cnt[i];

    vector<int> money(7);

    FOR (i, 1, 3) {
        FOR (j, 1, cnt[i]) {
            int x, y;
            cin >> x >> y;
            money[x] += y;
        }
    }

    int res = -1e9;

    FOR (i, 1, 6) {
        FOR (j, 1, 6) {
            FOR (k, 1, 6) {
                int lost = 0;
                vector<int> dice(7);
                dice[i]++;
                dice[j]++;
                dice[k]++;

                FOR (u, 1, 6) {
                    lost += lostMoney(dice[u], money[u]);
                }
                res = max(res, lost);
            }
        }
    }

    cout << res << endl;

    return 0;
}