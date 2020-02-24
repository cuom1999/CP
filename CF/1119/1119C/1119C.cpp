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

const int MAXN = 501;

bitset<MAXN> a[505], b[505];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		int x;
    		cin >> x;
    		a[i][j] = x;
    	}
    }

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		int x;
    		cin >> x;
    		b[i][j] = x;
    	}
    }

    FOR (i, 1, n) {
    	bitset<MAXN> c = a[i] ^ b[i];

    	if (c.count() % 2) {
    		cout << "No" << endl;
    		return 0;
    	}

    	if (i < n) {
    		a[i + 1] ^= c;
    	}
    	else {
    		if (c.count()) {
    			cout << "No" << endl;
    			return 0;
    		}
    	}
    }

    cout << "Yes" << endl;
    
	
    return 0;
}