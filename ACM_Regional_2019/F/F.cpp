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
typedef pair < ld, ld > DD;

ld a[100005], b[100005], d[100005], x[100005], y[100005];
int n, t;
    
// x = x + eps, val = val + diff - cost
// cost = 0 -> val = sum a
// cost = INF -> val = sum b
ld solve(ld cost) { 
    FOR (i, 1, n) {
        x[i] = (cost * y[i] - sq(eps)) / (2 * eps);
        if (x[i] < a[i]) x[i] = a[i];
        if (x[i] > b[i]) x[i] = b[i];
    }

    ld val = 0;
    FOR (i, 1, n) {
        val += x[i]; 
    }
    return val;
}   

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> t;

    ld sum = 0;
    FOR (i, 1, n) {
        cin >> a[i] >> b[i] >> d[i];
        sum += d[i];
    }

    FOR (i, 1, n) {
        x[i] = d[i] / sum * t;
        y[i] = x[i];
    }

    ld lower = 0, upper = 1e9;
    FOR (i, 1, 200) {
        ld mid = (lower + upper) / 2;
        if (solve(mid) < t) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }
    FOR (i, 1, n) {
        cout << fixed << setprecision(8) << x[i] << "\n";
    }

    return 0;
}