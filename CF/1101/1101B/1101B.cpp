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

string s;

int d[500005][8];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    
    int n = s.length();
    s = '0' + s;
    FOR (j, 1, 5) d[0][j] = -INF;
    FOR (i, 1, n) {
    	FOR (j, 1, 5) d[i][j] = d[i - 1][j];
    	if (s[i] == '[') {
    		d[i][1] = max(d[i][1], d[i - 1][0] + 1);
    	}
    	if (s[i] == ':') {
    		d[i][2] = max(d[i][2], d[i - 1][1] + 1);
    		d[i][4] = max(d[i][4], d[i - 1][3] + 1);
    		d[i][4] = max(d[i][4], d[i - 1][2] + 1);
    	}
    	if (s[i] == '|') {
    		d[i][3] = max(d[i][3], d[i - 1][3] + 1);
    		d[i][3] = max(d[i][3], d[i - 1][2] + 1);
    	}
    	if (s[i] == ']') {
    		d[i][5] = max(d[i - 1][4] + 1, d[i][5]);
    	}
    }
    if (d[n][5] < 0) {
    	cout << -1 << endl;
    }
    else cout << d[n][5] << endl;


    return 0;
}