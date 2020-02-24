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

int a[505], b[505];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (c == 1) {
        FOR (i, 1, r) cout << i + 1 << "\n";
        return 0;
    }
    FOR (i, 1, r) a[i] = i;
    FOR (i, 1, c) b[i] = r + i;

    FOR (i, 1, r) {
        FOR (j, 1, c) {
            cout << a[i] * b[j] / __gcd(a[i], b[j]) << " ";
        }
        cout << endl;
    }

    return 0;
}