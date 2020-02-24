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

    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int m = n - a1 * (k1 - 1) - a2 * (k2 - 1);

    if (m < 0) {
        cout << 0 << " ";
    }
    else {
        cout << m << " ";
    }

    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }

    if (n <= k1 * a1) {
        cout << n / k1 << endl;
    }
    else {
        n -= k1 * a1;
        cout << n / k2 + a1 << endl;
    }


    return 0;
}