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

vector<int> v[2][10];

void build(int level, int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	FOR (i, l, mid) {
		v[0][level].pb(i);
	}
	FOR (i, mid + 1, r) {
		v[1][level].pb(i);
	}

	build(level + 1, l, mid);
	build(level + 1, mid + 1, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));
 	
 	int t;
 	cin >> t;

 	FOR (z, 1, t) {
 		int n;
 		cin >> n;
 		
 		FOR (i, 0, 1) {
 			FOR (j, 1, 9) v[i][j].clear();
 		}

 		build(1, 1, n);
 		int res = 0;

 		FOR (i, 1, 9) {
 			if (!v[0][i].size() || !v[1][i].size()) break;
 			cout << v[0][i].size() << " " << v[1][i].size() << " ";
 			for (auto j: v[0][i]) cout << j << " ";
 			for (auto j: v[1][i]) cout << j << " ";
 			
 			cout << endl;

 			int ans;
 			cin >> ans;
 			res = max(res, ans);
 		}
 		cout << "-1 " << res << endl;

 	}

	
    return 0;
}