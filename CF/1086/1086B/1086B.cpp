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

vector<int> v[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    int cnt = 0;

    FOR (i, 1, n) {
    	if (v[i].size() == 1) {
    		cnt++;
    	}
    }

    cout << fixed << setprecision(8) << s * 2.0 / cnt << endl;
	
    return 0;
}