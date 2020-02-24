#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

const ld PI = acos(-1.0);
int n;
ld t[100005], s[100005], a[100005];

ld calc(ld x) {
    ld res = 0;
    FOR (i, 1, n) {
        ld dist = abs(a[i] - x);
        if (dist > PI) dist = 2 * PI - dist;
        res += max((ld) 0.0, t[i] - s[i] * dist); 
    }
    return res;
}

ld findMax(ld lower, ld upper) {
    ld res = calc(lower);
    res = max(res, calc(upper));
    
    FOR (i, 1, 50) {
        ld midL = (2 * lower + upper) / 3;
        ld midR = (lower + 2 * upper) / 3;

        if (calc(midL) > calc(midR)) {
            upper = midR;
        }
        else {
            lower = midL;
        }
    }
    res = max(res, calc(lower));
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n) {
        cin >> t[i] >> s[i] >> a[i];
    }
    ld res = 0;
    FOR (i, 0, 19) {
        res = max(res, findMax(2 * PI * i / 20, 2 * PI * (i + 1) / 20));
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}