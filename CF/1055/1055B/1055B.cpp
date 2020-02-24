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

ll a[100005], n,m,l;
int b[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>l;
    FOR (i,1,n) cin>>a[i];

    FOR (i,1,n) {
    	if (a[i]>l) b[i]=1;
    }
    int res=0;
    FOR(i,1,n){
    	if (b[i]!=b[i-1] && b[i]) res++;
    }

    FOR (z,1,m){
    	int t;
    	cin>>t;
    	if (!t){
    		cout<<res<<endl;
    	}
    	else{
    		ll p,d;
    		cin>>p>>d;
    		if (a[p]>l) continue;
    		a[p]+=d;
    		if (a[p]>l) {
    			b[p]=1;
    			if (b[p-1]==0 && b[p+1]==0) res++;
    			if (b[p-1] && b[p+1]) res--;
    		}
    	}
    }

    
	
         return 0;
}