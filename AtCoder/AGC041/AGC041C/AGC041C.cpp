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



int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n % 3) {
        cout << -1 << "\n";
    }
    else {
        char a[3][3];
        FOR (i, 0, 2) {
            FOR (j, 0, 2) {
                a[i][j] = '.';
            }
        }

        a[0][1] = a[0][0] = 'a';
        a[1][2] = a[2][2] = 'b';

        FOR (i, 0, n - 1) {
            FOR (j, 0, n - 1) {
                cout << a[i % 3][j % 3];
            }
            cout << '\n';
        }
    }

    return 0;
}