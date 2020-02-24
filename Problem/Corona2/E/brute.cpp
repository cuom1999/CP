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

bitset<55> a[100005], res;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
        string s;
        cin >> s;
        FOR (j, 0, m - 1) {
            a[i][j] = s[j] - '0';
        }
    }

    FOR (z, 1, 1000000) {
        FOR (j, 0, m - 1) {
            res[j] = rand() % 2;
        }
        bool isGood = 1;
        FOR (i, 1, n) {
            bitset<55> val = res ^ a[i];
            if (val.count() == m) {
                isGood = 0;
                break;
            }
        }
        if (isGood) {
            FOR (i, 0, m - 1) cout << res[i];
            return 0;
        }
    }
    cout << "LN\n";
    return 0;
}