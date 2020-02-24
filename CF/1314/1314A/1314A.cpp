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
typedef pair < ll, ll > II;

ll a[200005], t[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    vector<II> v;
    priority_queue<II, vector<II>> pq;

    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
    }

    FOR (i, 1, n) {
        cin >> t[i];
    }

    FOR (i, 1, n) {
        v.pb({a[i], t[i]});
    }

    sort(all(v));

    ll cur = 0;
    int pos = 0;
    ll res = 0;

    while (pos < v.size() || pq.size()) {
        if (!pq.size()) {
            cur = v[pos].first;
            pq.push({v[pos].second, v[pos].first});
            pos++;
        }

        while (pos < v.size() && cur >= v[pos].first) {
            pq.push({v[pos].second, v[pos].first});
            cur = v[pos].first;
            pos++;
        }

        II u = pq.top();
        // cout << u.first << " "  << u.second << " " << cur << endl;
        res += max(0LL, cur - u.second) * u.first; 
        pq.pop();
        cur++;
    }

    cout << res << endl;

    return 0;
}