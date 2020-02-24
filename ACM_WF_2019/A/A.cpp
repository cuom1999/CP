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

const int MAXN = 500005;

struct Data {
	int p, h, index;
	bool operator < (const Data& a) {
		if (p == a.p) return h < a.h;
		return p < a.p;
	}
};

Data b[MAXN], f[MAXN];
set<II> s;

vector<int> resBack; 

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    FOR (i, 1, n) {
    	cin >> b[i].p;
    	b[i].index = i;
    }

    FOR (i, 1, n) cin >> b[i].h;

    FOR (i, 1, n) {
    	cin >> f[i].p;
    	f[i].index = i;
    }

    FOR (i, 1, n) cin >> f[i].h;


    sort(f + 1, f + n + 1);
    sort(b + 1, b + n + 1);

    int j = 1;

    FOR (i, 1, n) {
    	if (!s.size()) {
			s.insert({b[j].h, b[j].index});
    		
    		while (j < n && b[j + 1].p == b[j].p) {
    			j++;
    			s.insert({b[j].h, b[j].index});
    			// cout << j << " " << b[j].h << " " << b[j].index << endl;
    		} 
    		j++;
    	}
    	// cout << f[i].h << endl;
    	// for (auto k: s) cout << k.first << " "; cout << endl;
    	auto it = s.lower_bound({f[i].h + 1, -1});
    	if (it == s.end()) {
    		cout << "impossible" << endl;
    		return 0;
    	}
    	resBack.pb(it->second);
    	s.erase(it);
    }

    
    for (auto i: resBack) cout << i << " "; cout << endl;
	FOR (i, 1, n) cout << f[i].index << " "; cout << endl;

    return 0;
}