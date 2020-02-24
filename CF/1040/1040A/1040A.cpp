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

int c[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    FOR (i,1,n){
    	cin>>c[i];
    }
    int res=0;
    FOR (i,1,n/2){
    	if (c[i]+c[n+1-i]==1){
    		cout<<-1; return 0;
    	}
    	if (c[i]==2){
    		if (c[n+1-i]==2){
    			res+=2*min(a,b);
    		}
    		else if (c[n+1-i]==1) res+=b;
    		else res+=a;
    	}
    	else if (c[i]==1){
    		if (c[n+1-i]==2){
    			res+=b;
    		}
    	}
    	else {
    		if (c[n+1-i]==2) res+=a;
    	}
    }
    if (n%2){
    	if (c[(n+1)/2]==2) res+=min(a,b);
    }
    cout<<res<<endl;
    
	
         return 0;
}