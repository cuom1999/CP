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

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    set<int> s;
    map<int, int> tree;
    set<int> inUse;
    FOR (i, 1, n) {
        cin >> a[i];
        s.insert(a[i]);
        tree[a[i]] = 1;
        inUse.insert(i);
    }

    ll res = 0;
    FOR (d, 1, m) {
        vector<int> tmp;
        for (auto i: inUse) {
            int isGood = 0;
            if (s.find(a[i] - d) == s.end()) {
                s.insert(a[i] - d);
                res += d;
                if (s.size() >= n + m) {
                    break;
                }
                isGood++;
            }
            if (s.find(a[i] + d) == s.end()) {
                s.insert(a[i] + d);
                res += d;
                if (s.size() >= n + m) {
                    break;
                }
                isGood++;
            }
            if (!isGood) tmp.pb(i);
        }
        for (auto j: tmp) inUse.erase(j);
        if (s.size() >= n + m) break;
    } 

    cout << res << "\n";
    for (auto i: s) if (!tree[i]) cout << i << ' ';

    return 0;
}