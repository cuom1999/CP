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

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree<II,null_type,less<II>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        cout << "Case " << z << ":\n";
        priority_queue<II, vector<II>, greater<II>> pq;
        int n;
        cin >> n;
        IndexTree s;
        vector<int> a(n + 1);

        FOR (q, 1, n) {
            int op;
            cin >> op;
            if (op == 1) {
                int curTime, val, endTime;
                cin >> curTime >> val >> endTime;
                a[q] = val;
                pq.push({endTime, q});
                s.insert({val, q});
            }
            else {
                int curTime, k;
                cin >> curTime >> k;
                while (pq.size()) {
                    II u = pq.top();
                    if (u.first < curTime) {
                        s.erase(s.find({a[u.second], u.second}));
                        pq.pop();
                    }
                    else break;                    
                }
                assert(pq.size() == s.size());
                // cout << q << " " << k << endl;
                if (k > s.size()) {
                    cout << -1 << "\n";
                }
                else {
                    II res = *s.find_by_order(k - 1);
                    cout << res.first << '\n';
                }
            }
            // for (auto i: )
        }
    }

    return 0;
}