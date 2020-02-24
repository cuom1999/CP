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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<II> v;
vector<II> ans;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR(i, 1, 3) {
    	int x, y;
    	cin >> x >> y;
    	v.pb(II(x, y));
    }

    sort(all(v));

    int res = 0;

    
    if (v[1].second >= v[0].second && v[2].second >= v[0].second) {
    	FOR (i, v[0].first, v[1].first) {
	    	ans.pb(II(i, v[0].second));
	    	res++;
	    }
	    int u = min(v[1].second, v[2].second);
	    FOR (i, v[0].second + 1, min(v[1].second, v[2].second)) {
	    	ans.pb(II(v[1].first, i));
	    	res++;
	    }

	    if (u == v[1].second) {
	    	FOR (i, v[1].second + 1, v[2].second) {
	    		ans.pb(II(v[1].first, i));
	    	}
	    	FOR (i, v[1].first + 1, v[2].first) {
	    		ans.pb(II(i, v[2].second));
	    	}
	    }
	    else {
	    	FOR (i, v[1].first + 1, v[2].first) {
	    		ans.pb(II(i, v[2].second));
	    	}
	    	FOR (i, v[2].second + 1, v[1].second) {
	    		ans.pb(II(v[1].first, i));
	    	}
	    }
    }
    else if (v[1].second < v[0].second && v[2].second < v[0].second) {
    	FOR (i, v[0].first, v[1].first) {
	    	ans.pb(II(i, v[0].second));
	    	res++;
	    }
	    int u = max(v[1].second, v[2].second);
	    FORD (i, v[0].second - 1, max(v[1].second, v[2].second)) {
	    	ans.pb(II(v[1].first, i));
	    	res++;
	    }

	    if (u == v[1].second) {
	    	FORD (i, v[1].second - 1, v[2].second) {
	    		ans.pb(II(v[1].first, i));
	    	}
	    	FOR (i, v[1].first + 1, v[2].first) {
	    		ans.pb(II(i, v[2].second));
	    	}
	    }
	    else {
	    	FOR (i, v[1].first + 1, v[2].first) {
	    		ans.pb(II(i, v[2].second));
	    	}
	    	FORD (i, v[2].second - 1, v[1].second) {
	    		ans.pb(II(v[1].first, i));
	    	}
	    }
    } 
    else if (v[1].second >= v[0].second && v[2].second < v[0].second) {
    	FOR (i, v[0].first, v[2].first) {
    		ans.pb(II(i, v[0].second));
    	}
    	FOR (i, v[0].second + 1, v[1].second) {
    		ans.pb(II(v[1].first, i));
    	}
    	FORD (i, v[0].second - 1, v[2].second) {
    		ans.pb(II(v[2].first, i));
    	}
    }
    else {
    	FOR (i, v[0].first, v[2].first) {
    		ans.pb(II(i, v[0].second));
    	}
    	FOR (i, v[0].second + 1, v[2].second) {
    		ans.pb(II(v[2].first, i));
    	}
    	FORD (i, v[0].second - 1, v[1].second) {
    		ans.pb(II(v[1].first, i));
    	}	
    }

    cout << ans.size() << endl;
    for (auto i: ans) cout << i.first << " " << i.second << endl;

	
    return 0;
}