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

ll d[1005][20005];

struct Data {
	int w, s;
	ll v;
	Data(int __w = 0, int __s = 0, ll __v = 0): w(__w), s(__s), v(__v) {}

	bool operator < (Data &x) {
		return s + w < x.s + x.w;
	}
};

Data a[1005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;

 	FOR (i, 1, n) {
 		cin >> a[i].w >> a[i].s >> a[i].v;
  	}   

  	sort(a + 1, a + n + 1);

  	FOR (i, 1, n) {
	  	FOR (j, 0, 20000) {
	  		d[i][j] = d[i - 1][j];
	  	}

	  	FOR (j, 0, 10000) {
	  		if (j <= a[i].s) {
	  			d[i][j + a[i].w] = max(d[i][j + a[i].w], d[i - 1][j] + a[i].v); 
	  		}
	  	}
  	}

  	ll res = 0;
  	FOR (j, 0, 20000) {
  		res = max(res, d[n][j]);
  	}

  	cout << res << endl;
	
    return 0;
}