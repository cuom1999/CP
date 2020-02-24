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

void output(int a, int b, int c, int sign) {
    cout << a * sign << " " << b * sign << " " << c * sign << '\n';
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        int sign = 1;
        if (n < 0) {
            sign = -1;
            n = -n;
        }
        if (n % 3 == 1) {
            n /= 3;
            output(n, n, n + 1, sign);
        }
        else if (n % 3 == 2) {
            n /= 3;
            output(n, n + 1, n + 1, sign);
        }
        else {
            if (n % 9 == 0) {
                n /= 9;
                output(n - 1, n, n + 1, sign);
            }
            else {
                cout << "LN\n";
            }
        }
    }

    return 0;
}