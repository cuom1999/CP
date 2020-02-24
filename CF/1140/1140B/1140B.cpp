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

string s;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t, n;
 	cin >> t;

 	FOR (z, 1, t) {
 		cin >> n;
 		cin >> s;

 		int res = INF;

 		FOR (i, 0, n - 1) {
 			if (s[i] == '>') {
 				res = min(res, i);
 				break;
 			}
 		}

 		FORD (i, n - 1, 0) {
 			if (s[i] == '<') {
 				res = min(res, n - i - 1);
 				break;
 			}
 		}

 		cout << res << endl;
 	}
	
    return 0;
}