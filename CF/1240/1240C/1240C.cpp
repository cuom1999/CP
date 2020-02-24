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
typedef pair < ll, II > Edge;

int deg[500005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s = "Abcv";
    s += "bcd";
    cout << s << endl;
    return 0;
    int t;
    cin >> t;

    FOR (z, 1, t) {
        int n, k;
        cin >> n >> k;
        FOR (i, 1, n) deg[i] = 0;
        vector<Edge> e;
        FOR (i, 1, n - 1) {
            int x, y;
            ll z;
            cin >> x >> y >> z;
            e.pb({z, {x, y}});
        }   
        sort(all(e));
        reverse(all(e));
        ll res = 0;
        FOR (i, 0, n - 2) {
            if (deg[e[i].second.first] < k && deg[e[i].second.second] < k) {
                deg[e[i].second.first]++;
                deg[e[i].second.second]++;
                res += e[i].first;
            }
        }
        cout << res << "\n";
    }


    return 0;
}