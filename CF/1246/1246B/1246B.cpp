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

bool cmp(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return (a.size() <= b.size());
}

int trace[100005];

void sieve() {
    FOR (i, 2, 100000) {
        if (!trace[i]) {
            FOR (j, 1, 100000 / i) {
                trace[i * j] = i;
            }
        }
    }
}

int ind[350], k;
vector<vector<int>> bucket[100005];

void factor(int x) {
    int b = 0;
    if (trace[x] >= 316) {
        b = trace[x];
        x /= trace[x];
    }

    vector<int> v(65);

    while (x > 1) {
        int u = trace[x];
        int cnt = 0;
        while (x % u == 0) {
            x /= u;
            cnt++;
        }
        v[ind[u]] = cnt % k;
    }

    bucket[b].pb(v);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n >> k;
    sieve();

    
    int cnt = 0;
    FOR (i, 2, 316) {
        if (trace[i] == i) {
            ind[i] = cnt++;
        }
    }

    FOR (i, 1, n) {
        int x;
        cin >> x;
        factor(x);
    }

    ll res = 0;
    FOR (b, 0, 100000) {
        if (bucket[b].size() == 0) continue;
        if (b && k > 2) continue;
        sort(all(bucket[b]));
        for (auto &v: bucket[b]) {
            vector<int> vc(65);

            FOR (i, 0, 64) {
                vc[i] = (k - v[i]) % k;
            }

            res += upper_bound(all(bucket[b]), vc) - lower_bound(all(bucket[b]), vc);
            if (v == vc) res--;
        }
    }
    cout << res / 2 << endl;

    return 0;
}