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
typedef pair < II, int > III;
typedef pair < ld, int > ID;

vector<III> adj[100005];
vector<int> tree[100005];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        vector<int> deg(n + 1), used(n + 1);

        FOR (i, 1, n) {
            adj[i].clear();
            tree[i].clear();
        }

        FOR (i, 1, n - 2) {
            int a[3];
            FOR (j, 0, 2) {
                cin >> a[j];
                deg[a[j]]++;
            }
            FOR (j, 0, 2) {
                adj[a[j]].pb({{a[(j + 1) % 3], a[(j + 2) % 3]}, i});
            }
        }

        priority_queue<II, vector<II>, greater<II>> pq;
        FOR (i, 1, n) {
            pq.push({deg[i], i});
        }

        vector<int> resQ, pos;
        while(pq.size()) {
            II u = pq.top();
            pq.pop();
            if (u.first != deg[u.second] || !u.first) continue;
            used[u.second] = 1;
            for (auto j: adj[u.second]) {
                auto i = j.first;
                if (!used[i.first] && !used[i.second]) {
                    // used[i] = 1;
                    resQ.pb(j.second);
                    deg[i.first]--;
                    deg[i.second]--;
                    tree[u.second].pb(i.first);
                    tree[u.second].pb(i.second);
                    // tree[i.first].pb(u.second);
                    // tree[i.second].pb(u.second);
                    pq.push({deg[i.first], i.first});
                    pq.push({deg[i.second], i.second});
                }
            }
            deg[u.second] = 0;
            pos.pb(u.second);
            // cout << u.second << endl;
            // FOR (i, 1, n) cout << deg[i] << " ";
            // cout << endl;
        }

        FOR (i, 1, n) {
            cout << i << ": ";
            for (auto j: tree[i]) cout << j << " ";
            cout << endl;
        }

        for (auto i: resQ) cout << i << " ";
        cout << "\n";
    }


    return 0;
}