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

int dpNeg[1004][1004], dpPos[1004][1004], a[500005], p[500005];
int cost[500005];

int main()
{IN; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("output2.txt", "w", stdout);
    
    int n, r, c;
    cin >> n >> c >> r;

    vector<II> v;
    FOR (i, 1, n) {
        cin >> a[i];
        v.pb({abs(a[i]) + 1, i});
    }
    sort(v.begin(), v.end());

    int ind = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!i || v[i].first != v[i - 1].first) ind++;
        p[v[i].second] = ind;
        cost[ind] = v[i].first;
    }

    FOR (i, 1, n) {
        if (a[i] < 0) {
            FOR (j, 0, n) {
                dpNeg[i][j] = dpPos[i - 1][j];
                if (j < p[i]) {
                    dpPos[i][j] = dpPos[i - 1][j] + 1;
                }
                else {
                    dpPos[i][j] = dpNeg[i - 1][j];
                }
            }
        }
        else if (a[i] > 0) {
            FOR (j, 0, n) {
                dpPos[i][j] = dpNeg[i - 1][j];
                if (j < p[i]) {
                    dpNeg[i][j] = dpNeg[i - 1][j] + 1;
                }
                else {
                    dpNeg[i][j] = dpPos[i - 1][j];
                }
            }   
        }
        else {
            FOR (j, 0, n) {
                if (j < p[i]) {
                    dpNeg[i][j] = dpNeg[i - 1][j] + 1;
                    dpPos[i][j] = dpPos[i - 1][j] + 1;
                }
                else {
                    dpNeg[i][j] = dpPos[i - 1][j];
                    dpPos[i][j] = dpNeg[i - 1][j];
                }
            }   
        }

        FOR (j, 0, n) cout << dpNeg[i][j] << " ";
        cout << endl;
        FOR (j, 0, n) cout << dpPos[i][j] << " ";
        cout << endl;
        cout << endl;
    }

    ll res = 2e18;
    FOR (i, 0, ind) {
        ll val = min(dpPos[n][i], dpNeg[n][i]) * 1ll * r + c * 1ll * cost[i];
        res = min(res, val);
    }

    cout << res << endl;


    return 0;
}