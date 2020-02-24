#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("cowmbat.in","r",stdin)
#define OUT freopen("cowmbat.out","w",stdout)
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

int d[30005][55][26];
int cost[26][26];
int n, m, k;
string s;

int dp(int index, int len, int c) {
    if (index == n) {
        if (len < k) return INF;
        return 0;
    }
    int &res = d[index][len][c];
    if (res != -1) return res;
    res = INF;
    
    int curChar = s[index] - 'a';
    if (len >= k) {
        int newLen;
        FOR (i, 0, m - 1) {
            if (i == c) {
                newLen = k;
            }
            else {
                newLen = 1;
            }
            res = min(res, dp(index + 1, newLen, i) + cost[curChar][i]);
        }
    }
    else {
        res = min(res, dp(index + 1, len + 1, c) + cost[curChar][c]);
    }
    // cout << index << " " << len << " " << c << " " << res << endl;  
    if (res > INF) res = INF;
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k;
    cin >> s;

    FOR (i, 0, m - 1) {
        FOR (j, 0, m - 1) {
            cin >> cost[i][j];
        }
    }

    FOR (k, 0, m - 1) {
        FOR (i, 0, m - 1) {
            FOR (j, 0, m - 1) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }   
    }

    int firstChar = s[0] - 'a';
    int res = INF;
    memset(d, -1, sizeof(d));
    FOR (i, 0, m - 1) {
        res = min(res, dp(1, 1, i) + cost[firstChar][i]);
    }

    cout << res << endl;

    return 0;
}