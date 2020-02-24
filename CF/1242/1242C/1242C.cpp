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

unordered_map<ll, int> bucket;
unordered_map<ll, vector<ll>> cycle;
vector<ll> v[20];
vector<int> sub[35000];
ll s[25];

int l[35000], r[35000];
int g[35000];
vector<int> res;

void split(int x) {
    if (l[x] == x) {
        res.pb(x);
        return;
    }
    split(l[x]);
    split(r[x]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    FOR (i, 1, n) {
        int x;
        cin >> x;
        FOR (j, 1, x) {
            ll m;
            cin >> m;
            v[i].pb(m);
            bucket[m] = i;
            s[i] += m;
        }
    }

    ll sum = 0;
    FOR (i, 1, n) {
        for (auto j: v[i]) sum += j;
    }

    if (sum % n) {
        cout << "No";
        return 0;
    }

    sum /= n;

    FOR (i, 1, n) {
        for (auto j: v[i]) {
            vector<bool> used(n + 1);
            used[i] = 1;
            
            int curr = i;
            ll curVal = j;
            cycle[curVal].pb(curVal);
            bool good = 1;

            while(1) {
                ll val = curVal - s[curr] + sum;
                if (!bucket.count(val)) {
                    good = 0;
                    break;
                }
                curVal = val;
                curr = bucket[curVal];
                if (used[curr]) break;
                cycle[j].pb(curVal);
                used[curr] = 1;
            }

            if (curr == i && curVal == j && good) {
                int val = 0;
                for (auto k: cycle[j]) {
                    val |= (1 << (bucket[k] - 1));
                }
                sub[val].pb(j);
                l[val] = val;
                g[val] = 1;
            }
        }
    }

    FOR (i, 0, (1 << n) - 1) {
        if (g[i]) continue;

        for (int j = i; j; j = (j - 1) & i) {
            int k = i ^ j;
            if (g[j] && g[k]) {
                g[i] = 1;
                l[i] = j;
                r[i] = k;
                break;
            }
        }
    }

    int cur = (1 << n) - 1;
    split(cur);

    vector<int> p(n + 1);
    vector<ll> c(n + 1);

    for (auto i: res) {
        ll u = sub[i][0];
        cycle[u].pb(cycle[u][0]);
        for (int j = 0; j + 1 < cycle[u].size(); j++) {
            p[bucket[cycle[u][j + 1]]] = bucket[cycle[u][j]]; 
            c[bucket[cycle[u][j]]] = cycle[u][j + 1];
        }
    }

    cout << "Yes\n";
    FOR (i, 1, n) {
        cout << c[p[i]] << " " << p[i] << endl;
    }
    return 0;
}