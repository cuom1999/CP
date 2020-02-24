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

ll a[500005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool plus=0, minus=0;
    FOR(i,1,n) {
    	cin>>a[i];
    	if (a[i]>=0) plus=1;
    	if (a[i]<=0) minus=1;
    }
    if (n==1){
    	cout<<a[1];
    	return 0;
    }
  	ll res=0;
  
    if (plus && minus){
    	FOR (i,1,n){
    		res+=abs(a[i]);
    	}
    }
    else if (plus) {
    	ll mi=INF; mi++;
    	FOR (i,1,n){
    		res+=a[i];
    		mi=min(mi,a[i]);
    	}
    	res-=2*mi;
    }
    else{
    	ll mi=-INF; mi--;
    	FOR (i,1,n){
    		res-=a[i];
    		mi=max(mi,a[i]);
    	}
    	res+=2*mi;
    }
    cout<<res<<endl;


    
	
         return 0;
}