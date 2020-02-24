#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

typedef pair < int, int > II;
typedef pair < int, II > III;

const int N = 3000000;
vector<III> pytagos[N + 1];

bitset<5504> gcd1[5504], vs[5505];

bool calcgcd1(int a, int b) {  
    if (!a || !b) return (a == 1 || b == 1);
    if (vs[a][b]) return gcd1[a][b];
    
    vs[a][b] = 1;

    if (a > b) swap(a, b);

    return gcd1[a][b] = calcgcd1(b % a, a);
}

int A[30000001], B[30000001], C[30000001];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int numA, numB, numC;
    cin >> numA >> numB >> numC;

    FOR (i, 1, numA) {
        int x;
        cin >> x;
        A[x]++;
    }

    FOR (i, 1, numB) {
        int x;
        cin >> x;
        B[x]++;
    }

    FOR (i, 1, numC) {
        int x;
        cin >> x;
        C[x]++;
    }

    int n = 30000000;
    int cnt = 0;

    gcd1[1][0] = gcd1[0][1] = 1;
    gcd1[1][1] = 1;

    ll res = 0;

    for (int i = 1; i <= n / i; i += 2) {
        for (int j = 2; j * 1ll * j <= n - i * i; j += 2) {
            
            int diff = i - j;
            if (diff < 0) diff = -diff;

            gcd1[i][j] = gcd1[j][i] = calcgcd1(i, j);

            if (gcd1[i][j]) {
                int a = abs(i * i - j * j);
                int b = 2 * i * j;
                int c = sq(i) + sq(j);

                pytagos[c % N].pb({c, {a, b}});
            }
        }
    }

    FOR (i, 1, 30000000) {
        if (!pytagos[i % N].size()) continue;
        for (int j = i; j <= 30000000; j += i) {
            if (C[j]) {
                int k = j / i;
                for (auto &m: pytagos[i % N]) {
                    if (m.first == i) {
                        res += A[m.second.first * k] * 1ll * B[m.second.second * k] * C[j];
                        res += A[m.second.second * k] * 1ll * B[m.second.first * k] * C[j];
                    }
                }
            }
        }
    }

    // cout << pytagos.size() << endl;
    // cout << cnt << endl;
    cout << res << endl;
    return 0;
}