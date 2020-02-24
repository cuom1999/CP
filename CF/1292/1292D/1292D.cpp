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

int trace[5005];
vector<int> path[5005];

const ll MOD = 1e9 + 9;
ll COEF = rand() * rand() * rand() % MOD;

vector<int> hashPath(vector<int>& p) {
    int n = p.size();
    
    vector<int> res(n);
    res[0] = p[0];
    ll cur = COEF;
    FOR (i, 1, n - 1) {
        res[i] = (res[i - 1] + cur * p[i]) % MOD;
        cur = cur * COEF % MOD;
    }
    return res;
}

int len[5005][5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    FOR (i, 2, 5000) {
        if (!trace[i]) {
            trace[i] = i;
            FOR (j, 1, 5000 / i) {
                if (!trace[i * j]) trace[i * j] = i;
            }
        }
    }

    FOR (i, 1, 5000) {
        int a = i;
        vector<int> cnt(5005);
        FOR (j, 1, a) {
            int cur = j;
            while (cur > 1) {
                cnt[trace[cur]]++;
                cur /= trace[cur];
            }
        }
        FOR (j, 2, 5000) {
            FOR (k, 1, cnt[j]) {
                path[i].pb(j);
            } 
        }
        reverse(all(path[i]));
    }
    
    FOR (i, 2, 5000) {
        path[i] = hashPath(path[i]);
    }

    FOR (i, 2, 5000) {
        len[1][i] = len[i][1] = path[i].size();
        FOR (j, i + 1, 5000) {
            int lower = -1, upper = min(path[i].size(), path[j].size()) - 1;
            while (lower < upper) {
                int mid = (lower + upper + 1) / 2;
                if (path[i][mid] == path[j][mid]) {
                    lower = mid;
                }
                else {
                    upper = mid - 1;
                }
            }
            len[i][j] = len[j][i] = path[i].size() + path[j].size() - 2 * (lower + 1);
            // if (i == 3 && j == 4) cout <<  
        }
    }

    int n;
    cin >> n;
    vector<int> cnt(5005);
    FOR (i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll res = 1e18;
    FOR (i, 1, 5000) {
        ll val = 0;
        FOR (j, 1, 5000) {
            val += cnt[j] * 1ll * len[i][j];
        }
        res = min(res, val);
    }

    cout << res << endl;
    return 0;
}