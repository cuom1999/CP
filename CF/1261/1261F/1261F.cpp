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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<II> v;
    FOR (i, 0, n - 1) {
        cin >> a[i];
        v.pb({a[i], i});
    }
    sort(all(v));
    reverse(all(v));

    vector<string> res(n + 1, string(n, '0'));
    FOR (i, 0, n - 1) {
        FOR (j, 0, v[i].first - 1) {
            res[(j + i) % (n + 1)][v[i].second] = '1';
        }
    }
    cout << n + 1 << '\n';
    FOR (i, 0, n) {
        cout << res[i] << "\n";
    }
    return 0;
}