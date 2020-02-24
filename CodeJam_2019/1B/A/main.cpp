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

int r[100005], c[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {    
	    int p, q;
	    cin >> p >> q;

	    memset(c, 0, sizeof(c));
	    memset(r, 0, sizeof(r));

	    cout << "Case #" << z << ": ";

	    FOR (i, 1, p) {
	    	int x, y;
	    	char cc;
	    	cin >> x >> y >> cc;

	    	if (cc == 'N') {
	    		r[y + 1]++;
	    	}
	    	else if (cc == 'S') {
	    		r[0]++;
	    		r[y]--;
	    	}
	    	else if (cc == 'E') {
	    		c[x + 1]++;
	    	}
	    	else {
	    		c[0]++;
	    		c[x]--;
	    	}
	    }

	    int maxC = -1, maxR = -1;
	    int indX = 0, indY = 0;

	    FOR (i, 1, q) c[i] += c[i - 1];
	    FOR (i, 1, q) r[i] += r[i - 1];

	    FOR (i, 0, q) {
	    	if (maxC < c[i]) {
	    		maxC = c[i];
	    		indX = i;
	    	}
	    	if (maxR < r[i]) {
	    		maxR = r[i];
	    		indY = i;
	    	}
	    }
        cout << indX << " " << indY << endl;

	}

 	
    return 0;
}