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
        cout << "Case #" << z << ": ";
        set<int> v[505];
        int n, s;
        cin >> n >> s;

        FOR (i, 1, n) {
            int a;
            cin >> a;
            FOR (j, 1, a) {
                int x;
                cin >> x;
                v[i].insert(x);
            }
        }

        ll res = 0;
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                bool isGood = 0;
                for (auto k: v[i]) {
                    if (v[j].find(k) == v[j].end()) {
                        isGood = 1;
                        break;
                    }
                }
                res += isGood;
            }
        }

        cout << res << "\n";
    }



    return 0;
}