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

char c[505][505];

vector<II> v;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	FOR (z, 1, t) {
 		int n, m;

 		cin >> n >> m;
 		v.clear();

 		FOR (i, 1, n) {
 			FOR (j, 1, m) {
 				cin >> c[i][j];
 				if (c[i][j] == '1') {
 					v.pb(II(i, j));
 				}
 			}
 		}

 		int res = INF;

 		FOR (i, 1, n) {
 			FOR (j, 1, m) {
 				v.pb(II(i, j));

 				int val = -1;
 				FOR (i1, 1, n) {
 					FOR (j1, 1, m) {
 						int minDist = INF;
 						for (auto u: v) minDist = min(minDist, abs(i1 - u.first) + abs(j1 - u.second));
 						val = max(val, minDist);
 					}
 				}

 				res = min(res, val);
 				v.pop_back();
 			}
 		}

 		cout << "Case #" << z << ": " << res << endl;

 	}   
	
    return 0;
}