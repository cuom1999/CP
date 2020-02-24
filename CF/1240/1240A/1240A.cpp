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

int n;
ll p[200005], x, y, a, b;
ll k;
        
bool check(int m) {
    ll u = __gcd(a, b);
    ll lcm = a * b / u;
    int numAB = m / lcm;
    int numA = m / a - numAB;
    int numB = m / b - numAB;
    ll res = 0;
    FOR (i, 1, numAB) {
        res += (x + y) * p[i] / 100; 
    }
    if (x >= y) {
        FOR (i, numAB + 1, numAB + numA) {
            res += x * p[i] / 100;
        }
        FOR (i, numAB + numA + 1, numAB + numA + numB) {
            res += y * p[i] / 100;
        }
    }
    else {
        FOR (i, numAB + 1, numAB + numB) {
            res += y * p[i] / 100;
        }
        FOR (i, numAB + numB + 1, numAB + numA + numB) {
            res += x * p[i] / 100;
        }   
    }
    return (res >= k);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        cin >> n;
        FOR (i, 1 , n) {
            cin >> p[i];
        }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);

        int lower = 1, upper = n;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (check(mid)) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }
        if (check(lower)) cout << lower << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}