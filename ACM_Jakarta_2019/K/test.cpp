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

const ll K = 1e9 + 7;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    s = '0' + s;

    FOR (z, 1, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            FOR (i, l, r) {
                if (s[i] == 'A') s[i] = 'B';
                else s[i] = 'A';
            }
        }
        else {
            int l, r;
            ll a, b;
            cin >> l >> r >> a >> b;
            FOR (i, l, r) {
                if (s[i] == 'A') a = (a + b) % K;
                else b = (a + b) % K;
            }
            cout << a << " " << b << "\n";
        }
    }

    return 0;
}
