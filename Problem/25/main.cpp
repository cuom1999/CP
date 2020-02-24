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

const int MAXN = 2005;

int a[MAXN][MAXN], s[MAXN][MAXN];

bool check(int x1, int y1, int x2, int y2) {
	int val = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
	if (val == (y2 - y1 + 1) * (x2 - x1 + 1)) return 1;
	return 0;
}

int res[MAXN];



int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
            char c;
            cin >> c;
            if (c == '.') a[i][j] = 1;
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		
    		if (!a[i][j]) continue;

    		int L = 0, R = min(n - i, m - j);
    		while (L < R) {
    			int mid = (L + R + 1) / 2;
    			if (check(i, j, i + mid, j + mid)) {
    				L = mid;
    			}
    			else {
    				R = mid - 1;
    			}
    		}
    		res[L + 1]++;
    	}
    }
    
    FORD (i, min(m, n), 1) res[i] += res[i + 1];

    FOR (i, 1, min(m, n)) cout << res[i] << endl;
	
    return 0;
}