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


vector<int> v[100005];
int a[100005];
int pos[100005];
int d[100006];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){
    	int x;
    	cin>>x;
    	a[x]=i;
    	pos[i]=x;

    }
    FOR (i,1,n){
    	for (int j=1; j<=n/i; j++){
    		int t=i*j;
    		if (1<=a[i]-t && a[i]-t<=n && pos[a[i]-t]>i){
    			v[i].pb(pos[a[i]-t]);
    		}
    		if (1<=a[i]+t && a[i]+t<=n && pos[a[i]+t]>i){
    			v[i].pb(pos[a[i]+t]);
    		}
    	}
    }
    d[n]=0;
    FORD(i,n-1,1){
    	for (auto j:v[i]){
    		if (d[j]==0){
    			d[i]=1;
    		}
    	}
    }
    FOR (i,1,n){
    	if (d[pos[i]]) cout<<"A";
    	else cout<<"B";
    }




    
	
         return 0;
}