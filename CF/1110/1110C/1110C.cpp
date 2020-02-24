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

ll res[(1 << 25)];
vector<ll> v = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main()
{IN; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 2, 25) {
    	ll u = (1 << i) - 1;
    	
    	res[u] = v[i - 2];
    }

    int q;
    cin >> q;
    FOR (z, 1, q) {
    	int x;
    	cin >> x;
    	int u = flog2(x) + 1;
    	if (res[x]) {
    		cout << res[x] << endl;
    	}
    	else {
    		cout << (1 << u) - 1 << endl;
    	}
    }

	
    return 0;
}