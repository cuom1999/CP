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

II solve(int n, int threshold) {
    int m = sqrt(n);
    FORD (i, m, 1) {
        if (n % i == 0) {
            int j = n / i;
            if (j <= i) continue;
            if ((i + j) % 2 == 0) {
                if ((j - i) / 2 > threshold) {
                    return {(j - i) / 2, (j + i) / 2};
                }
            } 
        }
    }

    return {-1, -1};
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> res;
    res.pb(0);
    FOR (i, 1, n / 2) {
        int x;
        cin >> x;
        auto u = solve(x, res.back());
        if (u.first < 0) {
            cout << "No";
            return 0;
        }
        res.pb(u.first);
        res.pb(u.second);
    }
    vector<ll> ans;    
    FOR (i, 1, n) {
        ll val = sq(res[i]) - sq(res[i - 1]);
        ans.pb(val);
        if (val <= 0) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (auto i: ans) cout << i << " ";

    return 0;
}