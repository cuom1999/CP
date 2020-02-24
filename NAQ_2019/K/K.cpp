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
    int n = s.size();

    vector<int> v[26];
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'].pb(i);
    }
    FOR (i, 0, 25) v[i].pb(n);

    ll res = 0;
    FOR (c, 0, 25) {
        for (int i = 0; i + 1 < v[c].size(); i++) {
            FOR (k, 0, 25) {
                if (k == c) continue;
                int u = *lower_bound(all(v[k]), v[c][i]);
                if (u < v[c][i + 1]) {
                    res++;
                }
            }
        }   
    }

    cout << res << endl;

    return 0;
}