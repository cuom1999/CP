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

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

struct PytagoTriple {
    int a, b, c; //a * a + b * b = c * c
    PytagoTriple(int __a = 0, int __b = 0, int __c = 0): a(__a), b(__b), c(__c){}
};

vector<PytagoTriple> pytagos;

bitset<10004> gcd[10004], vs[10005];

bool calcGCD(int a, int b) {  
    if (!a || !b) return (a == 1 || b == 1);
    if (vs[a][b]) return gcd[a][b];
    
    vs[a][b] = 1;

    if (a > b) swap(a, b);

    return gcd[a][b] = calcGCD(b % a, a);
}

int main()
{IN; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n = 100000000;
    ll cnt = 0;
    int cnt2 = 0;

    gcd[1][0] = gcd[0][1] = 1;
    gcd[1][1] = 1;

    for (int i = 1; i <= n / i; i += 2) {
        for (int j = 2; j * 1ll * j <= n - i * i; j += 2) {
            
            int diff = i - j;
            if (diff < 0) diff = -diff;

            gcd[i][j] = gcd[j][i] = calcGCD(i, j);

            if (gcd[i][j]) {
                int a = abs(i * i - j * j);
                int b = 2 * i * j;
                int c = sq(i) + sq(j);

                for (int k = 1; k <= n / c; k++) {
                    //pytagos.pb(PytagoTriple(a * k, b * k, c * k));
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
        
    return 0;
}