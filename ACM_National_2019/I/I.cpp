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
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;

    int n = s.length();

    int m = 0, h = 0;
    ll sum = 0; 

    FOR (i, 0, n - 1) {
        if (s[i] == '?') {
            m++;
            sum += i + 1;
        }
        else if (s[i] == 'H') {
            sum += 2 * (i + 1);
            h++;
        }
    }

    ld res = m * 1.0 * (m + 1) / 4.0 + h * 1ll * m + h * 1ll * h;
    res = sum - res;
    cout << fixed << setprecision(8) << res << endl;



    return 0;
}