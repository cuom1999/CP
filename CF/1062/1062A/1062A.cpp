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


int a[105];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> a[i];
    n++;
    a[n] = 1001;
    a[0] = 0;
    int res = 1;
    int cnt = 1; 
    FOR (i, 1, n){
    	if (a[i] == a[i - 1] + 1){
    		cnt++;
    	}
    	else{
    		cnt = 1;
    	}
    	res = max(res, cnt);
    }
    cout << max(0, res - 2);
    
	
         return 0;
}