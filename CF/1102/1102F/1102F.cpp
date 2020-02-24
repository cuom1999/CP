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

int a[18][10005];
int cost1[18][18];
int cost2[18][18]; // dau - cuoi

int n, m;
inline int abs(int x) {
	if (x < 0) return -x;
	return x;
}

int d[(1 << 16) + 1][17][17];

int calc(int bit, int start, int end) {
	if (popcnt(bit) == 1) return INF;
	if (popcnt(bit) == 2) return cost1[start][end];
	if (d[bit][start][end] != -1) return d[bit][start][end];
	int newBit = bit - (1 << (end - 1));
	int val = 0;
	FOR (i, 0, n - 1) {
		if ((1 << i) & bit) {
			int j = i + 1;
			if (j == end || j == start) continue;
			val = max(val, min(calc(newBit, start, j), cost1[end][j]));
		}
	}
	return d[bit][start][end] = val; 
}


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;

    FOR (i, 1, n) {
    	FOR (j, 1, m) cin >> a[i][j];
    }
    if (n == 1) {
    	int res = INF;
    	FOR (i, 1, m - 1) {
    		res = min(res, abs(a[1][i + 1] - a[1][i]));
    	}
    	cout << res << endl;
    	return 0;
    }
    FOR (i, 0, (1 << n)) {
    	FOR (j, 1, n) {
    		FOR (k, 1, n) d[i][j][k] = -1;
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, n) {
    		cost1[i][j] = INF;
    		FOR (k, 1, m) {
    			cost1[i][j] = min(cost1[i][j], abs(a[i][k] - a[j][k]));
    		}
    		cost2[i][j] = INF;
    		FOR (k, 1, m - 1) {
    			cost2[i][j] = min(cost2[i][j], abs(a[i][k + 1] - a[j][k]));
    		}
    		//cout << i << " " << j << " " << cost1[i][j] << " " << cost2[i][j] << endl;
    	}
    }

    int res = 0;
    FOR (i, 1, n) {
    	FOR (j, 1, n) {
    		if (i == j) continue;
    		res = max(res, min(calc((1 << n) - 1, i, j), cost2[i][j]));
    	}
    }

    cout << res << endl;
    //cout << cost1[2][1] << endl;
    //cout << calc(3, 1, 2) << endl;

    
	
    return 0;
}