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

int n;
string s;
ll a[100005];
ll d[100005][5];
char c[5] = {'w', 'h', 'a', 'r', 'd'};	
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = '0' + s;
    FOR (i, 1, n) cin >> a[i];
    
    FOR (i, 1, n) {
    	if (s[i] == c[1]) {
    		d[i][1] = d[i - 1][1] + a[i];
    	}
    	else d[i][1] = d[i - 1][1];
    }

    FOR (j, 2, 4) {
    	FOR (i, 1, n) {
    		if (s[i] == c[j]) {
    			d[i][j] = min(d[i - 1][j - 1], d[i - 1][j] + a[i]);
    		}
    		else d[i][j] = d[i - 1][j];
    	}
    }

    cout << d[n][4] << endl;
    
    return 0;
}