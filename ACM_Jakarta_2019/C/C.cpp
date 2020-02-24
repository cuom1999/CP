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
    int n, q;
    cin >> n >> q;
    vector<int> r(n + 1), c(n + 1), sr(n + 1), sc(n + 1);

    FOR (i, 1, n) {
        cin >> r[i];
        r[i] %= 2;
        sr[i] = sr[i - 1] + r[i];
    }

    FOR (i, 1, n) {
        cin >> c[i];
        c[i] %= 2;
        sc[i] = sc[i - 1] + c[i];
    }

    FOR (z, 1, q) {
        int ra, rb, ca, cb;
        cin >> ra >> ca >> rb >> cb;
        if (ra > rb) swap(ra, rb);
        if (ca > cb) swap(ca, cb);

        int u = sr[rb] - sr[ra - 1];
        int v = sc[cb] - sc[ca - 1];
        if ((u == 0 || u == rb - ra + 1) && (v == 0 || v == cb - ca + 1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}