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

int a[1000005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
    }

    int need = 0;

    FOR (i, 2, n) {
        if (a[i] < a[i - 1]) {
            need = i - 1;
            break;
        }
    }
    if (!need) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    int last = n + 1;

    FOR (i, need + 1, n) {
        if (a[i] > a[i - 1]) {
            last = i;
            break;
        } 
    }

    while (need >= 2 && a[need] == a[need - 1]) need--;
    reverse(a + need, a + last);

    FOR (i, 1, n - 1) {
        if (a[i] > a[i + 1]) {
            cout << "impossible";
            return 0;
        }
    }
    cout << need << " " << last - 1 << endl;

    return 0;
}