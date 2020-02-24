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
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int l, r;
    while (cin >> l >> r) {
        if (!l && !r) break;
        ld res = 0;
        ld e = 1e-15;
        FOR (i, l, r) {
            ld a = pow(i + e, 1.0/3);
            ld b = pow(i, 1.0/3);
            ld val = 1 / (a * a + a * b + b * b);
            res += val;
        }

        cout << fixed << setprecision(5) << res << "E-015\n";
    }

    // ld sum = 0;
    // int l = 10000000, r = 20000000;
    // FOR (i, 1, r) {
    //     sum += pow(i, -2.0/3);
        
    // }
    // ld val = 3 * pow(r, 1.0/3);
    // cout << fixed << setprecision(8) << sum << " " << val << endl; 
    return 0;
}