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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a;

    b.resize(n);
    FOR (i, 0, k - 1) b[i] = a[i];
    FOR (i, k, n - 1) b[i] = b[i - k];

    bool isSmaller = 0;
    FOR (i, 0, n - 1) {
        if (b[i] > a[i]) {
            isSmaller = 0;
            break;
        }
        if (a[i] > b[i]) {
            isSmaller = 1;
            break;
        }
    }
    cout << a.size() << endl;
    if (!isSmaller) {
        cout << b << endl;
    }
    else {
        FORD (i, k - 1, 0) {
            b[i] += 1;
            if (b[i] <= '9') break;
            b[i] = '0';
        }
        FOR (i, k, n - 1) b[i] = b[i - k];
        cout << b << endl;
    }


    return 0;
}