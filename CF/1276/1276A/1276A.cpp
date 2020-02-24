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
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    FOR (z, 1, t) {
        vector<int> res;

        string s;
        cin >> s;
        int n = s.size();
        vector<bool> used(n);

        FOR (i, 0, n - 1) {
            if (i + 4 < n) {
                string tmp;
                FOR (j, i, i + 4) {
                    tmp += s[j];
                }
                if (tmp == "twone") {
                    res.pb(i + 2);
                    used[i + 1] = used[i + 3] = 1;
                }
            }
        }

        FOR (i, 0, n - 3) {
            string tmp;
            FOR (j, i, i + 2) {
                tmp += s[j];
            }
            if (tmp == "two" || tmp == "one") {
                if (!used[i + 1]) {
                    res.pb(i + 1);
                }
            }
        }
        cout << res.size() << "\n";
        for (auto i: res) cout << i + 1 << " ";
        cout << "\n";
    }


    return 0;
}