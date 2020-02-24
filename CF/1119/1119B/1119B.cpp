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

int a[1005];
int h;

bool solve(int k) {
	vector<int> v;
	FOR (i, 1, k) {
		v.pb(a[i]);
	}

	sort(all(v));
	reverse(all(v));
	ll res = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) {
			res = res + (ll) v[i];
		}
	}

	if (res <= h) return 1;
	return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n >> h;

    FOR (i, 1, n) {
    	cin >> a[i];
    }


    int l = 1, r = n;

    while (l < r) {
    	int mid = (l + r + 1) / 2;
    	if (solve(mid)) {
    		l = mid;
    	}
    	else {
    		r = mid - 1;
    	}
    }

    cout << l << endl;
	
    return 0;
}