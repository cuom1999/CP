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
int a[200005];
int dd[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    FOR (i, 1, n) {
    	cin >> a[i];
    	v.pb(II(a[i],i));
    }

    sort(all(v));

    reverse(all(v));
    ll res = 0;
    FOR (i, 0, m * k - 1) {
    	dd[v[i].second] = 1;
    	res += (ll) v[i].first;
    }

    cout << res << endl;
    int cnt = 0;
    FOR (i, 1, n) {
    	cnt += dd[i];
    	if (dd[i] && (cnt % m == 0) && i != n) cout << i << " ";
    }

	
    return 0;
}