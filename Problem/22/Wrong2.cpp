#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

ll dp[1005][1005];
vector<char> parenStack;

ll a, b, c, d, e, f;
string s;

ll dist[1005][1005];
const int MAXN = 1001;



ll calc (ll i, ll j) { // i ) and j (
	if (dp[i][j] != -1) return dp[i][j];
	if (i == 0 && j == 0) return 0;
	ll res = 1e18;
	if (j >= 2) res = min(res, calc(i, j - 2) + a);
	if (i >= 2) res = min(res, calc(i - 2, j) + b);
	if (i >= 1) res = min(res, calc(i - 1, j) + min(c, d));
	if (j >= 1) res = min(res, calc(i, j - 1) + min(c, e));
	if (i >= 1 && j >= 1) res = min(res, calc(i - 1, j - 1) + f);
	if (j == 1 && i) res = min(res, calc(i + 1, 0) + a);
	if (i == 1 && j) res = min(res, calc(0, j + 1) + b);
	//cout << i << " " << j << " " << res << endl;
	return dp[i][j] = res;
}



int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        parenStack.clear();
        cin >> s;
        cin >> a >> b >> c >> d >> e >> f;

        //remove unnecessary parentheses

        for (int i = 0; i < s.length(); i++) {
        	if (s[i] == '(') {
        		parenStack.pb(s[i]);
        	} 
        	else {
        		if (!parenStack.size() || parenStack.back() == ')') {
        			parenStack.pb(s[i]);
        		}
        		else {
        			parenStack.pop_back();
        		}
        	}
        }


        ll numOpen = 0, numClose = 0;

        for (int i = 0; i < parenStack.size(); i++) {
        	if (parenStack[i] == ')') numClose++;
        	else numOpen++;
        }

        FOR (i, 0, 1000) {
        	FOR (j, 0, 1000) dp[i][j] = -1;
        }
        dp[0][0] = 0;
    	cout << calc(numClose, numOpen) << endl;	
    }
    return 0;
}