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

int a[105][105];
int res[105];
int m, n;
int row[105], col[105];

void count() { 
	FOR (i, 0, m - 1) row[i] = 0;
	FOR (i, 0, n - 1) col[i] = 0;
	FOR (i, 0, m - 1) { 
		FOR (j, 0, n - 1) { 
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	int cnt = 0;
	FOR (i, 0, m - 1) {
		FOR (j, 0, n - 1) { 
			if (a[i][j] && row[i] == 1 && col[j] == 1) cnt++;
		}
	}
	res[cnt]++;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);\
    cin >> m >> n;
    if (m < n) swap(m, n);

    FOR (i, 0, (1 << (m * n)) - 1) {
    	FOR (j, 0, (m * n) - 1) { 
    		if (i & (1 << j)) a[j / n][j % n] = 1;
    		else a[j / n][j % n] = 0;
    	} 
    	count();
    }

    int q;
    cin >> q;
    FOR (i, 1, q) {
        ll t;
        cin >> t;
        if (t <= n) {
            cout << res[t] << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}