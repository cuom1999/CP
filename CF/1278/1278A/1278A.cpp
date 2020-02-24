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
    int t;
    cin >> t;
    FOR (z, 1, t) {
        string s, t;
        cin >> s >> t;
        sort(all(s));
        int n = t.size();
        int m = s.size();
        bool good = 0;
        FOR (i, 0, n - m) {
            string k = t.substr(i, s.size());
            sort(all(k));
            // cout << i << " " << s << " " << k << endl;
            if (s == k) {
                cout << "YES\n";
                good = 1;
                break;
            }
        }
        if (!good) cout << "NO\n";
    }


    return 0;
}