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

ll d[3005][3005];
int c[3005][3005];

const ll K = 1e9 + 7;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    int n;
    cin >> n;

    FOR (i, 1, n) {
    	int l, r;
    	cin >> l >> r;
    	c[l][r] = 1;
    }
    FORD (i, H, 1) {
    	FORD (j, W, 1) {
    		if (c[i][j]) continue;
    		if (i == H && j == W) {
    			d[i][j] = 1;
    			continue;
    		}

    		d[i][j] = (d[i + 1][j] + d[i][j + 1]) % K;
    	}
    }
    
    cout << d[1][1] << endl;
	
    return 0;
}