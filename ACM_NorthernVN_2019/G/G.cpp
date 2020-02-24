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

char c[1005][1005];
int a[1005][1005];

bitset<4000> bs[1005][1005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        int n, m;
        cin >> n >> m;
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                cin >> c[i][j];
                a[i][j] = c[i][j] - '0'; 
            }
        }

        FOR (i, 1, n) {
            FOR (j, 1, m) {
                if (i == 1 && j == 1) {
                    bs[i][j] = bitset<4000>();
                    bs[i][j][a[i][j]] = 1;
                }
                else {
                    bs[i][j] = bs[i - 1][j] | bs[i][j - 1];
                    bs[i][j] <<= a[i][j];
                }
            }
        }

        FOR (i, 0, 3999) {
            if (bs[n][m][i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}