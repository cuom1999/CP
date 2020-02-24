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

// void update(vector<int> used, int &maxVal) {
//     while (used[maxVal] && maxVal) maxVal--;
// }
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> used(n + 1);
    // int maxVal = n;
    set<int> s;
    FOR (i, 1, n) s.insert(i);

    int r;
    cin >> r;
    used[r] = 1;    
    // update(used, maxVal);
    s.erase(r);

    vector<pair<int, int>> edges;
    int last = r;

    FOR (i, 1, n - 2) {
        int x;
        cin >> x;
        if (!used[x]) {
            edges.pb({last, x});
            used[x] = 1;
            s.erase(x);
            // update(used, maxVal);
        }
        else {
            int maxVal = *(--s.end());
            
            edges.pb({last, maxVal});
            used[maxVal] = 1;
            // update(used, maxVal);
            s.erase(maxVal);
        }
        last = x;
    }
    edges.pb({last, *(s.begin())});

    cout << r << '\n';
    for (auto e: edges) {
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}