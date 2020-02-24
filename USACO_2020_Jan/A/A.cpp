#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("cave.in","r",stdin)
#define OUT freopen("cave.out","w",stdout)
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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

char c[1005][1005];
int dx[2] = {1, 0};
int dy[2] = {0, -1};
int lab[1005 * 1005];

const ll MOD = 1e9 + 7;
ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll tmpProd, totalProd;

int node(int x, int y) {
    return x * 1001 + y;
}

int getRoot(int val) {
    while (lab[val] >= 0) {
        val = lab[val];
    }
    return val;
}

void join(int x, int y) {
    if (lab[x] > lab[y]) {
        swap(x, y);
    }
    lab[x] += lab[y];
    lab[y] = x;
} 


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    pw2[0] = 1;
    FOR (i, 1, 1000000) {
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }

    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> c[i][j];
        }
    }
    memset(lab, -1, sizeof(lab));

    ll res = 1;
    bool hasEmpty = 0;

    int numCC = 0;
    FORD (i, n - 1, 2) {
        FOR (j, 2, m - 1) {
            if (c[i][j] == '#') continue;
            hasEmpty = 1;
            numCC++;
            int curNode = node(i, j);
            FOR (k, 0, 1) {
                int newI = i + dx[k];
                int newJ = j + dy[k];
                if (c[newI][newJ] == '.') {
                    // cout << newI << " " << newJ << endl;
                    int newNode = node(newI, newJ);
                    int x = getRoot(curNode);
                    int y = getRoot(newNode);
                    if (x != y) {
                        numCC--;
                        join(x, y);
                    }
                }
            }
            // cout << i << " " << j << " " << numCC << endl;
        }   
        res = (res + pw2[numCC] - 1) % MOD;
        // cout << numCC << endl;
    }
    if (!hasEmpty) {
        cout << 0 << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}