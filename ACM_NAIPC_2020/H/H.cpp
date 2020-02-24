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

string s[4];
const ll MOD = 1e9 + 9;
ll BASE = 12345678;
ll valChar[3];
    
ll toInt(string& s, int n) {
    ll res = 0;
    ll pw = 1;
    FOR (i, 0, n - 1) {
        res = (res + pw * valChar[s[i] - 'A']) % MOD;
        pw = pw * BASE % MOD;
    }
    return res;
}   

int main()      
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    ll sumValChar = 0;
    FOR (i, 0, 2) {
        valChar[i] = rand();
        sumValChar += valChar[i];
    }

    FOR (i, 1, 3) {
        cin >> s[i];
    }

    int n = s[1].size();

    ll rotation[4][5005];
    map<ll, int> cost;

    FOR (i, 1, 3) {
        FOR (j, 0, n - 1) {
            string tmp;
            FOR (k, 0, n - 1) {
                tmp += s[i][(j + k) % n];
            }
            rotation[i][j] = toInt(tmp, n);
            if (i == 3) {
                int val = min(j, n - j);
                if (cost.count(rotation[i][j])) {
                    cost[rotation[i][j]] = min(cost[rotation[i][j]], val);
                }
                else {
                    cost[rotation[i][j]] = val;
                }
            }
        }
    }

    ll sumAll = 0;
    ll pw = 1;

    FOR (i, 0, n - 1) {
        sumAll = (sumAll + pw * sumValChar) % MOD;
        pw = pw * BASE % MOD;
    }

    int res = INF;
    FOR (i, 0, n - 1) {
        FOR (j, 0, n - 1) {
            int curCost = min(i, n - i) + min(j, n - j);
            ll sum = (rotation[1][i] + rotation[2][j]) % MOD;
            ll req = (sumAll - sum + MOD) % MOD;
            if (cost.count(req)) {
                int val = curCost + cost[req];
                res = min(res, val);
            }
        }
    }

    if (res != INF) {
        cout << res << endl;
    }
    else cout << -1 << endl;


    return 0;
}