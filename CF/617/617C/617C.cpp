#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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
typedef pair < ll, ll > II;

ll X[3], Y[3];
ll x[2005], y[2005];
int n;

ll dist (int i, int j) {
	return sq(X[i] - x[j]) + sq(Y[i] - y[j]);
}

bool dd[2004];

ll calc(ll r) {
	FOR (i, 1, n) {
		dd[i] = 0;
		if (dist(1, i) <= r) dd[i] = 1;
	}
	ll res = 0;
	r = 0;
	FOR (i, 1, n) {
		if (!dd[i]) {
			res = max(res, dist(2, i));
		}
		else {
			r = max(r, dist(1, i));
		}
	}

	return res + r;
}

bool cmp(int i, int j) {
	return dist(1, i) < dist(1, j);
}

bool cmp1(int i, int j) {
	return dist(2, i) < dist(2, j);
}

vector<int> v[3];
int pos[2005];

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    cin >> X[1] >> Y[1] >> X[2] >> Y[2];
    FOR (i, 1, n) {
    	cin >> x[i] >> y[i];
    	v[1].pb(i);
    	v[2].pb(i);
    }
    sort(all(v[1]), cmp);
	sort(all(v[2]), cmp1);

	//for (auto i: v[1]) cout << i << " "; cout << endl;
	//for (auto i: v[2]) cout << i << " "; cout << endl;


	ll res = dist(2, v[2].back());
    FOR (i, 0, n - 1) {
    	dd[v[1][i]] = 1;
    	while (v[2].size() && dd[v[2].back()]) v[2].pop_back();
    	//cout << i << endl;
		//for (auto j: v[2]) cout << j << " "; cout << endl;


    	if (v[2].size()) {
    		int m = v[2].back();
    		res = min(res, dist(1, v[1][i]) + dist(2, m));
    	}
    	else {
    		res = min(res, dist(1, v[1][i]));
    	}
    }
    cout << res << endl;

	
    return 0;
}