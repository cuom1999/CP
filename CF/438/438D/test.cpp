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


int a[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    FOR (i,1,n){
    	cin>>a[i];
    }
    FOR (z,1,m){
    	int t;
    	cin>>t;
    	if (t==1){
    		int l,r;
    		cin>>l>>r;

    		ll S=0;
    		FOR (j,l,r){
    			S+=(ll)a[j];
    		}
    		cout<<S<<endl;
    	}
    	else if (t==2){
    		int l,r,x;
    		cin>>l>>r>>x;
    		FOR (j,l,r) a[j]%=x;
    	}
    	else {
    		int k,x;
    		cin>>k>>x;
    		a[k]=x;
    	}
    }

    
	
         return 0;
}