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
        int n;
        ll h;

        cin >> n >> h;
        
        vector<int> a(n), b(n);

        FOR (i, 0, n - 1) {
            cin >> a[i];
        }
        FOR (i, 0, n - 1) {
            cin >> b[i];
        }

        ll cntA = 0, cntB = 0;
        vector<int> goodA;
        vector<int> goodB(1 << n), sumSubset(1 << n);

        FOR (i, 0, (1 << n) - 1) {
            ll sumA = 0;
            ll sumB = 0;
            FOR (j, 0, n - 1) {
                if (i & (1 << j)) {
                    sumA += a[j];
                    sumB += b[j];
                }
            }   

            if (sumA >= h) goodA.pb(i);
            if (sumB >= h) goodB[i]++;
        }

        FOR (i, 0, (1 << n) - 1) sumSubset[i] = goodB[i];
    
        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                if ((mask & (1 << i)) == 0) {
                    sumSubset[mask] += sumSubset[mask^(1<<i)];
                }
            }
        }

        ll res = 0;
        for (auto i: goodA) {
            int rev = i ^ ((1 << n) - 1);
            res += sumSubset[rev];
        }

        cout << res << "\n";
    }


    return 0;
}
