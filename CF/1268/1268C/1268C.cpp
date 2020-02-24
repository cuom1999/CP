#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


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
using namespace __gnu_pbds;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexedTree;

int a[200005], pos[200005];
indexedTree s;

ll sum0(int a) {
    return a * 1ll * (a + 1) / 2;
}

int main()
{IN; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    ll sumMin = 0, sumMax = 0, invCnt = 0;
    FOR (i, 1, n) {
        s.insert(pos[i]);
        int u = s.order_of_key(pos[i]);

        invCnt += i - 1;
        invCnt -= u;

        if (i % 2 == 0) {
            if (u <= i / 2 - 1) {
                int val = *s.find_by_order(i / 2);
                sumMin += pos[i];
                sumMax += val;
            }
            else {
                int val = *s.find_by_order(i / 2 - 1);
                sumMin += val;
                sumMax += pos[i];
            }
        }
        else {
            if (u <= i / 2 - 1) {
                int val = *s.find_by_order(i / 2);
                sumMin -= val;
                sumMin += pos[i];
            }
            else if (u > i / 2) {
                int val = *s.find_by_order(i / 2);
                sumMax -= val;
                sumMax += pos[i];
            }
        }

        ll res = invCnt + sumMax - sumMin - sum0(i - 1) + sum0((i + 1) / 2 - 1) + sum0(i / 2 - 1);
        cout << res << " "; 
        // cout << i << " " << invCnt << " " << sumMin << " " << sumMax << endl;
    }
    
    return 0;
}