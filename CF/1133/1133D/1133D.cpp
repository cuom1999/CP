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

int a[200005], b[200005];

map<ld, int> cnt;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    FOR (i, 1, n) {
    	cin >> b[i];
    }

    int c0 = 0;

    FOR (i, 1, n) {
    	ld val;

    	if (a[i]) {
    		val = -b[i] * 1.0 / a[i];
    		cnt[val]++;
    	}
    	else {
    		if (b[i] == 0) c0++;
    	} 
    }
    int res = 0;

    for (auto i: cnt) {
    	res = max(res, i.second);
    }

    cout << res + c0 << endl;
    
	
    return 0;
}