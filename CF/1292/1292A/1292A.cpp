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

int cnt[5], cntPair[7];
int a[4][100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    cnt[3] = n;
    cntPair[6] = n - 1;
    FOR (i, 1, 2) {
        FOR (j, 1, n) {
            a[i][j] = i;
        }
    }


    FOR (z, 1, q) {
        int x, y;
        cin >> x >> y;
        
        cnt[a[x][y] + a[3 - x][y]]--;
        
        if (y > 1) cntPair[a[x][y] + a[3 - x][y] + a[1][y - 1] + a[2][y - 1]]--;
        if (y < n) cntPair[a[x][y] + a[3 - x][y] + a[1][y + 1] + a[2][y + 1]]--;

        if (!a[x][y]) {
            a[x][y] = x;
        }
        else {
            a[x][y] = 0;
        }

        cnt[a[x][y] + a[3 - x][y]]++;
        if (y > 1) cntPair[a[x][y] + a[3 - x][y] + a[1][y - 1] + a[2][y - 1]]++;
        if (y < n) cntPair[a[x][y] + a[3 - x][y] + a[1][y + 1] + a[2][y + 1]]++;

        if (cnt[0] || cntPair[3]) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }

    return 0;
}