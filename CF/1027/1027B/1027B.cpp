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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    int q;
    cin>>n>>q;
    FOR (z,1,q){ 
    	ll r,c;
    	cin>>r>>c;
    	if (n%2==0){ 
    		if ((r+c)%2==0) { 
    			cout<<(r-1)*(n/2)+(c+1)/2<<endl;
    		}
    		else cout<<(r-1)*(n/2)+(c+1)/2+n*n/2<<endl;
    	}
    	else{ 
    		if ((r+c)%2==0){ 
    			if (r%2==1){ 
    				cout<<n*((r+1)/2-1)+(c+1)/2<<endl;
    			}
    			else{ 
    				cout<<n*((r+1)/2-1)+(n+1)/2+(c+1)/2<<endl;
    			}
    		}
    		else{ 
    			if (r%2==1){ 
    				cout<<n*((r+1)/2-1)+(c+1)/2+(n*n+1)/2<<endl;
    			}
    			else{ 
    				cout<<n*((r+1)/2-1)+(n+1)/2+(c)/2+(n*n+1)/2<<endl;
    			}
    		}	
    	}
    }


         return 0;
}