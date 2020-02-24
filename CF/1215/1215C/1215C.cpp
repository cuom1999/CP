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
    string s, t;
    cin >> n >> s >> t;

    vector<int> v[2];
    FOR (i, 0, n - 1) {
        if (s[i] != t[i]) {
            if (s[i] == 'a') {
                v[0].pb(i);
            }
            else {
                v[1].pb(i);
            }
        }
    }

    if ((v[0].size() + v[1].size()) % 2) {
        cout << -1;
        return 0;
    }

    vector<II> res;
    FOR (j, 0, 1) {
        for (int i = 0; i + 1 < v[j].size(); i += 2) {
            res.pb({v[j][i], v[j][i + 1]});
        }
    }

    if (v[0].size() % 2) {
        res.pb({v[0].back(), v[0].back()});
        res.pb({v[0].back(), v[1].back()});
    }

    cout << res.size() << endl;
    for (auto i: res) cout << i.first + 1 << " " << i.second + 1 << "\n";


    return 0;
}