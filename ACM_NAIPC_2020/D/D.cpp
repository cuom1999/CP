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

int n, k;
char a[6][6];
int len[6], c[6][6];
ll res;

bool check() {
    FOR (i, 1, n) {
        FOR (j, 1, n) {
            if (a[i][j] == 'X' && c[i][j]) return 0;
            if (a[i][j] == 'O' && c[i][j] == 0) return 0;
        }
    }

    // FOR (i, 1, n) {
    //     FOR (j, 1, n) {
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return 1;
}

void backtrack(int index) {
    if (index == k) {
        res += check();
        return;
    }

    // cout << index << endl;
    // FOR (i, 1, n) {
    //     FOR (j, 1, n) {
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    FOR (i, 1, n - len[index + 1] + 1) {
        FOR (j, 1, n) {
            bool isValid = 1;
            FOR (k, 0, len[index + 1] - 1) {
                if (c[i + k][j]) isValid = 0;
            }

            if (isValid) {
                FOR (k, 0, len[index + 1] - 1) {
                    c[i + k][j] = index + 1;
                }
                backtrack(index + 1);
                FOR (k, 0, len[index + 1] - 1) {
                    c[i + k][j] = 0;
                }
            }
            if (len[index + 1] == 1) continue;

            isValid = 1;
            FOR (k, 0, len[index + 1] - 1) {
                if (c[j][i + k]) isValid = 0;
            }
            
            if (isValid) {
                FOR (k, 0, len[index + 1] - 1) {
                    c[j][i + k] = index + 1;
                }
                backtrack(index + 1);
                FOR (k, 0, len[index + 1] - 1) {
                    c[j][i + k] = 0;
                }
            }            
        }
    }


}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cin >> a[i][j];
        }
    }

    FOR (i, 1, k) {
        cin >> len[i];
    }

    backtrack(0);

    cout << res << endl;


    return 0;
}