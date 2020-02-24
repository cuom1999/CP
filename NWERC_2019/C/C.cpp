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

int l[1005], r[2005], cnt[2005], x[2005];
map<int, int> used;


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> l[i] >> r[i];
        cnt[i] = 2;
    }
    int q;
    cin >> q;
    
    FOR (i, 1, q) {
        cin >> x[i];
        used[x[i]] = 1;
        FOR (j, 1, n) {
            if (l[j] <= x[i] && x[i] <= r[j]) cnt[j]--;
        }
    }

    FOR (i, 1, n) {
        if (cnt[i] < 0) {
            cout << "impossible";
            return 0;
        }
    }

    vector<int> res;
    FOR (i, 1, n) {
        if (cnt[i] == 0) continue;
        if (cnt[i + 1] > 0 && r[i] == l[i + 1] && !used[r[i]]) {
            cnt[i]--;
            cnt[i + 1]--;
            res.pb(r[i]);
        }
        FOR (j, 1, 10) {
            if (!cnt[i]) break;
            if (!used[l[i] + j]) {
                used[l[i] + j] = 1;
                res.pb(l[i] + j);
                cnt[i]--;
            }
        }

    }

    cout << res.size() << endl;
    for (auto i: res) {
        cout << i << " ";
    }


    return 0;
}