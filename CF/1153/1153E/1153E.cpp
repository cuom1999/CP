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

int n;

int X1, Y1, X2, Y2;
int cnt = 0;
int ask(int x1, int y1, int x2, int y2) {
	assert(x1 <= x2 && y1 <= y2 && 1 <= x1 && x2 <= n && 1 <= y1 && y2 <= n);
	// cnt++;

	// int res = 0;
	// if (x1 <= X1 && X1 <= x2 && y1 <= Y1 && Y1 <= y2) res++;
	// if (x1 <= X2 && X2 <= x2 && y1 <= Y2 && Y2 <= y2) res++;
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int res;
	cin >> res;

	return res % 2;
}
int c1, c2, r1, r2;
    
int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    // cin >> X1 >> Y1 >> X2 >> Y2;

    bool isOdd = 0;
    FOR (i, 1, n) {
    	int q = ask(1, 1, i, n);
    	if (q && !isOdd) {
    		isOdd = 1;
    		r1 = i;
    	}
    	if (!q && isOdd) {
    		isOdd = 0;
    		r2 = i;
    	}
    }

    isOdd = 0;
    FOR (i, 1, n) {
    	int q = ask(1, 1, n, i);
    	if (q && !isOdd) {
    		isOdd = 1;
    		c1 = i;
    	}
    	if (!q && isOdd) {
    		isOdd = 0;
    		c2 = i;
    	}
    }

    // cout << r1 << " " << r2 << " " << c1 << " " << c2 << endl;

    if (r1 && r2 && c1 && c2) {
    	int q = ask(r1, c1, r1, c1);
    	if (!q) {
    		swap(c1, c2);
    	}
    }
    else if (!r1) {
    	int L = 1, R = n;

    	while (L < R) {
    		int mid = (L + R) / 2;
    		int q = ask(1, 1, mid, c1);
    		if (q) R = mid;
    		else L = mid + 1;
    	}
    	r1 = r2 = L;
    }
    else {
		int L = 1, R = n;

    	while (L < R) {
    		int mid = (L + R) / 2;
    		int q = ask(1, 1, r1, mid);
    		if (q) R = mid;
    		else L = mid + 1;
    	}
    	c1 = c2 = L;
    }

    cout << "! " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
	// cout << cnt << endl;
    return 0;
}