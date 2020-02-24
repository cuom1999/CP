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
typedef pair < ll, ll > II;

II a[100005];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }

    sort(a + 1, a + n + 1);

    ll maxVal = 0;
    ll res = 0;
    FORD (i, n, 1) {
        res = max(res, 2 * min(a[i].second, maxVal) * a[i].first);
        maxVal = max(maxVal, a[i].second);
    }   

    FOR (i, 1, n) {
        // s.insert
        res = max(res, a[i].first * a[i].second);
    }

    ll s = res / 2;
    cout << s;
    if (res % 2) {
        cout << ".5";
    }
    else cout << ".0";
    return 0;
}