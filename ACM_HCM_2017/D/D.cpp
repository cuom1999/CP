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

vector<char> a[100005];
int m, n;

int solve(int x, int y, int row){
	while (x < row){
		if (a[x][y] == '\\') {
			if (y == n) return -1;
			if (a[x][y + 1] == '/') return -1;
			x++;
			y++;
		}
		else{
			if (y == 1) return -1;
			if (a[x][y - 1] == '\\') return -1;
			x++;
			y--;
		}
	}
	return y;
}
int r[805][100005];
int st[805], en[805];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin >> m >> n >> q;
    FOR (i, 1, m) {
    	a[i].resize(n + 2);
    	FOR (j, 1, n) {
    		char c;
    		cin >> c;
    		a[i][j] = c;
    	}
    }
    if (n > m) {
    	FOR (z, 1, q) {
    		int t;
    		cin >> t;
    		if (t == 1) {
    			int x, y;
    			cin >> x >> y;
    			if (a[x][y] == '\\') a[x][y] = '/';
    			else a[x][y] = '\\';
    		}
    		else{
    			int y;
    			cin >> y;
    			cout << solve(1, y, m + 1) << endl;
    		}
    	}
    }
    else{
    	n = 1;
    	int S = sqrt(m * 1.0 / n);
    	int mS = (m - 1) / S;
    	FOR (m, 1, 100000) {
    		S = sqrt(m * 1.0 / n);
    		mS = (m - 1) / S;
    		if (mS >= 300) cout << m << " " << mS << endl;
    	}
    	return 0;
    	FOR (i, 0, mS) {
    		if (i < mS){
    			st[i] = i * S + 1;
    			en[i] = S * (i + 1) + 1;
    		}
    		else{
    			st[i] = i * S + 1;
    			en[i] = m + 1;
    		}
    	}
    	FOR (i, 0, mS) {
    		FOR (j, 1, n) {
    			r[i][j] = solve(st[i], j, en[i]);
    		}
    	}
    	FOR (z, 1, q) {
	    	int t;
	    	cin >> t;
	    	if (t == 1) {
	    		int x, y;
	    		cin >> x >> y;
	    		int u = (x - 1) / S;
	    		if (a[x][y] == '\\') a[x][y] = '/';
	    		else a[x][y] = '\\';

	    		FOR (j, 1, n) r[u][j] = solve(st[u], j, en[u]);
	    	}
	    	else{
	    		int y;
	    		cin >> y;
	    		FOR (i, 0, mS){
	    			y = r[i][y];
	    			if (y == -1) break;
	    		}
	    		cout << y << endl;
	    	}
	    }
    }
    
    
    
	
    return 0;
}