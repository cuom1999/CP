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

const int N = 7001;

bitset<N> a[100005], b[7005]; 
int sqf[7007];

vector<int> divisors[7007];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 1, 7000) {
        FOR (j, 1, 7000 / i) {
            divisors[i * j].pb(i);
        }
    }
    FOR (i, 1, 7000) sqf[i] = 1;

    for (int i = 2; i * i <= 7000; i++) {
        FOR (j, 1, 7000 / (i * i) ) {
            sqf[i * i * j] = 0;
        }
    }
    FOR (v, 1, 7000) {
        FOR (i, 1, 7000 / v) {
            if (sqf[i]) {
                b[v][i * v] = 1;
            }
        }
    }

    sqf[1] = 1;

    int n, q;
    cin >> n >> q;

    FOR (z, 1, q) {
    	int t;
    	cin >> t;
    	if (t == 1) {
    		int i, v;
    		cin >> i >> v;
    		a[i] = 0;
    		for (auto j: divisors[v]) a[i][j] = 1;
    	}
    	else if (t == 2) {
    		int x, y, z;
    		cin >> x >> y >> z;
    		a[x] = a[y] ^ a[z];
    	}
    	else if (t == 4) {
    		int x, v;
    		cin >> x >> v;
            int res = 0;
            bitset<N> A = a[x] & b[v];
            res = A.count() % 2;  

            cout << res;
    	}
    	else {
            int x, y, z;
            cin >> x >> y >> z;
            a[x] = a[y] & a[z];
    	}
    	/*FOR (i, 1, n) {
    		cout << a[i] << " "; 
    	}
    	cout << endl;*/
    }
    
	
    return 0;
}