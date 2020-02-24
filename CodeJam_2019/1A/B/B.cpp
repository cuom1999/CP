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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> prime = {5, 7, 11, 13, 17, 18};

vector<II> r;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    int n, m;
    cin >> t >> n >> m;

    FOR (z, 1, t) {
    	r.clear();

    	for (auto p: prime) {
    		FOR (i, 1, 18) {
    			cout << p << " ";
    		}
    		cout << endl;

    		int sum = 0;
    		FOR (i, 1, 18) {
    			int x;

    			cin >> x;
    			sum += x;
    		}
    		r.pb(II(sum % p, p));
    	}

    	FOR (i, 0, m) {
    		bool isTrue = 1;
    		for (auto j: r) {
    			if (i % j.second != j.first) {
    				isTrue = 0;
    				break;
    			}
    		}
    		if (isTrue) {
    			cout << i << endl;
    		}
    	}

    	int ver;
    	cin >> ver;
    	if (ver == -1) return 0;
    }

    
	
    return 0;
}