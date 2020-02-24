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

int x[105], y[105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int k, n;
    int t;
    cin >> t;

    FOR (z, 1, t) {
    	cin >> k >> n;
    	FOR (i, 1, k) cin >> x[i] >> y[i];
	    
	    if (k >= 4) {
	    	cout << "yes" << endl;
	    	continue;
	    }

	    bool res = 0;
	    FOR (i, 1, k) {
	    	if (x[i] == 0 && y[i] == 0) res = 1;
	    	if (x[i] == 0 && y[i] == n - 1) res = 1;
	    	if (x[i] == n - 1 && y[i] == 0) res = 1;
	    	if (x[i] == n - 1 && y[i] == n - 1) res = 1;
	    }
	    if (k == 2) {
	    	if (x[1] == 0 && x[2] == 0) res = 1;
	    	if (x[1] == n - 1 && x[2] == n - 1) res = 1;
	    	if (x[1] == 0 && x[2] == n - 1) res = 1;
	    	if (x[1] == n - 1 && x[2] == 0) res = 1;


	    	if (y[1] == 0 && y[2] == 0) res = 1;
	    	if (y[1] == n - 1 && y[2] == n - 1) res = 1;
			if (y[1] == 0 && y[2] == n - 1) res = 1;
	    	if (y[1] == n - 1 && y[2] == 0) res = 1;
	    }
	    else if (k == 3) {
	    	FOR (i, 1, 3) {
	    		FOR (j, i + 1, 3) {
	    			if (x[i] == 0 && x[j] == 0) res = 1;
	    			if (x[i] == n - 1 && x[j] == n - 1) res = 1;
	    			if (x[i] == 0 && x[j] == n - 1) res = 1;
	    			if (x[i] == n - 1 && x[j] == 0) res = 1;


	    			if (y[i] == 0 && y[j] == 0) res = 1;
	    			if (y[i] == n - 1 && y[j] == n - 1) res = 1;
	    			if (y[i] == 0 && y[j] == n - 1) res = 1;
	    			if (y[i] == n - 1 && y[j] == 0) res = 1;
	    		} 
	    	}

	    	FOR (i, 1, 3) {
	    		if (x[i] == 0 || x[i] == n - 1 || y[i] == 0 || y[i] == n - 1) {
	    			swap(x[i], x[3]);
	    			swap(y[i], y[3]);
	    			break;
	    		}
	    	}
	    	if (x[3] == 0) {
	    		if (y[1] <= y[3] + 1 && y[2] <= y[3] + 1) res = 1;
	    		if (y[1] == n - 1 && y[2] <= y[3] + 1) res = 1;
	    		if (y[1] == n - 1 && y[2] == n - 1) res = 1;
	    		if (y[1] <= y[3] + 1 && y[2] == n - 1) res = 1;

				if (y[1] >= y[3] - 1 && y[2] >= y[3] - 1) res = 1;
	    		if (y[1] == 0 && y[2] >= y[3] - 1) res = 1;
	    		if (y[1] == 0 && y[2] == 0) res = 1;
	    		if (y[1] >= y[3] - 1 && y[2] == 0) res = 1;

	    	}
	    	if (x[3] == n - 1) {
	    		FOR (i, 1, 3) x[i] = n - 1 - x[i];

	    		if (y[1] <= y[3] + 1 && y[2] <= y[3] + 1) res = 1;
	    		if (y[1] == n - 1 && y[2] <= y[3] + 1) res = 1;
	    		if (y[1] == n - 1 && y[2] == n - 1) res = 1;
	    		if (y[1] <= y[3] + 1 && y[2] == n - 1) res = 1;

				if (y[1] >= y[3] - 1 && y[2] >= y[3] - 1) res = 1;
	    		if (y[1] == 0 && y[2] >= y[3] - 1) res = 1;
	    		if (y[1] == 0 && y[2] == 0) res = 1;
	    		if (y[1] >= y[3] - 1 && y[2] == 0) res = 1;
	    	}

	    	if (y[3] == 0) {
	    		if (x[1] <= x[3] + 1 && x[2] <= x[3] + 1) res = 1;
	    		if (x[1] == n - 1 && x[2] <= x[3] + 1) res = 1;
	    		if (x[1] == n - 1 && x[2] == n - 1) res = 1;
	    		if (x[1] <= x[3] + 1 && x[2] == n - 1) res = 1;

				if (x[1] >= x[3] - 1 && x[2] >= x[3] - 1) res = 1;
	    		if (x[1] == 0 && x[2] >= x[3] - 1) res = 1;
	    		if (x[1] == 0 && x[2] == 0) res = 1;
	    		if (x[1] >= x[3] - 1 && x[2] == 0) res = 1;

	    	}

	    	if (y[3] == n - 1) {
	    		FOR (i, 1, 3) y[i] = n - 1 - y[i];

	    		if (x[1] <= x[3] + 1 && x[2] <= x[3] + 1) res = 1;
	    		if (x[1] == n - 1 && x[2] <= x[3] + 1) res = 1;
	    		if (x[1] == n - 1 && x[2] == n - 1) res = 1;
	    		if (x[1] <= x[3] + 1 && x[2] == n - 1) res = 1;

				if (x[1] >= x[3] - 1 && x[2] >= x[3] - 1) res = 1;
	    		if (x[1] == 0 && x[2] >= x[3] - 1) res = 1;
	    		if (x[1] == 0 && x[2] == 0) res = 1;
	    		if (x[1] >= x[3] - 1 && x[2] == 0) res = 1;
	    	}
	    }
	    if (res) {
	    	cout << "yes" << endl;
	    }
	    else{
	    	cout << "no" << endl; 
	    }
	}
	
    return 0;
}