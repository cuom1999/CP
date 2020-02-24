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

int a[25], b[25];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
    	int n;
    	cin >> n;

    	a[0] = 2;
    	FOR (i, 1, (n + 1) / 2 - 1) {
    		a[i] = i * 2 + 1;
    	}

    	int c = 2;

    	FORD (i, n - 2, (n + 1) / 2) {
    		c += 2;
    		a[i] = c;
    	}

    	FOR (i, 0, n - 2) {
    		b[a[i]] = i;
    	}

    	vector<int> v;

    	FOR (i, 2, n) {
    		v.pb(b[i]);
    	}

    	FOR (i, 0, (n - 1) / 2 - 1) {
    		cout << 1 << " ";
    		for (int j = 0; j < v.size(); j++) {
    			cout << a[v[j]] << " ";
    		}
    		cout << 1 << " ";
    		cout << endl;

    		for (int j = 0; j < v.size(); j++) {
    			v[j] = (v[j] + 1) % (n - 1);
    		}
    	}

    	cout << endl;
    }



    
	
    return 0;
}