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

int l[5005][5005], r[5005][5005];
int a[5005];
int b[5005];
int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int N = 0;
    FOR (i, 1, n) {
    	cin >> a[i];
    	if (a[i - 1] != a[i]) {
    		N++;
    		b[N] = a[i];
    	}
    }

    FOR (len, 1, N - 1) {
    	FOR (i, 1, N - len) {
    		int j = i + len;
    		if (b[i] != b[j]) {
    			l[i][j] = min(l[i + 1][j], r[i + 1][j]) + 1;
    			r[i][j] = min(l[i][j - 1], r[i][j - 1]) + 1;
    		}
    		else {
    			l[i][j] = r[i][j] = min(l[i][j - 1], r[i + 1][j]);
    		}
    		//cout << i << " " << j << " " << l[i][j] << " " << r[i][j] << endl;
    	}
    }

    cout << min(l[1][N], r[1][N]) << endl;
 

    return 0;
}