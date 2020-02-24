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

string s[25], t[25];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 0, n - 1) {
        cin >> s[i];
    }
    FOR (i, 0, m - 1) {
        cin >> t[i];
    }

    int q;
    cin >> q;
    FOR (z, 1, q) {
        int x;
        cin >> x;
        x--;
        int a = x % n;
        int b = x % m;
        string res = s[a] + t[b];
        cout << res << '\n';
    }

    return 0;
}