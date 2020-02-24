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

int a[1 << 19];
bool used[1 << 19];
int f;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        if (a[i] == -1) f = i;
    }   
    ll res = 0;
    FORD (k, flog2(n), 1) {
        if (f >= (1 << k)) {
            cout << res << endl;
            return 0;
        }
        int minCost = INF + 1;
        int ind = -1;
        FOR (i, (1 << k), n) {
            if (!used[i] && minCost > a[i]) {
                minCost = a[i];
                ind = i;
            }
        }
        used[ind] = 1;
        res += minCost;
    }
    cout << res << endl;

    return 0;
}