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

map<string, map<string, int>> eq;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        FOR (j, 1, m) {
            int u;
            string v;
            cin >> u >> v;
            eq[s][v] = u;
        }
    }

    string final;
    cin >> final;

    map<string, int> res;
    res[final] = 1;

    while(1) {
        bool need = 0;
        for (auto i: res) {
            if (i.second == 0) continue;
            if (eq[i.first].size()) {
                need = 1;
                for (auto j: eq[i.first]) {
                    res[j.first] += i.second * j.second;
                }
                res[i.first] = 0;
            }
        }
        if (!need) break;
    }

    for (auto i: res) {
        if (i.second) {
            cout << i.first << " " << i.second << endl;
        }
    }

    return 0;
}