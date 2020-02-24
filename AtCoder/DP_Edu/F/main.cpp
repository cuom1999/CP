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

int d[3005][3005];

string s, t;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s >> t;

    int m = s.length();
    int n = t.length();

    s = '0' + s;
    t = '1' + t;

    FOR (i, 1, m) {
    	FOR (j, 1, n) {
    		if (s[i] == t[j]) {
    			d[i][j] = d[i - 1][j - 1] + 1;
    		}
    		else {
    			d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    		}
    	}
    }

	string res;

	int traceM = m, traceN = n;

	while (traceM && traceN) {
		if (s[traceM] == t[traceN]) {
			res += s[traceM];
			traceM--;
			traceN--;
		}
		else {
			if (d[traceM - 1][traceN] > d[traceM][traceN - 1]) {
				traceM--;
			}
			else {
				traceN--;
			}
		}
	}

	reverse(all(res));
	cout << res << endl;   
	
    return 0;
}