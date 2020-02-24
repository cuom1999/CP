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
typedef pair < int, int > II;
typedef pair < II, int > III;
vector<III> v;
int ans[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
    	int n;
    	v.clear();
    	cin >> n;
    	FOR (i, 1, n) {
	    	int l, r;
	    	cin >> l >> r;
	    	v.pb(III(II(l, r), i));
	    }
	    sort(all(v));
	    int ma = v[0].first.second;
	    int res = 0;
	    int dd = 0;
	    for (int i = 1; i + 1 < v.size(); i++) {
	    	if (v[i].first.first > ma) {
	    		res = v[i].second;
	    		dd = i;
	    		break;
	    	}
	    	ma = max(ma, v[i].first.second);
	    }
	    if (!res && v[n - 1].first.first > ma) {
	   		res = v[n - 1].second;
	   		dd = n - 1;
	    }
	    FOR (i, dd, n - 1) ans[v[i].second] = 2;
	    FOR (i, 0, dd - 1) ans[v[i].second] = 1;

	    if (res) {
	    	FOR (i, 1, n) {
	    		cout << ans[i] << " ";
	    	}
	    	cout << endl;
	    }
	    else {
	    	cout << -1 << endl;
	    }
    }
    
	
    return 0;
}