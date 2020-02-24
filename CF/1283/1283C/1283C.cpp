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

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> gave(n + 1), given(n + 1);

    FOR (i, 1, n) {
        cin >> a[i];
        if (a[i]) {
            gave[i] = 1;
            given[a[i]] = 1;
        }
    }


    vector<int> fixedPoints;
    FOR (i, 1, n) {
        if (!gave[i] && !given[i]) {
            fixedPoints.pb(i);
        }
    }

    if (fixedPoints.size() > 1) {
        for (int i = 0; i < fixedPoints.size(); i++) {
            a[fixedPoints[i]] = fixedPoints[(i + 1) % fixedPoints.size()];
        }
        for (auto i: fixedPoints) {
            given[i] = gave[i] = 1;
        }
    }
    int special = -1;

    if (fixedPoints.size() == 1) {
        special = fixedPoints[0];
        given[special] = gave[special] = 1;
    }

    vector<int> give, receive;
    FOR (i, 1, n) {
        if (!gave[i]) give.pb(i);
        if (!given[i]) receive.pb(i);
    }

    if (special != -1) {
        a[special] = receive[0];
        receive[0] = special;
    }

    for (int i = 0; i < give.size(); i++) {
        a[give[i]] = receive[i];
    }   

    FOR (i, 1, n) cout << a[i] << " ";

    return 0;
}