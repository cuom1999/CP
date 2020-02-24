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

int n,m;
int a[1005][1005], b[1005][1005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR (i,1,n){
    	FOR (j,1,m){
    		char c;
    		cin>>c;
    		if (c=='#') a[i][j]=1;
    	}
    }
    FOR (i,2,n-1){
    	FOR (j,2,m-1){
    		if (a[i-1][j]+a[i-1][j-1]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1]==8){
    			b[i-1][j]=b[i-1][j-1]=b[i-1][j+1]=b[i][j-1]=b[i][j+1]=b[i+1][j-1]=b[i+1][j]=b[i+1][j+1]=1;
    		}
    	}
    }
    FOR (i,1,n){
    	FOR (j,1,m) {
    		if (a[i][j]!=b[i][j]) {
    			cout<<"NO";
    			return 0;
    		}
    	}
    }
    
    cout<<"YES";
    
	
         return 0;
}