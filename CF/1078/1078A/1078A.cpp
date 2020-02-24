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
typedef pair < ld, ld > DD;

ld dist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

vector<DD> A, B;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;



    if (b) A.pb(DD(xa, (ld) (-c - a * xa) / b));
    if (a) A.pb(DD((ld) (-c - b * ya) / a, ya));
	
	if (b) B.pb(DD(xb, (ld) (-c - a * xb) / b));
    if (a) B.pb(DD((ld) (-c - b * yb) / a, yb));

    ld res = abs(xa - xb) + abs(ya - yb);
 
    for (auto i: A) {
    	for (auto j: B) {
    		res = min(res, dist(xa, ya, i.first, i.second) + dist(i.first, i.second, 
    			j.first, j.second) + dist(j.first, j.second, xb, yb));
    		//cout << i.first << " " << i.second << " " << j.first << " " << j.second << " " << res << endl;
    		//cout << dist(xa, ya, i.first, i.second) << " " << dist(i.first, i.second, 
    			//j.first, j.second) << " " << dist(j.first, j.second, xb, yb) << endl;
    	}
    }

    cout << fixed << setprecision(8) << res << endl;
	
    return 0;
}