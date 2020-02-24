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

ld v0 = 1.0/60;
ld v1 = 1.0/(12 * 60);

vector<ld> vec(ld alpha) {
    vector<ld> res;
    FOR (k, 0, 30) {
        ld s = k + alpha;
        ld t = s / (v0 - v1);
        if (t < 24 * 60) {
            res.pb(t);
        }
    }
    return res;
}

ld trans(string s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    vector<ld> v[190];
    v[0] = vec(0);
    v[90] = vec(0.25);
    auto tmp = vec(0.75);
    for (auto i: tmp) v[90].pb(i);
    v[180] = vec(0.5);

    int t;
    cin >> t;


    FOR (z, 1, t) {
        string s1, s2;
        int alpha;
        cin >> s1 >> s2 >> alpha;
        ld t1 = trans(s1);
        ld t2 = trans(s2);
        int res = 0;
        for (auto i: v[alpha]) {
            if ((t1 <= i && i <= t2) || (abs(t1 - i) < eps) || (abs(t2 - i) < eps)) {
                res++;
            }
        }
        cout << res << '\n';
    }

    return 0;
}