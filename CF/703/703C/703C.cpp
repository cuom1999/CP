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

ld w,v,u;
ld x[10005], y[10005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n>>w>>v>>u;
    FOR (i,0,n-1) cin>>x[i]>>y[i];
    bool q=1;
    FOR (i,0,n-1){ 
    	if (x[i]*u<v*y[i]) q=0;
    }
    if (q){ 
    	cout<<fixed<<setprecision(8)<<(ld) w*1.0/u;
    	return 0;
    }
    int st=0;
    FOR (i,0,n-1){ 
    	if (y[i]<y[st]){ 
    		st=i;
    		//continue;
    	}
    	else if (y[i]==y[st]){ 
    		if (x[i]>x[st]){ 
    			st=i;
    		}
    	}
    }
    //cout<<st<<endl;
    ld res=0;
    res+=y[st]*1.0/u;
    res+=max((ld) 0.0,(ld) (x[st]-res*v)*1.0/v);

    ld Y=y[st];

    while (1){
    	if (y[(st+1)%n]<y[st]) break;
        if (x[(st+1)%n]<x[st]) break;
    	ld e=max((ld) (x[(st+1)%n])*1.0/v-res,(ld) (y[(st+1)%n]-y[st])*1.0/u);
        e=max(e,(ld) 0 );
        res+=e;
    	st=(st+1)%n;	
    	Y=y[st];
    	//cout<<res<<endl;
    }
    res+=(w-Y)*1.0/u;
    cout<<fixed<<setprecision(8)<<res<<endl;


         return 0;
}